#include "triangle.h"

Triangle::Triangle(QWidget* parent)
    : IFigure(parent)
{

}

void Triangle::createFigure(GLfloat size)
{
    glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 0.0f, 0.0f, 0.2f);
        glVertex3f(0.0, size, 0.0);
        glColor4f(0.0f, 1.0f, 0.0f, 0.2f);
        glVertex3f(-size, -size, 0.0f);
        glColor4f(0.0f, 0.0f, 1.0f, 0.2f);
        glVertex3f(size, -size, 0.0f);
    glEnd();
}
