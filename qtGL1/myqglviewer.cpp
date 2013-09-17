#include "myqglviewer.h"
#include <GL/glut.h>
#include <QDebug>

MyQGLViewer::MyQGLViewer(QWidget *parent) :
    QGLViewer(parent)
{
}

void MyQGLViewer::initializeGL()
{
    this->camera()->setType(qglviewer::Camera::ORTHOGRAPHIC);
}

void MyQGLViewer::init()
{
    // Do nothing
}

void MyQGLViewer::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,0);
    glVertex2f(100,100);
    glVertex2f(0,100);
    glEnd();

//    glPushMatrix();
//    //glTranslatef(30, 30, -1);
//    glColor3f(0,0,1);
//    glutWireCone(2, 4, 64, 8);
//    glPopMatrix();

//    glFlush();
}

void MyQGLViewer::resizeGL(int width, int height)
{
//    qglviewer::Vec cameraPos = qglviewer::Vec(width / 2, height / 2, 0);
//    this->camera()->setPosition(cameraPos);

//    qglviewer::Vec lookAtPos = qglviewer::Vec(0, 0, 0);
//    this->camera()->lookAt(lookAtPos);
}
