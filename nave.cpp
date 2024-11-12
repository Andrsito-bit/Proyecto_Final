#include "nave.h"
#include "QKeyEvent"

nave::nave()

{    x = 200;
    y = 200;
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/ship.png");
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite.scaled(80,80));
    setPos(x,y);
}

void nave::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_A:
        movimiento(-5,0);

        spriteY = 0;
        spriteX = 16*cont;
        sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
        setPixmap(sprite.scaled(80,80));
        cont++;
        if(cont==5){cont=0;}
        break;

    case Qt::Key_D:
        movimiento(5,0);
        spriteY = 0;
        spriteX = 16*cont;
        sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
        setPixmap(sprite.scaled(80,80));
        cont++;
        if(cont==5){cont=0;}
        break;


    case Qt::Key_W:
        movimiento(0,-5);
        spriteY = 0;
        spriteX = 16*cont;
        sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
        setPixmap(sprite.scaled(80,80));
        cont++;
        if(cont==5){cont=0;}

        break;
    case Qt::Key_S:
        movimiento(0,5);

        spriteY = 0;
        spriteX = 16*cont;
        sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
        setPixmap(sprite.scaled(80,80));
        cont++;
        if(cont==5){cont=0;}

        break;
    default:
        QGraphicsItem::keyPressEvent(event);
    }
}
void nave::movimiento(int dx, int dy){
    if(x+16 > 800){
        x =784;
    }
    if(y+16 > 600){
        y =584;
    }
    if(x < 0){
        x = 0;
    }
    if(y < 0){
        y =0;
    }
    x += dx;
    y += dy;
    setPos(x,y);
}

void nave::setSprite(int dir){

    spriteY = dir;
    spriteX = 16*cont;
    QPixmap sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite);
    cont++;
    if(cont==5){cont=0;}

}

