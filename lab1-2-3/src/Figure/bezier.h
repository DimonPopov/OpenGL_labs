#ifndef BEZIER_H
#define BEZIER_H

#include <QList>

#include "ifigure.h"

class Bezier : public IFigure
{
private:
    QList<QPoint> points;           ///< набор точек.
    GLint r;                        ///< радиус точек.
    GLint currentPoint;            ///< захваченная курсором точка.
    /**
     * @brief Отрисовка кривой Безье на основе точек из point
     */
    void drawBezierLine();
public:
    Bezier(QWidget* parent = nullptr);
    ~Bezier() = default;
    void createFigure(GLfloat size) override;
protected:
    virtual void mousePressEvent(QMouseEvent* e) override;
    virtual void mouseMoveEvent(QMouseEvent* e) override;
    virtual void mouseReleaseEvent(QMouseEvent* e)  override;
    virtual void paintGL() override;
    virtual void resizeGL(int, int) override;
};

#endif // BEZIER_H
