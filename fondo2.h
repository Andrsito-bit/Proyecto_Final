#ifndef FONDO2_H
#define FONDO2_H

#include <QObject>
#include "QGraphicsPixmapItem"

class fondo2 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int spriteX = 0;
    int spriteY = 176;
    int spriteAncho = 416;
    int spriteAlto = 176;
    QPixmap sprite;
    QPixmap hojaSprites;

public:
    fondo2();
};

#endif // FONDO2_H
