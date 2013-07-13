#include <QApplication>
#include <QWidget>
#include <QLineEdit>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    
    QWidget window;
    window.setWindowTitle("Hi there! What's your name?");
    
    QLineEdit name(&window);
    
    window.show();
    
    return app.exec();
}

