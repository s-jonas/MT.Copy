#include "filehandler.h"

FileHandler::FileHandler(const QString filename)
{
    this->_filename = filename;
}

void FileHandler::openFile()
{
    if(this->_filename==NULL)
    {
        return;
    }

    this->file = new QFile(this->_filename);
    this->file->open(QIODevice::ReadOnly | QIODevice::Text);
    while(!file->isReadable())
    {
        QTime dieTime = QTime::currentTime().addSecs(2);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        this->file->open(QIODevice::ReadOnly | QIODevice::Text);
    }
}

void FileHandler::closeFile()
{
    if(this->file==NULL)
    {
        return;
    }
    this->file->close();
    delete(this->file);
}

QString FileHandler::readFile()
{
    if(this->file==NULL)
    {
        return NULL;
    }
    openFile();
    QString val(this->file->readAll());
    closeFile();
    return val;
}

