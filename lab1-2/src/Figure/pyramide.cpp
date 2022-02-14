#include "pyramide.h"

Pyramide::Pyramide(QWidget* parent)
    :IFigure(parent)
{

}

void Pyramide::createFigure(GLfloat size)
{
    glBegin(GL_TRIANGLE_FAN);
        glColor4f(0.0f, 1.0f, 0.0f, 0.3f);
        glVertex3f(0.0, size, 0.0);
        glVertex3f(-size, -size, size);
        glVertex3f(size, -size, size);
        glColor4f(1.0f, 0.5f, 0.0f, 0.4f);
        glVertex3f(size, -size, -size);
        glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
        glVertex3f(-size, -size, -size);
        glColor4f(1.0f, 1.0f, 0.0f, 0.6f);
        glVertex3f(-size, -size, size);
    glEnd();

    glBegin(GL_QUADS);
        glColor4f(1.0f, 0.0f, 0.0f, 0.7f);
        glVertex3f(-size, -size, size);
        glVertex3f(size, -size, size);
        glVertex3f(size, -size, -size);
        glVertex3f(-size, -size, -size);
    glEnd();
}
