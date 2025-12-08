#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    MainWindow window;
    window.setWindowTitle("To-Do List");
    window.resize(400, 500);
    window.show();
    
    return app.exec();
}