#ifndef LINE_H
#define LINE_H

#include "ifigure.h"

class Line : public IFigure
{
public:
    Line(QWidget* parent = nullptr);
    ~Line() = default;
    void createFigure(GLfloat size) override;
};

#endif // LINE_H
