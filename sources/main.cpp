#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QLabel>
#include <QDir>
#include <QString>
#include <filehandler.h>

int main(int argc, char *argv[])
{
    QString mainDir(QDir::tempPath()+"/copytrader");
    QDir dir(mainDir);
    if(!dir.exists(mainDir))
    {
        dir.mkdir(mainDir);
    }

    QApplication app(argc, argv);
    //QString fileName(QDir::tempPath()+"/"+"myea.dat");
    //FileHandler handler(fileName);

    //QLabel label2(handler.readFile());
    //QLabel label2(fileName);
    //label2.show();


    MainWindow* window = new MainWindow;
    window->show();

    return app.exec();
}
