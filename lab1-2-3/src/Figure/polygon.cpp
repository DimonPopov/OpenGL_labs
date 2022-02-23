#include "polygon.h"

Polygon::Polygon(QWidget* parent)
    : IFigure(parent)
{

}

void Polygon::createFigure(GLfloat size)
{
    glShadeModel(GL_SMOOTH);

    glBegin(GL_POLYGON);
        glColor4f(0.0f, 0.0f, 1.0f, 0.2f);
        glVertex3f(0.0, 0.0, 0.0);
        glColor4f(0.0f, 1.0f, 0.0f, 0.2f);
        glVertex3f(0.0, size, 0.0);
        glColor4f(1.0f, 0.0f, 0.0f, 0.2f);
        glVertex3f(size, size, 0.0);
        glColor4f(7.0f, 7.0f, 1.0f, 0.2f);
        glVertex3f(size, size, size);
        glColor4f(0.0f, 0.3f, 0.3f, 0.2f);
        glVertex3f(size, 0.0, 0.0);
    glEnd();
}
