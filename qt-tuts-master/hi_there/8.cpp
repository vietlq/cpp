#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    
    QWidget window;
    window.setWindowTitle("Hi there! What's your name?");
    
    QLineEdit name(&window);
    
    window.setMinimumSize(400, 300);
    
    name.setGeometry(20, 20, 200, 30);
    name.setText("Please enter your name");
    
    QPushButton button(&window);
    button.setGeometry(240, 20, 100, 30);
    button.setText("Click here");
    
    QLabel label(&window);
    label.setGeometry(20, 70, 300, 60);
    label.setText("Hi there! Please enter your name ;)");
    
    QObject::connect(&name, SIGNAL(textChanged(QString)), &label, SLOT(setText(QString)));
    QObject::connect(&button, SIGNAL(clicked()), &name, SLOT(clear()));
    QObject::connect(&button, SIGNAL(clicked()), &label, SLOT(clear()));
    
    window.show();
    
    return app.exec();
}

