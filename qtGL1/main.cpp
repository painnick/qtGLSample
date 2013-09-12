#include "mainwindow.h"
#include "glwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    glutInit(&argc, argv);

    MainWindow w;
    w.show();

//    GLWidget window;
//    window.resize(500, 500);
//    window.show();
    
    return a.exec();
}
