#ifndef PYRAMIDE_H
#define PYRAMIDE_H

#include "ifigure.h"

class Pyramide : public IFigure
{
public:
    Pyramide(QWidget* parent = nullptr);
    ~Pyramide() = default;
    void createFigure(GLfloat size = 1.0f);
};

#endif // PYRAMIDE_H
