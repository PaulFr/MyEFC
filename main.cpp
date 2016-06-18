#include "mainwindow.h"
#include <QApplication>
#include "epsifilecompressor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EpsiFileCompressor efc(1);
    MainWindow w(efc);
    w.show();

    return a.exec();
}
