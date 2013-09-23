#ifndef MYQGLVIEWER_H
#define MYQGLVIEWER_H

#include <QWidget>
#include <QGLViewer/qglviewer.h>

class MyQGLViewer : public QGLViewer
{
    Q_OBJECT
public:
    explicit MyQGLViewer(QWidget* parent=0, const QGLWidget* shareWidget=0);

protected:
    void draw();

signals:
    
public slots:
    
};

#endif // MYQGLVIEWER_H
