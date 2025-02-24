//
// Created by Yuang Ryan on 2025/2/20.
//

#ifndef SIMPLE_SERIALL_SERIAL_H
#define SIMPLE_SERIALL_SERIAL_H
#include "QObject"
#include "QDebug"
#include "QtSerialPort/QSerialPortInfo"
#include "QtSerialPort/QSerialPort"
#include "QMutex"

class Serial : public QObject
{
    Q_OBJECT
public:
    /* 构造函数 */
    explicit Serial(QObject* parent = nullptr);

    QList<QSerialPortInfo> Serial_Info;
    QSerialPort Port;
    mutable QMutex portMutex;

    /* 串口状态 */
    bool Serial_State;

private:


};


#endif //SIMPLE_SERIALL_SERIAL_H
