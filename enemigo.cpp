#include "enemigo.h"
# include <windows.h>
#include "QKeyEvent"

Enemigo::Enemigo() {
    int altura = 200;
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/Flight.png");
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite);
    setSprite(0);
    timerMov = new QTimer(this);
    connect(timerMov, &QTimer::timeout, this, [=]() {
        movimiento(altura);
    });
}




void Enemigo::setSprite(int dir){

    spriteY = dir;
    spriteX = 150*cont;
    QPixmap sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite);
    cont++;
    if(cont==8){cont=0;}
}


void Enemigo::movimiento(int altura)
{


}

