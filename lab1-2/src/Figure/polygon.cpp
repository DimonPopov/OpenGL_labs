#include "polygon.h"

Polygon::Polygon(QWidget* parent)
    : IFigure(parent)
{

}

void Polygon::createFigure(GLfloat size)
{
    glBegin(GL_POLYGON);
        glColor4f(0.0f, 0.0f, 1.0f, 0.2f);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, size, 0.0);
        glVertex3f(size, size, 0.0);
        glVertex3f(size, size, size);
        glVertex3f(size, 0.0, 0.0);
    glEnd();
}
