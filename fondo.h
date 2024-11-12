#ifndef FONDO_H
#define FONDO_H

#include <QObject>
#include "QGraphicsPixmapItem"

class fondo : public QObject, public QGraphicsPixmapItem
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
    fondo();

};

#endif // FONDO_H
