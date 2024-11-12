#include "Jugador.h"
#include "QKeyEvent"

Jugador::Jugador()
{
    x = 200;
    y = 200;
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/sprites.png");
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite.scaled(40,40));
}

void Jugador::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_A:
        movimiento(-5,0);
        setSprite(60);
        break;
    case Qt::Key_D:
        movimiento(5,0);
        setSprite(120);
        break;
    case Qt::Key_W:
        movimiento(0,-5);
        setSprite(180);
        break;
    case Qt::Key_S:
        movimiento(0,5);
        setSprite(0);
        break;

    default:
        QGraphicsItem::keyPressEvent(event);
    }
}

void Jugador::movimiento(int dx, int dy){
    if(x+60 > 1024){
        x =964;
    }
    if(y+60 > 600){
        y =540;
    }
    if(x < 0){
        x = 0;
    }
    if(y < 440){
        y =440;
    }
    x += dx;
    y += dy;
    setPos(x,y);
}

void Jugador::setSprite(int dir){

    spriteY = dir;
    spriteX = 60*cont;
    QPixmap sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite);
    cont++;
    if(cont==7){cont=0;}

}
