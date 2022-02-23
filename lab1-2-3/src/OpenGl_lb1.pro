QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Figure/bezier.cpp \
    Figure/cube.cpp \
    Figure/ifigure.cpp \
    Figure/line.cpp \
    Figure/polygon.cpp \
    Figure/pyramide.cpp \
    Figure/triangle.cpp \
    controlpanel.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Figure/bezier.h \
    Figure/cube.h \
    Figure/ifigure.h \
    Figure/line.h \
    Figure/polygon.h \
    Figure/pyramide.h \
    Figure/triangle.h \
    controlpanel.h \
    mainwindow.h

TRANSLATIONS += \
    OpenGl_lb1_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
