#include "myqglviewer.h"
#include <GL/glut.h>
#include <QDebug>

MyQGLViewer::MyQGLViewer(QWidget *parent) :
    QGLViewer(parent)
{
}

void MyQGLViewer::initializeGL()
{
    QRect geometry = ((QWidget*)this->parent())->geometry();

    qDebug() << geometry.width() + ", " + geometry.height();

    glViewport(0, 0, geometry.width(), geometry.height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, geometry.width(), 0, geometry.height(), -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyQGLViewer::init()
{
    // setAxisIsDrawn(true);
}

void MyQGLViewer::draw()
{
//    //some 3D
//    glColor4f(1.0, 0.5, 0.5, 1.0);
//    glutSolidTeapot(0.5);
//    glTranslated(1.0, 0, 0);
//    glColor4f(0.5, 1.0, 0.5, 1.0);
//    glutSolidSphere(0.33, 20, 20);
//    glTranslated(-2.0, -0.5, 0);
//    glColor4f(0.5, 0.5, 1.0, 1.0);
//    glRotated(-90, 1, 0, 0);
//    glutSolidCone(0.5, 1.0, 20, 20);

//    glColor4f(1.0, 0.0, 0.0, 1.0);
//    drawText(60, 60, QString(tr("3D 프로그램!")), QFont("나눔고딕", 20));

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,500);
    glVertex2f(500,100);
    glEnd();
}

void MyQGLViewer::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
