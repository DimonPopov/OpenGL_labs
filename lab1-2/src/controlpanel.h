#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include <QHBoxLayout>
#include <QComboBox>
#include <QDoubleSpinBox>

#include "Figure/ifigure.h"

/**
 * @brief Панель управления сценой.
 */
class ControlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPanel(QWidget *parent = nullptr);
    /**
     * @brief Получения строки команды GL по номеру.
     * @return Команда GL.
     */
    static GLuint getDigit(QString);
    /**
     * @brief Получения номера команды GL по строке.
     * @return Команда GL строкой.
     */
    static QString getString(GLuint);
private:
    /**
     * @brief Инициализация виджета с фигурой.
     */
    void initGLscene();
    /**
     * @brief Инициализация всех управлющих элементов.
     */
    void initControlElement();
    IFigure* currentFigure;         ///< указатель на текущую фигуру.
    QHBoxLayout* hLayout;           ///< указатель на компоновщик.
    QComboBox* transparencyBox;     ///< указатель на комбо-бокс с выбором типа альфа-теста.
    QDoubleSpinBox* spinRef;        ///< указатель на спин-бокс со значением сравниваемого альфа-канала.
    QComboBox* blendBox1;           ///< указатель на комбо-бокс с выбором смешивания S фактора.
    QComboBox* blendBox2;           ///< указатель на комбо-бокс с выбором смешивания D фактора.
    QSlider* xSlider;               ///< Слайдер для точки х теста отссечения.
    QSlider* ySlider;               ///< Слайдер для точки у теста отссечения.
    QSlider* wSlider;               ///< Слайдер для ширины теста отссечения.
    QSlider* hSlider;               ///< Слайдер для высоты теста отссечения.
private slots:
    void handleBlandBoxChanged(QString);
    void handlePrimitiveBoxChanged(QString);
    void handleTransparencySpinBoxChanged(double newValue);
    void handleAlphaTest(QString);
    void handleScissorSliderTriggered(int);
};

#endif // CONTROLPANEL_H
