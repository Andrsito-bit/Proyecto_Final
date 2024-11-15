// enemigo.h
#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "qobject.h"
#include "QGraphicsPixmapItem"
#include "proyectil1.h" // Incluimos la clase Proyectil
#include <QTimer>

class Enemigo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int spriteX = 0;
    int spriteY = 150;
    int spriteAncho = 150;
    int spriteAlto = 150;
    QPixmap sprite;
    QPixmap hojaSprites;
    int cont = 0;
    int vida = 5;
    int movimiento_x = 0;
    QTimer *timerMov;
    QTimer *timerDisparo; // Nuevo temporizador para disparos

public:
    Enemigo();
    void setSprite();
    void vidas();

public slots:
    void disparar(); // Nuevo slot para disparar proyectiles
};

#endif // ENEMIGO_H
