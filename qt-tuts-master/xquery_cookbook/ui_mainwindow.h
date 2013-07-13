/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jun 5 15:28:15 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionOpenXML;
    QAction *actionOpenXQuery;
    QWidget *centralWidget;
    QPushButton *butXMLFile;
    QLineEdit *lineXMLFile;
    QLineEdit *lineXQueryFile;
    QPushButton *butXQueryFile;
    QLabel *labelTitle;
    QTextBrowser *textOutput;
    QPushButton *butProcess;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(600, 400));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOpenXML = new QAction(MainWindow);
        actionOpenXML->setObjectName(QString::fromUtf8("actionOpenXML"));
        actionOpenXQuery = new QAction(MainWindow);
        actionOpenXQuery->setObjectName(QString::fromUtf8("actionOpenXQuery"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        butXMLFile = new QPushButton(centralWidget);
        butXMLFile->setObjectName(QString::fromUtf8("butXMLFile"));
        butXMLFile->setGeometry(QRect(460, 40, 120, 30));
        lineXMLFile = new QLineEdit(centralWidget);
        lineXMLFile->setObjectName(QString::fromUtf8("lineXMLFile"));
        lineXMLFile->setGeometry(QRect(20, 40, 420, 30));
        lineXMLFile->setReadOnly(true);
        lineXQueryFile = new QLineEdit(centralWidget);
        lineXQueryFile->setObjectName(QString::fromUtf8("lineXQueryFile"));
        lineXQueryFile->setGeometry(QRect(20, 80, 420, 30));
        lineXQueryFile->setReadOnly(true);
        butXQueryFile = new QPushButton(centralWidget);
        butXQueryFile->setObjectName(QString::fromUtf8("butXQueryFile"));
        butXQueryFile->setGeometry(QRect(460, 80, 120, 30));
        labelTitle = new QLabel(centralWidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(100, 0, 400, 30));
        labelTitle->setAlignment(Qt::AlignCenter);
        textOutput = new QTextBrowser(centralWidget);
        textOutput->setObjectName(QString::fromUtf8("textOutput"));
        textOutput->setGeometry(QRect(20, 160, 560, 170));
        butProcess = new QPushButton(centralWidget);
        butProcess->setObjectName(QString::fromUtf8("butProcess"));
        butProcess->setGeometry(QRect(460, 120, 120, 30));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 120, 420, 30));
        progressBar->setValue(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpenXML);
        menuFile->addAction(actionOpenXQuery);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionOpenXML->setText(QApplication::translate("MainWindow", "&Open XML", 0, QApplication::UnicodeUTF8));
        actionOpenXML->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionOpenXQuery->setText(QApplication::translate("MainWindow", "Open XQuery", 0, QApplication::UnicodeUTF8));
        butXMLFile->setText(QApplication::translate("MainWindow", "XML File", 0, QApplication::UnicodeUTF8));
        butXQueryFile->setText(QApplication::translate("MainWindow", "XQuery File", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Pick up a XQuery file to process a XML file</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        butProcess->setText(QApplication::translate("MainWindow", "Process XML", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
