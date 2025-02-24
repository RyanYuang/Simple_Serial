#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include "QLineSeries"
#include "QValueAxis"
void MainWindow::Set_Up()
{
    /* 设置*/
    ui->plainTextEdit->setReadOnly(true);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , Serial(new::Serial)
    , Serial_Rec_Thread(new::Serial_Rec_Thread(Serial))
    , Serial_OC_Manange_Thread(new::Serial_OC_Manange_Thread(Serial))
{

    QLineSeries *m_Line_Series;
    QValueAxis *axisX;
    QValueAxis *axisY;

    ui->setupUi(this);
    // 创建对象（使用new动态分配）

    m_Line_Series = new QLineSeries();
    axisX = new QValueAxis();
    axisY = new QValueAxis();


    // 生成数据点
    QVector<QPointF> points;
    for(int i = 0; i < 100; i++) {
        points.append(QPointF(i, i));
    }
    m_Line_Series->replace(points);

    // 添加系列到图表
    //ui->chart->addSeries(m_Line_Series);

    // 设置坐标轴
    m_Line_Series->attachAxis(axisX);
    m_Line_Series->attachAxis(axisY);
    //ui->chart->addAxis(axisX, Qt::AlignBottom);
    //ui->chart->addAxis(axisY, Qt::AlignLeft);
    // 设置坐标范围
    axisX->setRange(0, 100);
    axisY->setRange(0, 100);
    /* 取消图示 */
    //chart->legend()->hide();

    // 将视图添加到布局



    this->Set_Up();

    /*  第一次获取串口列表 */

    for(const auto &Info :Serial->Serial_Info)
    {
        ui->SerialNumberCombo->addItem(Info.portName());
    }




    //////////////* 串口设置信号合集 *///////////////
    /* 串口选择信号槽 */
    connect(ui->SerialNumberCombo, SIGNAL(activated(int)), this, SLOT(Serial_Selector_Combo()));
    /* 波特率选择信号槽 */
    //connect(ui->BaudRateCombo, SIGNAL(activated(int)),this, SLOT(Serial_Selector_Combo()));
    /////////////////////////////////////////////


    /* 串口连接信号槽 */
    connect(ui->Connect_Btn, SIGNAL(clicked(bool)), this, SLOT(Serial_Connect()));
    connect(Serial_OC_Manange_Thread,&Serial_OC_Manange_Thread::Update_Connect_btn, this, &MainWindow::Update_Serial_Connect_Btn);
    /* 串口读取信号槽 */
    //connect(Serial_Rec_Thread,&Serial_Rec_Thread::data_Received,this,&MainWindow::Serial_Read);
    /* 接收栏清除信号槽 */
    connect(ui->Clear_Btn, SIGNAL(clicked(bool)), this, SLOT(Rec_Plant_Clear()));
    /* 发送按钮信号槽 */
    connect(ui->Send_Btn, SIGNAL(clicked(bool)), this, SLOT(Send_Msg()));
    connect(&Serial->Port,&QSerialPort::readyRead,this, &MainWindow::Serial_Read);
    qDebug()<<ui->SerialNumberCombo->currentText();

    //connect(ui->Side_Bar_Serial_Setting_Btn, SIGNAL(clicked(bool)), this, SLOT(Switch_Widget_Screen()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

//////////////* 串口设置槽函数实现合集 *///////////////
/* 串口选择下拉框 */
void MainWindow::Serial_Selector_Combo() {
    for(const auto &Info :Serial->Serial_Info)
    {
        ui->SerialNumberCombo->addItem(Info.portName());
    }
    qDebug()<<ui->SerialNumberCombo->currentText();
}

/* 数据位选择下拉框 */
void MainWindow::Select_Parity()
{
    const int index = ui->ParityCombo->currentIndex();
    QSerialPort::Parity Parity;
    switch(index)
    {
        case 0:
            Parity = QSerialPort::Parity::NoParity;
            break;
        case 1:
            Parity = QSerialPort::Parity::EvenParity;
            break;
        case 2:
            Parity = QSerialPort::Parity::OddParity;
            break;
        case 3:
            Parity = QSerialPort::Parity::SpaceParity;
            break;
        case 4:
            Parity = QSerialPort::Parity::MarkParity;
            break;
    }
    Serial->Port.setParity(QSerialPort::Parity(index));
}





////////////////////////////////////////////////////
void MainWindow::Serial_Connect() {
        //qDebug() << "Connecting to device!";

        /* 设置串口参数 */
        /* 设置波特率 */
        Serial->Port.setBaudRate(ui->BaudRateCombo->currentText().toInt());
        /* 设置数据位 */
        Serial->Port.setDataBits(QSerialPort::DataBits(ui->DataBitCombo->currentIndex() + 5));
        /* 设置极性 */
        MainWindow::Select_Parity();
        /* 设置停止位 */
        Serial->Port.setStopBits(QSerialPort::StopBits(ui->StopBitCombo->currentIndex()));
        /* 设置端口 */
        Serial->Port.setPortName(ui->SerialNumberCombo->currentText());
        qDebug() << "PortName:" << Serial->Port.portName();
        qDebug() << "Baud Rate:" << Serial->Port.baudRate();
        qDebug() << "Data Bit:" << Serial->Port.dataBits();
        qDebug() << "Parity:" << Serial->Port.parity();
        qDebug() << "StopBits:" << Serial->Port.stopBits();
        Serial_OC_Manange_Thread->start();
}
/*  串口读取函数的实现 */
void MainWindow::Serial_Read()
{
    /* 读取所有数据*/
    QByteArray data = Serial->Port.readAll();
    qDebug()<<data;
    ui->plainTextEdit->appendPlainText(data);
}
/* 接收框清除函数 */
void MainWindow::Rec_Plant_Clear()
{
    ui->plainTextEdit->clear();
}

/*  发送按钮实现函数 */
void MainWindow::Send_Msg()
{
    /* TextCharFormat对象 */
    QTextCharFormat fmt;
    /* 字符串格式转换 */
    QString str =ui->Send_Text->toPlainText();
    QByteArray sendData = str.toUtf8();
    /* 发送到串口*/
    bool state = Serial->Port.write(sendData);
    qDebug()<<state<<"-"<<Serial->Port.waitForBytesWritten(1000);
    fmt.setForeground(QColor(Qt::green));
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
    ui->plainTextEdit->appendPlainText(str);
    fmt.setForeground(QColor(Qt::white));
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
    /* 清空输出框 */
    ui->Send_Text->clear();
}

/* 连接串口按钮更新 */
void MainWindow::Update_Serial_Connect_Btn()
{
    if(Serial->Serial_State)
    {
        ui->Connect_Btn->setText("Disconnect");
    }
    else
    {
        ui->Connect_Btn->setText("Connect");
    }
}

/* 页面切换函数 */
void MainWindow::Switch_Widget_Screen()
{
    qDebug()<<"Switch";
    this->ui->centralwidget->close();
    //this->ui->sec_centralwidge->show();
}

