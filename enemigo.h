#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "qobject.h"
#include "QGraphicsPixmapItem"
#include "proyectil1.h" // Incluimos la clase Proyectil
#include <QTimer>

class Enemigo : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

private:
    int spriteX = 0;
    int spriteY = 150;
    int spriteAncho = 150;
    int spriteAlto = 150;
    QPixmap sprite;
    QPixmap hojaSprites;
    int cont = 0;
    int vida = 10; // Vida del enemigo
    QTimer *timerMov;
    QTimer *timerDisparo;

public:
    Enemigo();
    void setSprite();
    void reducirVida(int dano); // Nuevo método para recibir daño

signals:
    void enemigoMuerto();

public slots:
    void disparar();
};

#endif // ENEMIGO_H

