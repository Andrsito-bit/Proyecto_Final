#ifndef JUGADOR_H
#define JUGADOR_H

#include "qobject.h"
#include "QGraphicsPixmapItem"



class Jugador:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    qreal x =200;
    qreal y =200;
    int spriteX = 0;
    int spriteY = 120;
    int spriteAncho = 60;
    int spriteAlto = 60;
    QPixmap sprite;
    QPixmap hojaSprites;
    int cont = 0;
    int vidas = 5;
    QTimer *timerMov;


public:
    Jugador();
    void keyPressEvent(QKeyEvent *event) override;
    void movimiento(int dx, int dy);

    void contador_vidas();

    void setSprite(int dir);

};

#endif // JUGADOR_H
