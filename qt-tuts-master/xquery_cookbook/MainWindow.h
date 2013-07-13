#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void getXMLFile();
    void getXQueryFile();
    void processXML();
    
protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::MainWindow *ui;
    
    QFile xmlFile;
    QString xmlFileName;
    
    QFile xqueryFile;
    QString xqueryFileName;
};

#endif // MAINWINDOW_H
