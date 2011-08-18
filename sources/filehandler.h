#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QApplication>
class FileHandler
{
    public:
        FileHandler(const QString filename);
        QString readFile();
    private:
        void openFile();
        void closeFile();
        QString _filename;
        QFile *file;
};

#endif // FILEHANDLER_H
