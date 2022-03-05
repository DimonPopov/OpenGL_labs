#ifndef TURTLE_H
#define TURTLE_H

#include <QObject>

/**
 * @brief Класс передвигающейся черепашки, которая
 * оставляет за собой след из линии.
 */
class Turtle
{
public:
    Turtle(int x, int y, int angle = 0);
    ~Turtle() = default;

    /**
     * @brief Переместить черепаху на расстояние.
     * @param len - расстояние на которое надо переместиться.
     */
    void forward(int len);

    /**
     * @brief Повернуть черепашку направо.
     * @param angle - угол поворота в градусах.
     */
    void right(int angle);

    /**
     * @brief Повернуть черепашку налево.
     * @param angle - угол поворота в градусах.
     */
    void left(int angle);

    /**
     * @brief Переместиться в определенную точку.
     * @param x - координата по линии абсцисс.
     * @param y - координата по линии координат.
     */
    void go(int x, int y);

    /**
     * @brief Получить координаты черепахи.
     * @return текущие координаты.
     */
    QPair<int, int> getPosition() const;

    /**
     * @brief Получить текущий угол направления движения.
     * @return угол в градусах.
     */
    int getAngle() const;

    /**
     * @brief Получить стартовую позицию черепахи.
     * @return стартовые координаты.
     */
    QPair<int, int> getDefaultValue() const;

    /**
     * @brief Вернуть координаты и угол к дефолтным значениям
     * (заданным при создании экземпляра).
     */
    void returnToDefaultValue();

private:
    int defX;                   ///< дефолтное значение у.
    int defY;                   ///< дефолтное значение х.
    int defAngle;               ///< дефолтный угол в градусах.
    int angle;                  ///< текущий угол в градусах.
    int x;                      ///< позиция по х.
    int y;                      ///< позиция по y.
};

#endif // TURTLE_H
