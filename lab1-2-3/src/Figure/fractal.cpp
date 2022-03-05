#include <QtMath>

#include "fractal.h"

Fractal::Fractal(QWidget* parent)
    : IFigure(parent)
{
    status = "ABCDEFGHA+ABCDEFGHA+ABCDEFGHA+ABCDEFGH";
}

void Fractal::createFigure(GLfloat /*size*/)
{
    drawFractal(250, 300, 90);
    drawFractal(236, 305, 45);
}

void Fractal::drawFractal(int x, int y, int angle)
{
    turtle = new Turtle(x, y, angle);

    glLineWidth(2);

    glBegin(GL_LINE_STRIP);
        glColor4f(0.0f, 1.0f, 0.0f, 0.2f);

        auto coordinates = turtle->getPosition();

        glVertex3d(coordinates.first, coordinates.second, 0);

        for (const auto& i : qAsConst(status))
        {
            if (i == 'A')
                turtle->forward(25);
            if (i == '+')
                turtle->left(90);
            if (i == 'B')
                turtle->forward(150);
            if (i == 'C')
            {
                turtle->right(145);
                turtle->forward(180);
            }
            if (i == 'E')
            {
                turtle->left(110);
                turtle->forward(80);
            }
            if (i == 'D')
            {
                turtle->right(90);
                turtle->forward(165);
            }
            if (i == 'F')
            {
                turtle->right(165);
                turtle->forward(115);
            }
            if (i == 'G')
            {
                turtle->right(125);
                turtle->forward(92);
            }
            if (i == 'H')
            {
                turtle->left(55);
                turtle->forward(20);
            }

            coordinates = turtle->getPosition();

            glVertex3d(coordinates.first,  coordinates.second, 0);
        }

        delete turtle;

    glEnd();
}

void Fractal::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width(), height(), 0, -1, 1);
}

void Fractal::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    nFigure = draw();
    glCallList(nFigure);
}

void Fractal::mousePressEvent(QMouseEvent *e)
{
    QOpenGLWidget::mousePressEvent(e);
}

void Fractal::mouseMoveEvent(QMouseEvent *e)
{
    QOpenGLWidget::mouseMoveEvent(e);
}
