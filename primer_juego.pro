QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Jugador.cpp \
    asteroide.cpp \
    bala.cpp \
    enemigo.cpp \
    enemigoesquivable.cpp \
    fondo.cpp \
    fondo2.cpp \
    main.cpp \
    mainwindow.cpp \
    nave.cpp \
    naveenemiga.cpp \
    protagonista.cpp \
    proyectil1.cpp \
    proyectil_jugador.cpp

HEADERS += \
    Jugador.h \
    asteroide.h \
    bala.h \
    enemigo.h \
    enemigoesquivable.h \
    fondo.h \
    fondo2.h \
    mainwindow.h \
    nave.h \
    naveenemiga.h \
    protagonista.h \
    proyectil1.h \
    proyectil_jugador.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    Sprites.pro

RESOURCES += \
    sprites.qrc

DISTFILES +=
