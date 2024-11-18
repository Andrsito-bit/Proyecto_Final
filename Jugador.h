#ifndef JUGADOR_H
#define JUGADOR_H

#include "protagonista.h"
#include "proyectil_jugador.h"
#include <QGraphicsScene>

class Jugador : public Protagonista {
    Q_OBJECT

private:
    int spriteX = 0;
    int spriteY = 120;
    int spriteAncho = 60;
    int spriteAlto = 60;
    int cont = 0;

public:
    Jugador();
    void keyPressEvent(QKeyEvent *event) override;
    void setSprite(int dir);
    void movimiento(int dx,int dy);

private:
    void dispararProyectil();

signals:
    void jugadorMuerto(); // Señal emitida si el jugador pierde todas sus vidas
};

#endif // JUGADOR_H

