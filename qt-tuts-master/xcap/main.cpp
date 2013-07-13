#include <QtGui/QApplication>
#include "XCap.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(xcap);
    
    QApplication app(argc, argv);
    
    QApplication::setQuitOnLastWindowClosed(false);
    
    XCap capwin;
    capwin.hide();
    
    return app.exec();
}
