#include "mainwindow.h"
#include "Serial.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    qputenv("QT_LOGGING_RULES", "qt.serialport.debug=true");
    w.show();
    return a.exec();
}
