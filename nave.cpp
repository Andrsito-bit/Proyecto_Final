#include "nave.h"
#include "QKeyEvent"

nave::nave()
{
    x = 200;
    y = 200;
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/ship.png");
    sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite.scaled(80, 80));
    setPos(x, y);
}

void nave::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_A:
        movimiento(-5, 0);
        setSprite(0);
        break;
    case Qt::Key_D:
        movimiento(5, 0);
        setSprite(0);
        break;
    case Qt::Key_W:
        movimiento(0, -5);
        setSprite(0);
        break;
    case Qt::Key_S:
        movimiento(0, 5);
        setSprite(0);
        break;
    default:
        QGraphicsItem::keyPressEvent(event);
    }
}

void nave::movimiento(int dx, int dy)
{
    // Lógica de límites ajustada
    x = qMax(0.0, qMin(784.0, x + dx));
    y = qMax(0.0, qMin(584.0, y + dy));
    setPos(x, y);
}

void nave::setSprite(int dir)
{
    spriteY = dir;
    spriteX = 16 * cont;
    QPixmap sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite.scaled(80, 80));
    cont = (cont + 1) % 5; // Animación cíclica
}
