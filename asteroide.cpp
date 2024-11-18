#include "asteroide.h"
#include <QtGlobal> // Para números aleatorios

Asteroide::Asteroide(QObject *parent)
    : QObject(parent) {
    // Configurar imagen del asteroide
    setPixmap(QPixmap(":/asteroid.png").scaled(50, 50));

    // Generar velocidad aleatoria
    velocidadX = (rand() % 7 + 1) * (rand() % 2 == 0 ? 1 : -1); // -7 a 7
    velocidadY = (rand() % 7 + 1) * (rand() % 2 == 0 ? 1 : -1); // -7 a 7

    // Conectar un temporizador para mover el asteroide
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Asteroide::mover);
    timer->start(50);
}

void Asteroide::mover() {
    // Mover el asteroide
    setPos(x() + velocidadX, y() + velocidadY);

    // Rebotar en las paredes
    if (x() <= 0 || x() + boundingRect().width() >= scene()->width()) {
        velocidadX = -velocidadX;
    }
    if (y() <= 0 || y() + boundingRect().height() >= scene()->height()) {
        velocidadY = -velocidadY;
    }
}
