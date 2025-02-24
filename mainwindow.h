#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "Serial.h"
#include "QTimer"
#include "Thread.h"
#include "QTextCodec"
#include "QtCharts/QChartView"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow;

/* 串口接收线程类 */
class Serial_Rec_Thread :public Thread
{
Q_OBJECT
public:
    explicit Serial_Rec_Thread(Serial *serial)
    {
        m_serial = serial;
    }
signals:
    void data_Received(QByteArray buffer); /* 数据接收信号 */
protected:
    void run() override {
        QByteArray buffer;
        QElapsedTimer timer;
        timer.start();
        constexpr qint64 MAX_READ_SIZE = 1024;

        while (!this->isInterruptionRequested()) { // 使用标准停止标志
            QMutexLocker locker(&m_serial->portMutex);

            if (!m_serial->Port.isOpen()) {
                qDebug() << "Port closed, sleeping...";
                QThread::msleep(100);
                continue;
            }

            // 非阻塞读取检查
            bool hasData = m_serial->Port.waitForReadyRead(50);
            qint64 bytesAvailable = m_serial->Port.bytesAvailable();
            bytesAvailable = bytesAvailable > 0 ? bytesAvailable : 0;

            if (hasData && bytesAvailable > 0) {
                qint64 bytesToRead = qMin(bytesAvailable, MAX_READ_SIZE);
                QByteArray data = m_serial->Port.read(10);

                if (!data.isEmpty()) {
                    //buffer += data;
                    timer.restart();
                    qDebug() << "Received:" << data.size() << "bytes | Buffer:" << buffer.size();
                }
            }

            // 定时或定量发送数据
            if (timer.hasExpired(100) || buffer.size() >= 1024) {
                if (!buffer.isEmpty()) {
                    emit data_Received(buffer);
                    buffer.clear();
                }
            }
        }
    }

private:
    Serial *m_serial;

};
/* 串口开关管理线程 */
class Serial_OC_Manange_Thread:public  Thread
{
Q_OBJECT

signals:
    void Update_Connect_btn();

private:
    Serial *m_serial;
public:
    Serial_OC_Manange_Thread(Serial* serial)
    {
        m_serial = serial;
    };
    void run() override
    {
        if(!m_serial->Serial_State) {
            /* 打开串口*/
            if (m_serial->Port.open(QIODevice::ReadWrite)) {

                qDebug() << "串口打开成功";
                /* 设置串口状态为开启 */
                m_serial->Serial_State = true;
                /* 发送更新UI */
                emit Update_Connect_btn();
                /* 更新按钮 */
                //ui->Connect_Btn->setText("Disconnect");


            } else {
                qDebug() << "串口打开失败";
            }
        }
        else
        {
            /* 设置串口状态为关闭 */
            m_serial->Serial_State = false;
            /* 发送更新UI */
            emit Update_Connect_btn();
            /* 关闭串口 */
            m_serial->Port.close();
            qDebug()<<"串口关闭";

            /* 更新按钮 */
            //ui->Connect_Btn->setText("Connect");

        }
    }


};

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    /* 这是MainWindow这个类的构造函数，没有指定父类 */
    MainWindow(QWidget *parent = nullptr);
    /* 这是MainWindow这个类的析构函数，没有指定父类 */
    ~MainWindow();
    void Set_Up();
private slots:
    //////////////* 串口设置槽合集 *///////////////
    void Serial_Selector_Combo();
    void Select_Parity();
    ////////////////////////////////////////////
    void Serial_Connect();
    void Serial_Read();
    void Rec_Plant_Clear();
    void Send_Msg();
    void Update_Serial_Connect_Btn();
    void Switch_Widget_Screen();


private:
    Ui::MainWindow *ui;
    Serial *Serial;
    Serial_Rec_Thread *Serial_Rec_Thread;
    Serial_OC_Manange_Thread *Serial_OC_Manange_Thread;
};


#endif // MAINWINDOW_H
