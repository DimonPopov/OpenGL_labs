#ifndef FRACTAL_H
#define FRACTAL_H

#include <QMap>

#include "ifigure.h"
#include "turtle.h"

class Fractal : public IFigure
{
public:
    explicit Fractal(QWidget* parent = nullptr);
    ~Fractal() = default;
    void createFigure(GLfloat size) override;
private:
    Turtle* turtle;                             ///< Представление черепашки.
    QString status;                             ///< Текущее состояние аксиомы.

    /**
     * @brief Отрисовка по заданному состоянию
     * @param x - начальная точка черепашки по х.
     * @param y - начальная точка черепашки по у.
     * @param angle - начальное направление взгляда черепашки.
     */
    void drawFractal(int x, int y, int angle);
protected:
    virtual void resizeGL(int, int) override;
    virtual void paintGL() override;
    virtual void mousePressEvent(QMouseEvent* e) override;
    virtual void mouseMoveEvent(QMouseEvent* e) override;
};

#endif // FRACTAL_H
