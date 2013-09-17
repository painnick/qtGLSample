#ifndef MYQGLVIEWER_H
#define MYQGLVIEWER_H

#include <QWidget>
#include <QGLViewer/qglviewer.h>

class MyQGLViewer : public QGLViewer
{
    Q_OBJECT
public:
    explicit MyQGLViewer(QWidget *parent = 0);
    void resizeGL(int width, int height);


protected:
    void initializeGL();
    void init();
    void draw();

signals:
    
public slots:
    
};

#endif // MYQGLVIEWER_H
