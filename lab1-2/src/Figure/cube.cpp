#include "cube.h"

Cube::Cube(QWidget* parent)
    : IFigure(parent)
{

}

void Cube::createFigure(GLfloat size)
{
    size = size * 2/3;

    glBegin(GL_QUADS);
         // левая грань
         glColor4f(0.0f, 1.0f, 0.0f, 0.2f);
         glVertex3f( -size, -size, -size);
         glVertex3f( -size,  size, -size);
         glVertex3f( -size,  size,  size);
         glVertex3f( -size, -size,  size);
         // правая грань
         glColor4f(1.0f, 0.0f, 0.0f, 0.3f);
         glVertex3f(  size, -size, -size);
         glVertex3f(  size, -size,  size);
         glVertex3f(  size,  size,  size);
         glVertex3f(  size,  size, -size);
         // нижняя грань
         glColor4f(0.0f, 0.0f, 1.0f, 0.4f);
         glVertex3f( -size, -size, -size);
         glVertex3f( -size, -size,  size);
         glVertex3f(  size, -size,  size);
         glVertex3f(  size, -size, -size);
         // верхняя грань
         glColor4f(0.2f, 0.3f, 0.7f, 0.5f);
         glVertex3f( -size, size, -size);
         glVertex3f( -size, size,  size);
         glVertex3f(  size, size,  size);
         glVertex3f(  size, size, -size);
         // задняя грань
         glColor4f(0.2f, 0.2f, 0.2f, 0.6f);
         glVertex3f( -size, -size, -size);
         glVertex3f(  size, -size, -size);
         glVertex3f(  size,  size, -size);
         glVertex3f( -size,  size, -size);
         // передняя грань
         glColor4f(0.7f, 0.3f, 0.1f, 0.7f);
         glVertex3f( -size, -size,  size);
         glVertex3f(  size, -size,  size);
         glVertex3f(  size,  size,  size);
         glVertex3f( -size,  size,  size);
    glEnd();
}
