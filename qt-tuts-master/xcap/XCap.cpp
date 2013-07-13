#include <stdlib.h>
#include <time.h>

#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>
#include <QDesktopServices>
#include <QIcon>
#include <QPainter>
#include <QPrinter>

#include "XCap.h"

XCap::XCap(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("XCap Screen Capture");
    this->setWindowIcon( QIcon(":/resources/heart.png") );
    
    this->initShortcuts();
    
    this->initActions();
    this->initSystemTray();
    
    // set the default output format; actions & menu must be set up a priori
    this->setOutType("png");
}

XCap::~XCap()
{
    shortQuit->setDisabled();
    delete shortQuit;
    shortQuit = 0;
    
    shortCurWin->setDisabled();
    delete shortCurWin;
    shortCurWin = 0;
    
    shortDesktop->setDisabled();
    delete shortDesktop;
    shortDesktop = 0;
}

void XCap::initShortcuts()
{
    shortDesktop = new QxtGlobalShortcut(this);
    shortCurWin = new QxtGlobalShortcut(this);
    shortQuit = new QxtGlobalShortcut(this);
    
    shortDesktop->setEnabled();
    shortCurWin->setEnabled();
    shortQuit->setEnabled();
    
    connect(shortDesktop, SIGNAL(activated()), this, SLOT(capDesktop()));
    connect(shortCurWin, SIGNAL(activated()), this, SLOT(capCurWin()));
    connect(shortQuit, SIGNAL(activated()), qApp, SLOT(quit()));
    
    //shortDesktop->setShortcut( QKeySequence( tr("Ctrl+Shift+0") ) );
    //shortCurWin->setShortcut( QKeySequence( tr("Ctrl+Shift+9") ) );
    //shortQuit->setShortcut( QKeySequence( tr("Ctrl+Shift+7") ) );
    
    // works perfectly on Windows & Linux but does not work on Mac OS X!
    shortDesktop->setShortcut( QKeySequence( Qt::CTRL + Qt::SHIFT + Qt::Key_F12 ) );
    shortCurWin->setShortcut( QKeySequence( Qt::CTRL + Qt::SHIFT + Qt::Key_F11 ) );
    shortQuit->setShortcut( QKeySequence( Qt::CTRL + Qt::SHIFT + Qt::Key_F9 ) );
    
    //shortDesktop->setShortcut( QKeySequence( Qt::CTRL + Qt::SHIFT + Qt::Key_0 ) );
    //shortCurWin->setShortcut( QKeySequence( Qt::CTRL + Qt::SHIFT + Qt::Key_9 ) );
    //shortQuit->setShortcut( QKeySequence( Qt::CTRL + Qt::SHIFT + Qt::Key_7 ) );
}

void XCap::initActions()
{
    capDesktopAction = new QAction(tr("Capture &Desktop"), this);
    connect(capDesktopAction, SIGNAL(triggered()), this, SLOT(capDesktop()));
    
    capCurWinAction = new QAction(tr("Capture Active &Window"), this);
    connect(capCurWinAction, SIGNAL(triggered()), this, SLOT(capCurWin()));
    
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    
    signalMapper = new QSignalMapper(this);
    for(int i = 0; i < XF_TOTAL; ++i) {
        outTypeAction[i] = new QAction(tr(XCAP_FORMATS[i]), this);
        
        connect(outTypeAction[i], SIGNAL(triggered()), signalMapper, SLOT(map()));
        
        signalMapper->setMapping(outTypeAction[i], tr(XCAP_FORMATS[i]));
    }
    
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(setOutType(QString)));
}

void XCap::initSystemTray()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(capDesktopAction);
    trayIconMenu->addAction(capCurWinAction);
    trayIconMenu->addSeparator();
    
    outTypeMenu = trayIconMenu->addMenu( tr("Output Format:") );
    for(int i = 0; i < XF_TOTAL; ++i) {
        outTypeMenu->addAction(outTypeAction[i]);
    }
    
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
    
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon( QIcon(":/resources/heart.png") );
    
    trayIcon->setContextMenu(trayIconMenu);
    
    trayIcon->show();
}

void XCap::capDesktop()
{
    QApplication::beep();
    
    // clear image for low memory situations on embedded devices.
    capPixmap = QPixmap();
    capPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    
    savePix();
}

void XCap::capCurWin()
{
    QWidget * activeWin = 0;
    QApplication::beep();
    
    foreach(QWidget * awidget, QApplication::topLevelWidgets()) {
        if(awidget->isWindow()) {
            if(awidget->visibleRegion() != QRegion()) {
                //== QRegion(awidget->rect());
                if(1) {
                    activeWin = awidget;
                    break;
                }
            }
        }
    }
    
    // clear image for low memory situations on embedded devices.
    capPixmap = QPixmap();
    capPixmap = QPixmap::grabWidget(activeWin);
    
    QMessageBox::information(
        this,
        "Current Window's geometry",
        QString("w = %1, h = %2, activeWin = %3")
        .arg(capPixmap.width())
        .arg(capPixmap.height())
        .arg(int(activeWin))
    );
    
    savePix();
}

void XCap::setOutType(const QString & _outType)
{
    // set output format
    this->outType = _outType.trimmed().toLower();
    
    // update the submenu title
    outTypeMenu->setTitle( tr("Output Format: %1").arg(this->outType) );
    
    // update icon for the active format
    foreach(QAction *tempAct, outTypeMenu->actions()) {
        if(tempAct->text() == this->outType) {
            tempAct->setIcon( QIcon(":/resources/heart.png") );
            tempAct->setIconVisibleInMenu(true);
        } else {
            tempAct->setIcon( QIcon() );
            tempAct->setIconVisibleInMenu(false);
        }
    }
}

void XCap::savePix()
{
    imgPath = QString("%1/%2.%3")
    .arg(QDesktopServices::storageLocation(QDesktopServices::DesktopLocation))
    .arg(time(NULL))
    .arg(outType);
    
    if(outType == "pdf" || outType == "ps") {
        this->printPsPdf();
    } else {
        capPixmap.save(imgPath);
    }
}

void XCap::printPsPdf()
{
    QPrinter::OutputFormat printFormat;
    
    if(outType == "pdf") printFormat = QPrinter::PdfFormat;
    if(outType == "ps") printFormat = QPrinter::PostScriptFormat;
    
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(imgPath);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setFullPage(false);
    
    QPainter painter;
    if (! painter.begin(&printer)) {
        QMessageBox::information(
            this,
            "Cannot save!",
            tr("Cannot save the screenshot! Please check that %1 is writable.").arg(imgPath)
        );
        return;
    }
    painter.setWindow(0, 0, capPixmap.width(), capPixmap.height());
    
    QPen pen;
    pen.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.setPen(pen);
    
    // read more @ http://doc.trolltech.com/4.6/printing.html
    // read more @ http://doc.trolltech.com/4.6/qprinter.html
    painter.drawPixmap(
        QRect(0, 0, capPixmap.width(), capPixmap.height()),
        capPixmap,
        capPixmap.rect()
    );
    
    painter.end();
}
