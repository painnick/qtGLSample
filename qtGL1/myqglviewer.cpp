#include "myqglviewer.h"
#include <GL/glut.h>
#include <QDebug>

using namespace qglviewer;
using namespace std;

MyQGLViewer::MyQGLViewer(QWidget* parent, const QGLWidget* shareWidget)
    : QGLViewer(parent, shareWidget)
{
    // Move camera according to viewer type (on X, Y or Z axis)
    camera()->setPosition(Vec(0.0, 0.0, 1.0));
    camera()->lookAt(sceneCenter());

    camera()->setType(Camera::ORTHOGRAPHIC);
    camera()->showEntireScene();

    // Forbid rotation
    WorldConstraint* constraint = new WorldConstraint();
    constraint->setRotationConstraintType(AxisPlaneConstraint::FORBIDDEN);
    camera()->frame()->setConstraint(constraint);
}

void MyQGLViewer::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(1,0);
    glVertex2f(1,1);
    glVertex2f(0,1);
    glEnd();

    const float nbSteps = 200.0;
    glBegin(GL_QUAD_STRIP);
    for (float i=0; i<nbSteps; ++i)
      {
        float ratio = i/nbSteps;
        float angle = 21.0*ratio;
        float c = cos(angle);
        float s = sin(angle);
        float r1 = 1.0 - 0.8f*ratio;
        float r2 = 0.8f - 0.8f*ratio;
        float alt = ratio - 0.5f;
        const float nor = 0.5f;
        const float up = sqrt(1.0-nor*nor);
        glColor3f(1.0-ratio, 0.2f , ratio);
        glNormal3f(nor*c, up, nor*s);
        glVertex3f(r1*c, alt, r1*s);
        glVertex3f(r2*c, alt+0.05f, r2*s);
      }
    glEnd();
}
