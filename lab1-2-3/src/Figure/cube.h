#ifndef CUBE_H
#define CUBE_H

#include "ifigure.h"

class Cube : public IFigure
{
public:
    Cube(QWidget* parent = nullptr);
    ~Cube() = default;
    void createFigure(GLfloat size) override;
};

#endif // CUBE_H
