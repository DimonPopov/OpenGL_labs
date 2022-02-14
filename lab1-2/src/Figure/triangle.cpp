#include "triangle.h"

Triangle::Triangle(QWidget* parent)
    : IFigure(parent)
{

}

void Triangle::createFigure(GLfloat size)
{
    glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 0.0f, 0.0f, 0.7f);
        glVertex3f(0.0, size, 0.0);
        glVertex3f(-size, -size, size);
        glVertex3f(size, -size, size);
    glEnd();
}
