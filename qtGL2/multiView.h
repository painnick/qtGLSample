#ifndef MULTIVIEW_H
#define MULTIVIEW_H

#include <QGLViewer/qglviewer.h>

class Scene
{
public:
  void draw() const;
};


class Viewer : public QGLViewer
{
public:
  Viewer(const Scene* const s, int type, QWidget* parent, const QGLWidget* shareWidget=NULL);

protected :
  virtual void draw();

private:
  const Scene* const scene_;
};

#endif // MULTIVIEW_H
