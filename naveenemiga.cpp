#include "naveenemiga.h"
#include "bala.h"
#include <QGraphicsScene>

EnemigoNave::EnemigoNave() {
    hojaSprites.load(":/enemy-medium.png");
    setPixmap(hojaSprites.copy(0, 0, 32, 16).scaled(64, 32)); // Frame inicial
    setPos(300, 50);

    // Temporizador para disparar balas
    QTimer *timerDisparo = new QTimer(this);
    connect(timerDisparo, &QTimer::timeout, this, &EnemigoNave::disparar);
    timerDisparo->start(1500); // Dispara cada 1.5 segundos
}

void EnemigoNave::disparar() {
    Bala *bala = new Bala(x() + pixmap().width() / 2 - 8, y() + pixmap().height());
    scene()->addItem(bala);
}


