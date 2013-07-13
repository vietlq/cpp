#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    
    QWidget window;
    window.show();
    window.setWindowTitle("Hi there! What's your name?");
    
    return app.exec();
}

