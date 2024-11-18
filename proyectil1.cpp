#include "proyectil1.h"
#include <QGraphicsScene>
#include <QList>
#include "Jugador.h"

Proyectil::Proyectil(qreal startX, qreal startY, qreal vX, qreal vY, QObject *parent)
    : QObject(parent), velocidadX(vX), velocidadY(vY), gravedad(0.5), cuadroActual(0), anchoCuadro(48), altoCuadro(48) {
    spriteSheet.load(":/projectile_sprite.png");
    setPixmap(spriteSheet.copy(cuadroActual * anchoCuadro, 0, anchoCuadro, altoCuadro));
    setPos(startX, startY);

    timerMovimiento = new QTimer(this);
    connect(timerMovimiento, &QTimer::timeout, this, &Proyectil::actualizarPosicion);
    timerMovimiento->start(30);

    timerAnimacion = new QTimer(this);
    connect(timerAnimacion, &QTimer::timeout, this, &Proyectil::actualizarAnimacion);
    timerAnimacion->start(100);
}

Proyectil::~Proyectil() {
    delete timerMovimiento;
    delete timerAnimacion;
}

void Proyectil::actualizarPosicion() {
    setPos(x() + velocidadX, y() + velocidadY);
    velocidadY += gravedad;

    QList<QGraphicsItem *> colisiones = collidingItems();
    for (auto &objeto : colisiones) {
        Jugador *jugador = dynamic_cast<Jugador *>(objeto);
        if (jugador) {
            jugador->recibirDanio(5); // Reduce la vida del jugador
            return;
        }
    }

    if (y() > scene()->height() || x() < 0 || x() > scene()->width()) {
        scene()->removeItem(this);
        delete this;
    }
}

void Proyectil::actualizarAnimacion() {
    cuadroActual = (cuadroActual + 1) % 8;
    setPixmap(spriteSheet.copy(cuadroActual * anchoCuadro, 0, anchoCuadro, altoCuadro));
}
