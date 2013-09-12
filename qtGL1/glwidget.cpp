#include "glwidget.h"

#include <QDebug>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);
}

void GLWidget::initializeGL() {
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_POLYGON_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0, 0, 0, 0);

    point = QPoint(100, 100);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,500);
    glVertex2f(500,100);
    glEnd();

    // 입력 좌표 표시
    QPoint topLeft = point + QPoint(-10, -10);
    QPoint bottomRight = point + QPoint(10, 10);

    qDebug() << "== topLeft & bottomRight";
    qDebug() << QString::number(topLeft.x()) + ", " + QString::number(topLeft.y());
    qDebug() << QString::number(bottomRight.x()) + ", " + QString::number(bottomRight.y());

    glColor3f(0,1,0);
    glRectf(topLeft.x(), topLeft.y(), bottomRight.x(), bottomRight.y());
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
    qDebug() << QString::number(event->x()) + ", " + QString::number(event->y());

    point.setX(event->x());
    point.setY(this->height() - event->y());

    this->repaint();
}


void GLWidget::mouseMoveEvent(QMouseEvent *event) {
    // printf("%d, %d\n", event->x(), event->y());
}

void GLWidget::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
    case Qt::Key_Escape:
        close();
        break;
    default:
        event->ignore();
        break;
    }
}
