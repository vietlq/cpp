#ifndef XCAP_H
#define XCAP_H

#include <QtGui/QWidget>
#include <QKeySequence>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QSignalMapper>

//#include <QxtGui/QxtGlobalShortcut>
#include "libqxt/src/gui/qxtglobalshortcut.h"

static const char* XCAP_FORMATS[] = {
    "png", "jpg", "gif", "bmp", "pdf", "ps", "tif", "svg", 0
};

class XCap : public QWidget
{
    Q_OBJECT

public:
    enum allowed_formats_t {
        PNG = 0, JPG, GIF, BMP, PDF, PS, TIF, SVG, XF_TOTAL
    };
    
    XCap(QWidget *parent = 0);
    ~XCap();
    
public slots:
    void capDesktop();
    void capCurWin();
    void setOutType(const QString & _outType);
    
protected:
    void initShortcuts();
    void initActions();
    void initSystemTray();
    
    void savePix();
    void printPsPdf();
    
private:
    QxtGlobalShortcut * shortDesktop;
    QxtGlobalShortcut * shortCurWin;
    QxtGlobalShortcut * shortQuit;
    
    QPixmap capPixmap;
    
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QMenu *outTypeMenu;
    
    QAction *capDesktopAction;
    QAction *capCurWinAction;
    QAction *quitAction;
    QAction *outTypeAction[XF_TOTAL];
    
    QString outType;
    QString imgPath;
    
    QSignalMapper *signalMapper;
};

#endif // XCAP_H
