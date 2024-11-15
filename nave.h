#ifndef NAVE_H
#define NAVE_H

#include "qobject.h"
#include "QGraphicsPixmapItem"


class nave : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    qreal x =200;
    qreal y =200;
    int spriteX = 0;
    int spriteY = 0;
    int spriteAncho = 16;
    int spriteAlto = 24;
    QPixmap sprite;
    QPixmap hojaSprites;
    int cont = 0;
    int vidas = 5;
    QTimer *timerMov;


public:
    nave();
    void keyPressEvent(QKeyEvent *event) override;
    void movimiento(int dx, int dy);
    void contador_vidas();
    void setSprite(int dir);
};

#endif // NAVE_H
