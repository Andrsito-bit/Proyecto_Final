#include "jugador.h"
#include <QKeyEvent>

Jugador::Jugador() {
    x = 50;
    y = 300;
    vidas = 5; // Configuración inicial de vidas
    hojaSprites.load(":/sprites.png");
    QPixmap sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite.scaled(60, 60));
    setPos(x, y);

    setFlag(QGraphicsItem::ItemIsFocusable); // Hacer que el jugador sea focuseable
    setFocus(); // Asignar el foco al jugador
}

void Jugador::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        movimiento(-5, 0);
        setSprite(60); // Izquierda
        break;
    case Qt::Key_D:
        movimiento(5, 0);
        setSprite(120); // Derecha
        break;
    case Qt::Key_W:
        movimiento(0, -5);
        setSprite(180); // Arriba
        break;
    case Qt::Key_S:
        movimiento(0, 5);
        setSprite(0);   // Abajo
        break;
    case Qt::Key_Space: // Disparar proyectil
        dispararProyectil();
        break;
    }
}

void Jugador::setSprite(int dir) {
    spriteY = dir;
    spriteX = 60 * cont;
    QPixmap sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite.scaled(60, 60));
    cont = (cont + 1) % 7; // Avanzar en la animación
}

void Jugador::dispararProyectil() {
    // Verifica que la escena exista antes de agregar el proyectil
    if (scene()) {
        ProyectilJugador *proyectil = new ProyectilJugador(pos().x() + spriteAncho / 2, pos().y());
        scene()->addItem(proyectil);
    }
}


void Jugador::movimiento(int dx, int dy)
{
    // Definir los límites de la pantalla (asumiendo 800x600)
    const double limiteIzquierdo = 0.0;
    const double limiteDerecho = 700.0;
    const double limiteSuperior = 450.0;
    const double limiteInferior = 540.0;

    // Actualizar posición con límites
    x = qMax(limiteIzquierdo, qMin(limiteDerecho, x + dx));
    y = qMax(limiteSuperior, qMin(limiteInferior, y + dy));
    setPos(x, y);
}
