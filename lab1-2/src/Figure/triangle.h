#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "ifigure.h"

class Triangle : public IFigure
{
public:
    Triangle(QWidget* parent = nullptr);
    ~Triangle() = default;
    void createFigure(GLfloat size = 1.0f);
};

#endif // TRIANGLE_H
