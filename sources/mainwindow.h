#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    private:
        QFileSystemWatcher* watcher;
        QFileInfo* fileInfo;
        void initMenu();
        void initMainWindow();
    public:
        MainWindow(QMainWindow *parent = 0, Qt::WindowFlags flags = 0);
        ~MainWindow();
        QTextEdit* editor;
    public slots:
        void addAccount();
        void onFileChanged(const QString& file);
};

#endif // MAINWINDOW_H
