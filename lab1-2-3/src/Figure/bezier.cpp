#include <QMouseEvent>
#include <QtMath>
#include <QDebug>

#include "bezier.h"

#define MAX_STEPS 30

Bezier::Bezier(QWidget* parent)
    : IFigure(parent), r(20), currentPoint(-1)
{

}

void Bezier::createFigure(GLfloat /*size*/)
{
    glPointSize(r);
    glBegin(GL_POINTS);

        glColor4f(1.0f, 0.0f, 0.0f, 0.0f);

        for (const auto& i : qAsConst(points))
        {
            glVertex3d(i.x(), i.y(), 0);
        }

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINE_STRIP);

        glColor4f(0.0f, 1.0f, 0.0f, 0.0f);

        for (const auto& i : qAsConst(points))
        {
            glVertex3d(i.x(), i.y(), 0);
        }

    glEnd();

    if (points.count() >= 3)
        drawBezierLine();

}

void Bezier::drawBezierLine()
{
    glColor4f(0.0f, 0.0f, 1.0f, 0.0f);

    glBegin(GL_LINE_STRIP);
        float step = 1.0f / MAX_STEPS;

        if (points.count() == 4)
        {
            for (float t = 0; t <= (1 + step); t += step)
            {
                float x = pow((1 - t), 3) * points[0].x() + 3 * pow((1 - t), 2) * t * points[1].x() + 3 * (1 - t)* pow(t, 2) * points[2].x() + pow(t, 3) * points[3].x();
                float y = pow((1 - t), 3) * points[0].y() + 3 * pow((1 - t), 2) * t * points[1].y() + 3 * (1 - t)* pow(t, 2) * points[2].y() + pow(t, 3) * points[3].y();

                glVertex3d(x, y, 0);
            }
        }
        else
        {
            for (float t = 0; t <= (1 + step); t += step)
            {
                float x = pow((1 - t), 2) * points[0].x() + 2 * (1 - t) * t * points[1].x() + pow(t, 2) * points[2].x();
                float y = pow((1 - t), 2) * points[0].y() + 2 * (1 - t) * t * points[1].y() + pow(t, 2) * points[2].y();
                glVertex3d(x, y, 0);
            }
        }
    glEnd();
}

void Bezier::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width(), height(), 0, -1, 1);
}

void Bezier::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    nFigure = draw();
    glCallList(nFigure);
}

void Bezier::mousePressEvent(QMouseEvent *e)
{
    int x = e->x();
    int y = e->y();

    for (int i = 0; i < points.count(); ++i)
    {
        if (x > (points[i].x() - r) && x < (points[i].x() + r) &&
            y > (points[i].y() - r) && y < (points[i].y() + r))
        {
            currentPoint = i;
            return;
        }
    }

    if (points.count() >= 4)
    {
        return;
    }
    else
    {
        QPoint tmp(x, y);
        points.append(tmp);
        update();
    }
}

void Bezier::mouseReleaseEvent(QMouseEvent* /*e*/)
{
    currentPoint = -1;
}

void Bezier::mouseMoveEvent(QMouseEvent *e)
{
    if (currentPoint != -1)
    {
        if (e->x() < width() && e->x() > 0)
            points[currentPoint].setX(e->x());
        if (e->y() < height() && e->y() > 0)
            points[currentPoint].setY(e->y());

        update();
    }
}
