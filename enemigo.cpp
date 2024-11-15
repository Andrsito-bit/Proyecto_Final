// enemigo.cpp
#include "enemigo.h"
#include "proyectil1.h" // Incluimos la clase Proyectil
#include <QGraphicsScene>

Enemigo::Enemigo() {
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/Flight.png");
    sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite.scaled(300,300));
    setSprite();

    timerMov = new QTimer(this);
    connect(timerMov, &QTimer::timeout, this, &Enemigo::setSprite);
    timerMov->start(100);

    timerDisparo = new QTimer(this);
    connect(timerDisparo, &QTimer::timeout, this, &Enemigo::disparar);
    timerDisparo->start(700); // Dispara cada 2 segundos
}

void Enemigo::setSprite() {
    spriteY = 0;
    spriteX = 150 * cont;
    QPixmap sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite.scaled(300,300));
    cont++;
    if (cont == 8) { cont = 0; }
}

void Enemigo::disparar() {
    Proyectil *proyectil = new Proyectil(x()+spriteAncho, y() + spriteAlto / 2, -5, -10); // Dispara hacia la izquierda y ligeramente hacia arriba
    scene()->addItem(proyectil); // Añadir el proyectil a la escena

    Proyectil *proyectil2 = new Proyectil(x()+spriteAncho, y() + spriteAlto / 2, 5, -10); // Dispara hacia la izquierda y ligeramente hacia arriba
    scene()->addItem(proyectil2); // Añadir el proyectil a la escena
}
