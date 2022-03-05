#include <cmath>
#include <QtMath>

#include "turtle.h"

Turtle::Turtle(int _x, int _y, int angle)
    : defX(_x), defY(_y), defAngle(angle), angle(angle), x(_x), y(_y)
{

}

void Turtle::forward(int len)
{
    float newX = (float)len * cos(qDegreesToRadians((float)angle));
    float newY = (float)len * sin(qDegreesToRadians((float)angle));

    x += static_cast<int>(newX);
    y -= static_cast<int>(newY);
}

void Turtle::right(int _angle)
{
    angle -= _angle;
}

void Turtle::left(int _angle)
{
    angle += _angle;
}

void Turtle::go(int _x, int _y)
{
    x = _x;
    y = _y;
}

QPair<int, int> Turtle::getPosition() const
{
    return {x, y};
}

int Turtle::getAngle() const
{
    return angle;
}

void Turtle::returnToDefaultValue()
{
    x = defX;
    y = defY;
    angle = defAngle;
}

QPair<int, int> Turtle::getDefaultValue() const
{
    return {defX, defY};
}
