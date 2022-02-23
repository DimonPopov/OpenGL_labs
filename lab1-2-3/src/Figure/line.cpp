#include "line.h"

Line::Line(QWidget* parent)
    : IFigure(parent)
{

}

void Line::createFigure(GLfloat size)
{   
    glBegin(GL_LINES);
        glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
        glVertex3f(0.0, size, 0.0);
        glVertex3f(-size, -size, size);
        glVertex3f(size, -size, size);
        glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
        glVertex3f(size, -size, -size);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex3f(-size, -size, -size);
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glVertex3f(-size, -size, size);
    glEnd();

}
