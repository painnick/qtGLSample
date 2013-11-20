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
    camera()->setFOVToFitScene();

    camera()->setType(Camera::ORTHOGRAPHIC);
//    camera()->showEntireScene();

    // Forbid rotation
    WorldConstraint* constraint = new WorldConstraint();
    constraint->setRotationConstraintType(AxisPlaneConstraint::FORBIDDEN);
    camera()->frame()->setConstraint(constraint);

    glEnable(GL_DEPTH_TEST);
}

void MyQGLViewer::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(-1.0f, 1.0f, -1.0f);

    int countX = 16;
    int countY = 24;
    float base = 2.0f / min(countX, countY);

    float stepX = 2.0f / (countX - 1);
    float stepY = 2.0f / (countY - 1);

    for(int y = 0; y < countY; y ++) {
        for(int x = 0; x < countX; x ++) {
            float r = (rand() % 256) / 256.0f;
            float g = (rand() % 256) / 256.0f;
            float b = (rand() % 256) / 256.0f;
            glColor3f(r, g, b);

            glutSolidCone(0.5, 1.0, 16, 8);

            if(x != countX - 1)
                glTranslatef(stepX, 0, 0);
        }
        glTranslatef(-2.0f, -stepY, 0);
    }
}
