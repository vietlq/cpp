#include <QFileDialog>
#include <QIODevice>
#include <QBuffer>
#include <QXmlQuery>
#include <QXmlSerializer>
#include <QVariant>
#include <QTextStream>

#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    connect(ui->butXMLFile, SIGNAL(clicked()), this, SLOT(getXMLFile()));
    connect(ui->butXQueryFile, SIGNAL(clicked()), this, SLOT(getXQueryFile()));
    connect(ui->butProcess, SIGNAL(clicked()), this, SLOT(processXML()));
    
    connect(ui->actionOpenXML, SIGNAL(triggered()), this, SLOT(getXMLFile()));
    connect(ui->actionOpenXQuery, SIGNAL(triggered()), this, SLOT(getXQueryFile()));
    
    ui->progressBar->setValue(0);
    
    this->setWindowTitle("XQuery Example");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::getXMLFile()
{
    xmlFileName = QFileDialog::getOpenFileName(this, "Open XML file", "", tr("XML files (*.xml *.xslt)"));
    ui->lineXMLFile->setText(xmlFileName);
}

void MainWindow::getXQueryFile()
{
    xqueryFileName = QFileDialog::getOpenFileName(this, "Open XQuery file", "", tr("XQuery files (*.xq *.xquery)"));
    ui->lineXQueryFile->setText(xqueryFileName);
}

void MainWindow::processXML()
{
    ui->progressBar->setValue(0);
    ui->textOutput->setText("Processing...");
    
    QString outText;
    QString xqueryTxt;
    QXmlQuery query;
    bool isOK;
    
    xmlFile.setFileName(xmlFileName);
    xmlFile.open(QIODevice::ReadOnly);
    
    xqueryFile.setFileName(xqueryFileName);
    xqueryFile.open(QIODevice::ReadOnly);
    
    QTextStream textStream(&xqueryFile);
    xqueryTxt = textStream.readAll();
    textStream.flush();
    
    // QXmlQuery::bindVariable() does not work!!!
    //query.bindVariable("myCookBook", QVariant(xmlFileName));
    //query.bindVariable("myCookBook", &xmlFile);
    xqueryTxt.replace("$myCookBook", xmlFileName);
    query.setQuery(xqueryTxt);
    
    isOK = query.evaluateTo(&outText);
    
    xqueryFile.close();
    xmlFile.close();
    
    if(isOK) {
        ui->textOutput->setPlainText(outText);
        ui->progressBar->setValue(100);
    } else {
        ui->textOutput->setPlainText("An error occurred!");
    }
}
