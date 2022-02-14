#ifndef POLYGON_H
#define POLYGON_H

#include "ifigure.h"

class Polygon : public IFigure
{
public:
    Polygon(QWidget* parent = nullptr);
    ~Polygon() = default;
    void createFigure(GLfloat size = 1.0f);
};

#endif // POLYGON_H
