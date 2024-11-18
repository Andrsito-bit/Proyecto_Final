#include "enemigo.h"
#include "proyectil1.h"
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
    timerDisparo->start(800);
}

void Enemigo::setSprite() {
    spriteY = 0;
    spriteX = 150 * cont;
    QPixmap sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite.scaled(300,300));
    cont = (cont + 1) % 8;
}

void Enemigo::disparar() {
    Proyectil *proyectil = new Proyectil(x() + spriteAncho, y() + spriteAlto / 2, -5, -10);
    scene()->addItem(proyectil);
    Proyectil *proyectil2 = new Proyectil(x() + spriteAncho, y() + spriteAlto / 2, 5, -10);
    scene()->addItem(proyectil2);
}

void Enemigo::reducirVida(int dano) {
    vida -= dano;
    if (vida <= 0) {
        emit enemigoMuerto(); // Notifica que el enemigo ha muerto
    }
}
