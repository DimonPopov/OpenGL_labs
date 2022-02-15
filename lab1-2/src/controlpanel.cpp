#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QColorDialog>
#include <QDoubleSpinBox>
#include <QSpacerItem>
#include <QSlider>

#include "controlpanel.h"
#include "Figure/line.h"
#include "Figure/cube.h"
#include "Figure/pyramide.h"
#include "Figure/triangle.h"
#include "Figure/polygon.h"

#define KEY_LINES       ("GL_LINES")
#define KEY_TRIANGLE    ("GL_TRIANGLES")
#define KEY_QUAD        ("GL_QUADS")
#define KEY_POLYGON     ("GL_POLYGON")
#define KEY_PYRAMIDE    ("GL_TRIANGLE_FAN")


ControlPanel::ControlPanel(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(200, 400);
    initGLscene();
    initControlElement();
}

void ControlPanel::initGLscene()
{
    currentFigure = new Line();
}

void ControlPanel::initControlElement()
{
    hLayout = new QHBoxLayout(this);

    QVBoxLayout* vLayout = new QVBoxLayout;

    QLabel* lab1Label = new QLabel(tr("Primitives:"));
    QComboBox* primitivesBox = new QComboBox;

    primitivesBox->addItem(KEY_LINES);
    primitivesBox->addItem(KEY_TRIANGLE);
    primitivesBox->addItem(KEY_QUAD);
    primitivesBox->addItem(KEY_POLYGON);
    primitivesBox->addItem(KEY_PYRAMIDE);

    connect(primitivesBox, &QComboBox::currentTextChanged, this, &ControlPanel::handlePrimitiveBoxChanged);

    QLabel* transparencyLabel = new QLabel(tr("Alpha test:"));
    transparencyBox = new QComboBox;

    transparencyBox->addItem(tr(getString(GL_ALWAYS).toUtf8()));
    transparencyBox->addItem(tr(getString(GL_NEVER).toUtf8()));
    transparencyBox->addItem(tr(getString(GL_LESS).toUtf8()));
    transparencyBox->addItem(tr(getString(GL_EQUAL).toUtf8()));
    transparencyBox->addItem(tr(getString(GL_LEQUAL).toUtf8()));
    transparencyBox->addItem(tr(getString(GL_GREATER).toUtf8()));
    transparencyBox->addItem(tr(getString(GL_NOTEQUAL).toUtf8()));
    transparencyBox->addItem(tr(getString(GL_GEQUAL).toUtf8()));

    connect(transparencyBox, &QComboBox::currentTextChanged, this, &ControlPanel::handleAlphaTest);

    spinRef = new QDoubleSpinBox;
    spinRef->setSingleStep(0.1);
    spinRef->setMinimum(0);
    spinRef->setMaximum(1);
    spinRef->setToolTip(tr("Alpha channel"));

    connect(spinRef, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &ControlPanel::handleTransparencySpinBoxChanged);

    QLabel* blendTextLabel = new QLabel(tr("Blender test:"));
    blendBox1 = new QComboBox;

    blendBox1->addItem(tr(getString(GL_ZERO).toUtf8()));
    blendBox1->addItem(tr(getString(GL_ONE).toUtf8()));
    blendBox1->addItem(tr(getString(GL_DST_COLOR).toUtf8()));
    blendBox1->addItem(tr(getString(GL_ONE_MINUS_DST_COLOR).toUtf8()));
    blendBox1->addItem(tr(getString(GL_SRC_ALPHA).toUtf8()));
    blendBox1->addItem(tr(getString(GL_ONE_MINUS_SRC_ALPHA).toUtf8()));
    blendBox1->addItem(tr(getString(GL_DST_ALPHA).toUtf8()));
    blendBox1->addItem(tr(getString(GL_ONE_MINUS_DST_ALPHA).toUtf8()));
    blendBox1->addItem(tr(getString(GL_SRC_ALPHA_SATURATE).toUtf8()));

    connect(blendBox1, &QComboBox::currentTextChanged, this, &ControlPanel::handleBlandBoxChanged);

    blendBox2 = new QComboBox;

    blendBox2->addItem(tr(getString(GL_ONE).toUtf8()));
    blendBox2->addItem(tr(getString(GL_ZERO).toUtf8()));
    blendBox2->addItem(tr(getString(GL_ONE_MINUS_SRC_ALPHA).toUtf8()));
    blendBox2->addItem(tr(getString(GL_SRC_COLOR).toUtf8()));
    blendBox2->addItem(tr(getString(GL_ONE_MINUS_SRC_COLOR).toUtf8()));
    blendBox2->addItem(tr(getString(GL_SRC_ALPHA).toUtf8()));
    blendBox2->addItem(tr(getString(GL_DST_ALPHA).toUtf8()));
    blendBox2->addItem(tr(getString(GL_ONE_MINUS_DST_ALPHA).toUtf8()));

    connect(blendBox2, &QComboBox::currentTextChanged, this, &ControlPanel::handleBlandBoxChanged);

    QLabel* ScissorTextLabel = new QLabel(tr("Scissor test:"));

    QHBoxLayout* vSliderLayout1 = new QHBoxLayout;
    QHBoxLayout* vSliderLayout2 = new QHBoxLayout;
    QHBoxLayout* vSliderLayout3 = new QHBoxLayout;
    QHBoxLayout* vSliderLayout4 = new QHBoxLayout;

    QLabel* x = new QLabel("x: ");
    QLabel* y = new QLabel("y: ");
    QLabel* w = new QLabel("w:");
    QLabel* h = new QLabel("h: ");

    xSlider = new QSlider(Qt::Orientation::Horizontal);
    ySlider = new QSlider(Qt::Orientation::Horizontal);
    wSlider = new QSlider(Qt::Orientation::Horizontal);
    hSlider = new QSlider(Qt::Orientation::Horizontal);

    connect(xSlider, &QSlider::actionTriggered, this, &ControlPanel::handleScissorSliderTriggered);
    connect(ySlider, &QSlider::actionTriggered, this, &ControlPanel::handleScissorSliderTriggered);
    connect(wSlider, &QSlider::actionTriggered, this, &ControlPanel::handleScissorSliderTriggered);
    connect(hSlider, &QSlider::actionTriggered, this, &ControlPanel::handleScissorSliderTriggered);

    xSlider->setMinimum(0);
    ySlider->setMinimum(0);
    wSlider->setMinimum(0);
    hSlider->setMinimum(0);

    xSlider->setMaximum(currentFigure->width());
    ySlider->setMaximum(currentFigure->height());
    wSlider->setMaximum(currentFigure->width());
    hSlider->setMaximum(currentFigure->height());

    wSlider->setValue(currentFigure->width());
    hSlider->setValue(currentFigure->height());

    xSlider->setToolTip(QString("x = %1").arg(xSlider->value()));
    ySlider->setToolTip(QString("y = %1").arg(ySlider->value()));
    wSlider->setToolTip(QString("w = %1").arg(wSlider->value()));
    hSlider->setToolTip(QString("h = %1").arg(hSlider->value()));

    vSliderLayout1->addWidget(x);
    vSliderLayout1->addWidget(xSlider);
    vSliderLayout2->addWidget(y);
    vSliderLayout2->addWidget(ySlider);
    vSliderLayout3->addWidget(w);
    vSliderLayout3->addWidget(wSlider);
    vSliderLayout4->addWidget(h);
    vSliderLayout4->addWidget(hSlider);


    QLabel* hint = new QLabel(tr("Hint: You can rotate the shape."));

    vLayout->addWidget(lab1Label);
    vLayout->addWidget(primitivesBox);
    vLayout->addWidget(transparencyLabel);
    vLayout->addWidget(transparencyBox);
    vLayout->addWidget(spinRef);
    vLayout->addWidget(blendTextLabel);
    vLayout->addWidget(blendBox1);
    vLayout->addWidget(blendBox2);
    vLayout->addWidget(ScissorTextLabel);
    vLayout->addLayout(vSliderLayout1);
    vLayout->addLayout(vSliderLayout2);
    vLayout->addLayout(vSliderLayout3);
    vLayout->addLayout(vSliderLayout4);
    auto spacer = new QSpacerItem(100, 100, QSizePolicy::Minimum, QSizePolicy::Maximum);
    vLayout->addSpacerItem(spacer);
    vLayout->addWidget(hint);

    hLayout->addLayout(vLayout);
    hLayout->addWidget(currentFigure);
}

void ControlPanel::handlePrimitiveBoxChanged(QString text)
{
    delete currentFigure;

    if (text == KEY_LINES)
        currentFigure = new Line();
    else if (text == KEY_TRIANGLE)
        currentFigure = new Triangle();
    else if (text == KEY_POLYGON)
        currentFigure = new Polygon();
    else if (text == KEY_PYRAMIDE)
        currentFigure = new Pyramide();
    else if (text == KEY_QUAD)
        currentFigure = new Cube();
    else
        currentFigure = new Line();

    // Вау, вот это костыль, ну Димасик, ну красава...
    hLayout->addWidget(currentFigure);
    // После выбора фигуры, задействовать значения с панели контроля.
    handleAlphaTest(transparencyBox->currentText());
    handleScissorSliderTriggered(0);
    handleBlandBoxChanged("");
}

void ControlPanel::handleAlphaTest(QString text)
{
    auto value = spinRef->value();
    currentFigure->setAlphaTest(getDigit(text), value);
}

void ControlPanel::handleTransparencySpinBoxChanged(double /*newValue*/)
{
    handleAlphaTest(transparencyBox->currentText());
}

void ControlPanel::handleBlandBoxChanged(QString)
{
    auto strBox1 = blendBox1->currentText();
    auto strBox2 = blendBox2->currentText();
    currentFigure->setBlenderTest(getDigit(strBox1), getDigit(strBox2));
}

void ControlPanel::handleScissorSliderTriggered(int)
{
    currentFigure->setScissorTest(xSlider->value(), ySlider->value(), wSlider->value(), hSlider->value());
    xSlider->setToolTip(QString("x = %1").arg(xSlider->value()));
    ySlider->setToolTip(QString("y = %1").arg(ySlider->value()));
    wSlider->setToolTip(QString("w = %1").arg(wSlider->value()));
    hSlider->setToolTip(QString("h = %1").arg(hSlider->value()));
}

QString ControlPanel::getString(GLuint dig)
{
    switch (dig){

    case (GL_ZERO):
        return "GL_ZERO";
    case (GL_ONE):
        return "GL_ONE";
    case (GL_DST_COLOR):
        return "GL_DST_COLOR";
    case (GL_ONE_MINUS_DST_COLOR):
        return "GL_ONE_MINUS_DST_COLOR";
    case (GL_SRC_ALPHA):
        return "GL_SRC_ALPHA";
    case (GL_ONE_MINUS_SRC_ALPHA):
        return "GL_ONE_MINUS_SRC_ALPHA";
    case (GL_DST_ALPHA):
        return "GL_DST_ALPHA";
    case (GL_ONE_MINUS_DST_ALPHA):
        return "GL_ONE_MINUS_DST_ALPHA";
    case (GL_SRC_ALPHA_SATURATE):
        return "GL_SRC_ALPHA_SATURATE";
    case (GL_SRC_COLOR):
        return "GL_SRC_COLOR";
    case (GL_ONE_MINUS_SRC_COLOR):
        return "GL_ONE_MINUS_SRC_COLOR";

    // alpha
    case (GL_NEVER):
        return "GL_NEVER";
    case (GL_LESS):
        return "GL_LESS";
    case (GL_EQUAL):
        return "GL_EQUAL";
    case (GL_LEQUAL):
        return "GL_LEQUAL";
    case (GL_GREATER):
        return "GL_GREATER";
    case (GL_NOTEQUAL):
        return "GL_NOTEQUAL";
    case (GL_GEQUAL):
        return "GL_GEQUAL";
    case (GL_ALWAYS):
        return "GL_ALWAYS";
    default:
        return "";
    }
}

 GLuint ControlPanel::getDigit(QString str)
{
    // blender
    if (str == "GL_ZERO")
        return GL_ZERO;
    if (str == "GL_ONE")
        return GL_ONE;
    if (str == "GL_DST_COLOR")
        return GL_DST_COLOR;
    if (str == "GL_ONE_MINUS_DST_COLOR")
        return GL_ONE_MINUS_DST_COLOR;
    if (str == "GL_SRC_ALPHA")
        return GL_SRC_ALPHA;
    if (str == "GL_ONE_MINUS_SRC_ALPHA")
        return GL_ONE_MINUS_SRC_ALPHA;
    if (str == "GL_DST_ALPHA")
        return GL_DST_ALPHA;
    if (str == "GL_ONE_MINUS_DST_ALPHA")
        return GL_ONE_MINUS_DST_ALPHA;
    if (str == "GL_SRC_ALPHA_SATURATE")
        return GL_SRC_ALPHA_SATURATE;
    if (str == "GL_SRC_COLOR")
        return GL_SRC_COLOR;
    if (str == "GL_ONE_MINUS_SRC_COLOR")
        return GL_ONE_MINUS_SRC_COLOR;

    // alpha
    if (str == "GL_NEVER")
        return GL_NEVER;
    if (str == "GL_LESS")
        return GL_LESS;
    if (str == "GL_EQUAL")
        return GL_EQUAL;
    if (str == "GL_LEQUAL")
        return GL_LEQUAL;
    if (str == "GL_GREATER")
        return GL_GREATER;
    if (str == "GL_NOTEQUAL")
        return GL_NOTEQUAL;
    if (str == "GL_GEQUAL")
        return GL_GEQUAL;
    if (str == "GL_ALWAYS")
        return GL_ALWAYS;

    return -1;
}
