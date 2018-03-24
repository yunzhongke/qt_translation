#include <QtWidgets/QApplication>
#include <QtCore/QTranslator>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("lang_zh.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}


