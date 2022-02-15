#ifndef IFIGURE_H
#define IFIGURE_H

#include <QOpenGLWidget>

/**
 * @brief Интерфейс объемных фигур.
 */
class IFigure : public QOpenGLWidget
{
public:
    IFigure(QWidget* parent = nullptr);
    virtual ~IFigure(){};
    /**
     * @brief Выставляет значения для теста альфа-канала.
     */
    void setAlphaTest(GLuint, double);
    /**
     * @brief Выставляет значения для теста смешивания.
     */
    void setBlenderTest(GLuint, GLuint);
    /**
     * @brief Выставляет значения для теста отсечения.
     */
    void setScissorTest(GLint, GLint, GLsizei, GLsizei);
private:
    GLuint draw(GLfloat size);
    GLuint nFigure;                                         ///< номер дисплейного списка фигуры.
    GLfloat xRotate;                                        ///< угол поворота по х.
    GLfloat yRotate;                                        ///< угол поворота по у.
    QPoint pPosition;                                       ///< координата указателя мыши.
protected:
    GLuint alphaTest = GL_ALWAYS;                           ///< режим теста альфа-канала.
    double alphaTestValue = 0.0;                            ///< значения сравнения для альфа-теста.
    GLint x = 0;                                            ///< координаты x угла для теста отсечения.
    GLint y = 0;                                            ///< координаты y угла для теста отсечения.
    GLsizei w = width();                                        ///< ширина отсекающего прямоугольника.
    GLsizei h = width();                                        ///< ширина отсекающего прямоугольника.
    GLuint blenderTestSFactor = GL_ZERO;                    ///< cпособ вычисления входящих факторов смешения RGBA.
    GLuint blenderTestDFactor = GL_ONE;                     ///< способ вычисления факторов смешения RGBA, уже находящихся в буфере кадра.
    virtual void createFigure(GLfloat size) = 0;
    virtual void initializeGL() override;
    virtual void resizeGL(int, int) override;
    virtual void paintGL() override;
    virtual void mousePressEvent(QMouseEvent* e) override;
    virtual void mouseMoveEvent(QMouseEvent* e) override;
};

#endif // IFIGURE_H
