#ifndef POLYGON_H
#define POLYGON_H

#include "ifigure.h"

class Polygon : public IFigure
{
public:
    Polygon(QWidget* parent = nullptr);
    ~Polygon() = default;
    void createFigure(GLfloat size) override;
};

#endif // POLYGON_H
