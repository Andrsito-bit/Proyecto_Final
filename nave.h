#ifndef NAVE_H
#define NAVE_H

#include "protagonista.h"

class Nave : public Protagonista {
    Q_OBJECT

private:
    int spriteX = 0;
    int spriteY = 0;
    int spriteAncho = 16;
    int spriteAlto = 24;
    int cont = 0;

public:
    Nave();
    ~Nave();
    void keyPressEvent(QKeyEvent *event) override;
    void setSprite(int dir);
    void movimiento(int dx,int dy);

public slots:
    void detectarColisiones();
};

#endif // NAVE_H
