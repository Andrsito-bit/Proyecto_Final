// proyectil1.h
#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include <QPixmap>

class Proyectil : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

private:
    qreal velocidadX;       // Velocidad en X
    qreal velocidadY;       // Velocidad en Y
    qreal gravedad;         // Gravedad
    QTimer *timerMovimiento; // Timer para mover el proyectil
    QTimer *timerAnimacion;  // Timer para la animación
    QPixmap spriteSheet;     // Hoja de sprites del proyectil
    int cuadroActual;        // Cuadro actual de la animación
    int anchoCuadro;         // Ancho de cada cuadro de la animación
    int altoCuadro;          // Alto de cada cuadro de la animación

public:
    Proyectil(qreal startX, qreal startY, qreal vX, qreal vY, QObject *parent = nullptr);
    ~Proyectil();

public slots:
    void actualizarPosicion();
    void actualizarAnimacion();
};

#endif // PROYECTIL_H
