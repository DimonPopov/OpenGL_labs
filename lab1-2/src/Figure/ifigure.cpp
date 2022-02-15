#include <QOpenGLFunctions>
#include <QMouseEvent>

#include "ifigure.h"

IFigure::IFigure(QWidget* parent)
    : QOpenGLWidget(parent), xRotate(0), yRotate(0)
{
    setMinimumSize(600, 600);
}

void IFigure::initializeGL()
{
    QOpenGLFunctions* func = QOpenGLContext::currentContext()->functions();
    func->glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    func->glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    nFigure = draw(1.2f);
}

GLuint IFigure::draw(GLfloat size)
{
    GLuint n = glGenLists(1);
    glNewList(n, GL_COMPILE);

    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_SCISSOR_TEST);

    glBlendFunc(blenderTestDFactor, blenderTestSFactor);
    glAlphaFunc(alphaTest, alphaTestValue);
    glScissor(x, y, w, h);

    createFigure(size);

    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_SCISSOR_TEST);

    glEndList();

    return n;
}

void IFigure::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
}

void IFigure::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(xRotate, 1.0, 0.0, 0.0);
    glRotatef(yRotate, 0.0, 1.0, 0.0);
    glCallList(nFigure);
}

void IFigure::mousePressEvent(QMouseEvent *e)
{
    pPosition = e->pos();
}

void IFigure::mouseMoveEvent(QMouseEvent *e)
{
    xRotate += 180 * (GLfloat)(e->y() - pPosition.y()) / height();
    yRotate += 180 * (GLfloat)(e->x() - pPosition.x()) / width();
    update();
    pPosition = e->pos();
}

void IFigure::setAlphaTest(GLuint test, double value)
{
    alphaTest = test;
    alphaTestValue = value;
    nFigure = draw(1.2f);
    update();
}

void IFigure::setBlenderTest(GLuint sF, GLuint dF)
{
    blenderTestDFactor = dF;
    blenderTestSFactor = sF;
    nFigure = draw(1.2f);
    update();
}

void IFigure::setScissorTest(GLint _x , GLint _y, GLsizei _w, GLsizei _h)
{
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    nFigure = draw(1.2f);
    update();
}
