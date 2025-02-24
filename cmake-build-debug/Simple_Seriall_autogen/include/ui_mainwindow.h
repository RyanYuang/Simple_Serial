/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QLineSeries"
#include "QValueAxis"
#include "QChartView"
#include "QSplitter"
QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *SerialNumberCombo;
    QPushButton *Connect_Btn;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *BaudRateCombo;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QComboBox *DataBitCombo;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QComboBox *ParityCombo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *FlowControlCombo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *StopBitCombo;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *Send_Text;
    QPushButton *Send_Btn;
    QPushButton *Clear_Btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    ////////////////* 折线图控件声明 *////////////////
    QChartView *cview;
    QChart *chart;

    //////////////////////////////////////////////////

    /////////////////* 侧边栏控件声明 *//////////////////
    QWidget *Side_Bar_Widget;
    QWidget *sec_centralwidge;
    QPushButton *Side_Bar_Serial_Setting_Btn;
    QPushButton *Side_Bar_Widget_Btn;
    QVBoxLayout *Side_Bar_Serial_Vertical_Layout;

    //////////////////////////////////////////////////

    /////////////////* 自定视图区域声明 *//////////////////
    QWidget *modify_view_Widget;
    ////////////////////////////////////////////////////

    /////////////////* 拆分器声明 *//////////////////
    QSplitter *splitter;
    QSplitter *sendARecSplitter;
    ////////////////////////////////////////////////////


    void setupUi(QMainWindow *MainWindow)
    {
        /*region - 基本控件设置 */
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        /* 设置窗体大小 */
        MainWindow->resize(1083, 723);
        sec_centralwidge = new QWidget(MainWindow);
        sec_centralwidge->setStyleSheet("background-color:red;");
        sec_centralwidge->hide();
        /* 基本控件*/
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        /*基本控件的网格排列 */
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        /* endregion */

        /*region - 侧边栏控件定义*/
        /////////////////* 侧边栏控件定义 *//////////////////
        Side_Bar_Widget = new QWidget(centralwidget);
        Side_Bar_Widget->setObjectName("SideBarWidget");
        Side_Bar_Widget->setMinimumSize(QSize(100,0));

        /* 侧边栏垂直控件 */

        Side_Bar_Serial_Vertical_Layout = new QVBoxLayout(Side_Bar_Widget);
        Side_Bar_Serial_Vertical_Layout->setObjectName("Side_Bar_Serial_Vertical_Layout");

        // 串口设置按钮
        Side_Bar_Serial_Setting_Btn = new QPushButton(Side_Bar_Widget);
        Side_Bar_Serial_Setting_Btn->setText("Serial");
        Side_Bar_Serial_Vertical_Layout->addWidget(Side_Bar_Serial_Setting_Btn);

        // 控件设置按钮
        Side_Bar_Widget_Btn = new QPushButton(Side_Bar_Widget);
        Side_Bar_Widget_Btn->setText("Widget");
        Side_Bar_Serial_Vertical_Layout->addWidget(Side_Bar_Widget_Btn);

        /* 添加布局 */
        gridLayout->addWidget(Side_Bar_Widget,0,0,1,1,Qt::AlignTop);

        /* */

        //////////////////////////////////////////////////
        /* endregion */

        /* region - 左边栏的控件定义*/
        ////////////////* 左边栏的控件定义 *////////////////
        /* 左边栏的盒子 */
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        /* 左边栏盒子的排列 */
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        /* 垂直排列 */
        verticalFrame = new QFrame(groupBox);
        verticalFrame->setObjectName("verticalFrame");
        verticalLayout = new QVBoxLayout(verticalFrame);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(verticalFrame);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 20));
        verticalLayout->addWidget(label);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        SerialNumberCombo = new QComboBox(verticalFrame);
        SerialNumberCombo->setObjectName("SerialNumberCombo");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SerialNumberCombo->sizePolicy().hasHeightForWidth());
        SerialNumberCombo->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(SerialNumberCombo);

        Connect_Btn = new QPushButton(verticalFrame);
        Connect_Btn->setObjectName("Connect_Btn");

        horizontalLayout_6->addWidget(Connect_Btn);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(verticalFrame);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        BaudRateCombo = new QComboBox(verticalFrame);
        BaudRateCombo->addItem(QString());
        BaudRateCombo->addItem(QString());
        BaudRateCombo->setObjectName("BaudRateCombo");

        horizontalLayout->addWidget(BaudRateCombo);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(verticalFrame);
        label_6->setObjectName("label_6");

        horizontalLayout_7->addWidget(label_6);

        DataBitCombo = new QComboBox(verticalFrame);
        DataBitCombo->addItem(QString());
        DataBitCombo->addItem(QString());
        DataBitCombo->addItem(QString());
        DataBitCombo->addItem(QString());
        DataBitCombo->setObjectName("DataBitCombo");

        horizontalLayout_7->addWidget(DataBitCombo);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_7 = new QLabel(verticalFrame);
        label_7->setObjectName("label_7");

        horizontalLayout_8->addWidget(label_7);

        ParityCombo = new QComboBox(verticalFrame);
        ParityCombo->addItem(QString());
        ParityCombo->addItem(QString());
        ParityCombo->addItem(QString());
        ParityCombo->addItem(QString());
        ParityCombo->addItem(QString());
        ParityCombo->setObjectName("ParityCombo");

        horizontalLayout_8->addWidget(ParityCombo);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(verticalFrame);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        FlowControlCombo = new QComboBox(verticalFrame);
        FlowControlCombo->addItem(QString());
        FlowControlCombo->addItem(QString());
        FlowControlCombo->addItem(QString());
        FlowControlCombo->setObjectName("FlowControlCombo");

        horizontalLayout_4->addWidget(FlowControlCombo);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(verticalFrame);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        StopBitCombo = new QComboBox(verticalFrame);
        StopBitCombo->addItem(QString());
        StopBitCombo->addItem(QString());
        StopBitCombo->addItem(QString());
        StopBitCombo->setObjectName("StopBitCombo");

        horizontalLayout_2->addWidget(StopBitCombo);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_3->addWidget(verticalFrame, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        /* endregion */

        /*region - 右边栏的控件定义*/
        ////////////////* 右边栏的控件定义 *////////////////
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(plainTextEdit, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        Send_Text = new QTextEdit(groupBox_2);
        Send_Text->setObjectName("Send_Text");

        horizontalLayout_5->addWidget(Send_Text);

        Send_Btn = new QPushButton(groupBox_2);
        Send_Btn->setObjectName("Send_Btn");

        horizontalLayout_5->addWidget(Send_Btn);


        gridLayout_2->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        Clear_Btn = new QPushButton(groupBox_2);
        Clear_Btn->setObjectName("Clear_Btn");

        gridLayout_2->addWidget(Clear_Btn, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 2, 1, 1);


        //////////////////////////////////////////////////
        /* endregion */

        /* region - mainmenubar */
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1083, 42));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        /* endregion*/

        /*region - 自定视图区域*/


        modify_view_Widget = new QWidget(groupBox_2);
        modify_view_Widget->setObjectName("modify_view_Widget");
        modify_view_Widget->setMinimumWidth(1);
        modify_view_Widget->setMinimumHeight(500);
        modify_view_Widget->setStyleSheet("background-color:white;");
        /* 设置布局 */
        gridLayout_2->addWidget(modify_view_Widget,0,0,1,1);

//        // 定义折线图
//        chart = new QChart();
//        cview = new QChartView(groupBox_2);
//        // 设置图表
//        cview->setChart(chart);
//        gridLayout_2->addWidget(cview, 0, 0, 1, 1);
        /* endregion*/

        /* region - 信息收发以及设置拆分器 */
        splitter = new QSplitter(centralwidget);
        splitter->setGeometry(QRect(120,80,461,332));
        splitter->addWidget(groupBox);
        splitter->addWidget(groupBox_2);
        gridLayout->addWidget(splitter, 0, 1, 1, 1);
        /* endregion - 拆分器 */

        /* region - 接收以及发送框拆分器 */
//        sendARecSplitter = new QSplitter(groupBox_2);
//        sendARecSplitter->setGeometry(QRect(120,80,461,332));
//        sendARecSplitter->addWidget(modify_view_Widget);
//        sendARecSplitter->addWidget(plainTextEdit);
//
//
//        sendARecSplitter->addWidget(Send_Text);
//
//        sendARecSplitter->addWidget(Clear_Btn);
//        sendARecSplitter->addWidget(Send_Btn);
//
//        sendARecSplitter->setOrientation(Qt::Vertical);

//        gridLayout->addWidget(splitter, 0, 1, 1, 1);
        /* endregion */
        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    /* 不重启翻译的函数 */
    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Serial Configuration", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Serial Number:", nullptr));
        Connect_Btn->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Baud rate", nullptr));
        BaudRateCombo->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        BaudRateCombo->setItemText(1, QCoreApplication::translate("MainWindow", "115200", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Data bit", nullptr));
        DataBitCombo->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        DataBitCombo->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        DataBitCombo->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        DataBitCombo->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "Parity", nullptr));
        ParityCombo->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        ParityCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Even", nullptr));
        ParityCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Odd", nullptr));
        ParityCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Space", nullptr));
        ParityCombo->setItemText(4, QCoreApplication::translate("MainWindow", "Mark", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Flow control", nullptr));
        FlowControlCombo->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        FlowControlCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Hard", nullptr));
        FlowControlCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Soft", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Stop bits", nullptr));
        StopBitCombo->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        StopBitCombo->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        StopBitCombo->setItemText(2, QCoreApplication::translate("MainWindow", "1.5", nullptr));

        groupBox_2->setTitle(QString());
        Send_Text->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                                                                     "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                                                                     "p, li { white-space: pre-wrap; }\n"
                                                                     "</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
                                                                     "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.AppleSystemUIFont';\"><br /></p></body></html>", nullptr));
        Send_Btn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        Clear_Btn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi


};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
