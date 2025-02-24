//
// Created by Yuang Ryan on 2025/2/20.
//
#include "Serial.h"

Serial::Serial(QObject* parent)
{
    //获取可用的端口
    this->Serial_Info = QSerialPortInfo::availablePorts();
    qDebug()<<this->Serial_Info.count();


}
