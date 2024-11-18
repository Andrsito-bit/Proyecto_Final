#ifndef ENEMIGO_NAVE_H
#define ENEMIGO_NAVE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "bala.h"

class EnemigoNave : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    QPixmap hojaSprites;
    int spriteX = 0;
    int vidas = 3;


public:
    EnemigoNave();


public slots:
    void disparar();

};

#endif // ENEMIGO_NAVE_H
