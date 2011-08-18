#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <addaccountwidget.h>

MainWindow::MainWindow(QMainWindow *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
    watcher = new QFileSystemWatcher(this);
    watcher->addPath(QDir::tempPath()+"/"+"copytrader");

    fileInfo = new QFileInfo();
    connect(watcher, SIGNAL(directoryChanged(const QString &)), this, SLOT(onFileChanged(const QString &)));
    initMainWindow();
    initMenu();


}

MainWindow::~MainWindow()
{
    delete(editor);
}
void MainWindow::initMenu()
{
    QMenu *fileMenu = new QMenu(tr("&Konten"),this);
    menuBar()->addMenu(fileMenu);
    fileMenu->addAction(QIcon(""), tr("&Konto hinzufügen"), this, SLOT(addAccount()), QKeySequence(tr("Ctrl+N","Datei|Konto hinzufügen")) );
}

void MainWindow::initMainWindow()
{
    this->editor = new QTextEdit;
    this->resize(320,200);
    this->setCentralWidget(editor);
    this->setWindowTitle("CopyTrader - Demo");
}

void MainWindow::onFileChanged(const QString& file)
{
      //fileInfo->setFile(file);
    QDir dir(file);
    QStringList filters;
    filters << "*.cpp" << "*.cxx" << "*.cc";
    dir.setNameFilters(filters);

      //update();
      //repaint();

      QCoreApplication::processEvents();
      if(dir.entryList().size()>0)
      {
          QMessageBox::information(this, "info", QString::number(dir.entryList().size()));
      }



}

void MainWindow::addAccount()
{
    //editor->hide();
    AddAccountWidget* w = new AddAccountWidget(this);
    setCentralWidget(w);
}
