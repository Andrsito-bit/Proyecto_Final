#include "proyectil_jugador.h"
#include "enemigo.h"
#include <QGraphicsScene>

ProyectilJugador::ProyectilJugador(int startX, int startY, int velocidad)
    : velocidad(velocidad), cuadroActual(0) {
    setPos(startX, startY);
    hojaSprites = QPixmap(":/hit.png");
    actualizarSprite();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ProyectilJugador::mover);
    timer->start(50);
}

ProyectilJugador::~ProyectilJugador() {
    if (timer->isActive()) {
        timer->stop();
    }
    delete timer;
}

void ProyectilJugador::mover() {
    setPos(x(), y() + velocidad);

    QList<QGraphicsItem *> colisiones = collidingItems();
    for (auto &objeto : colisiones) {
        Enemigo *enemigo = dynamic_cast<Enemigo *>(objeto);
        if (enemigo) {
            delete this;
            enemigo->reducirVida(1); // Reduce la vida del jugador
            return;
        }
    }

    if (y() < 0) {
        scene()->removeItem(this);
        delete this;
        return;
    }

    actualizarSprite();
}

void ProyectilJugador::actualizarSprite() {
    QPixmap cuadro = hojaSprites.copy(cuadroActual * 15, 0, 20, 16); // Cada cuadro es de 20x16
    setPixmap(cuadro);
    cuadroActual++;
    if (cuadroActual >= 4){cuadroActual = 0;}    // Cambia entre 4 cuadros
}
