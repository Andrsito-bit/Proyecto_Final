#include "nave.h"
#include "asteroide.h"
#include "bala.h"
#include <QKeyEvent>
#include <QGraphicsScene>

Nave::Nave() {
    x = 200;
    y = 200;
    vidas = 5;
    hojaSprites.load(":/ship.png");
    QPixmap sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite.scaled(80, 80));
    setPos(x, y);

    setFlag(QGraphicsItem::ItemIsFocusable); // Hacer que la nave sea focuseable
    setFocus(); // Asignar el foco a la nave

    // Temporizador para colisiones
    QTimer *timerColisiones = new QTimer(this);
    connect(timerColisiones, &QTimer::timeout, this, &Nave::detectarColisiones);
    timerColisiones->start(50);
}

Nave::~Nave() {
    // Destructor explícito
}

void Nave::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        movimiento(-20, 0);
        setSprite(0);
        break;
    case Qt::Key_D:
        movimiento(20, 0);
        setSprite(0);
        break;
    case Qt::Key_W:
        movimiento(0, -20);
        setSprite(0);
        break;
    case Qt::Key_S:
        movimiento(0, 20);
        setSprite(0);
        break;
    default:
        QGraphicsItem::keyPressEvent(event);
    }
}



void Nave::movimiento(int dx, int dy)
{
    // Lógica de límites ajustada
    x = qMax(0.0, qMin(784.0, x + dx));
    y = qMax(0.0, qMin(584.0, y + dy));
    setPos(x, y);
}







void Nave::setSprite(int dir) {
    spriteY = dir;
    spriteX = 16 * cont;
    QPixmap sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite.scaled(80, 80));
    cont = (cont + 1) % 5;
}

void Nave::detectarColisiones() {
    QList<QGraphicsItem *> itemsColisionados = collidingItems();
    for (auto item : itemsColisionados) {
        if (dynamic_cast<Asteroide *>(item)) {
            recibirDanio(1);
            break;
        }
        if (dynamic_cast<Bala *>(item)) {
            recibirDanio(1);
            scene()->removeItem(item);
            delete item;
            break;
        }
    }
}

