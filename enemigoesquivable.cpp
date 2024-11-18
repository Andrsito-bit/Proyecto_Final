#include "enemigoesquivable.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <Jugador.h>

EnemigoEsquivable::EnemigoEsquivable(qreal startX, qreal startY, QObject *parent)
    : QObject(parent), velocidadX(6.0), velocidadY(0.0), amplitudOnda(5.0), anguloOnda(0.0), direccion(-1),
    anchoCuadro(57), altoCuadro(42), cuadroActual(0) {

    // Cargar el sprite
    spriteSheet.load(":/alien-enemy-walk.png");
    setPixmap(spriteSheet.copy(0, 0, anchoCuadro, altoCuadro));
    setPos(startX, startY);

    if (direccion < 0) {
        QTransform transform;
        transform.scale(-1, 1); // Voltear horizontalmente
        setTransform(transform);
    }

    tipoMovimiento = (QRandomGenerator::global()->bounded(2) == 0) ? LINEA_RECTA : ONDA;

    timerMovimiento = new QTimer(this);
    connect(timerMovimiento, &QTimer::timeout, this, &EnemigoEsquivable::mover);
    timerMovimiento->start(30);

    timerAnimacion = new QTimer(this);
    connect(timerAnimacion, &QTimer::timeout, this, &EnemigoEsquivable::actualizarSprite);
    timerAnimacion->start(100);
}

EnemigoEsquivable::~EnemigoEsquivable() {
    delete timerMovimiento;
    delete timerAnimacion;
}

void EnemigoEsquivable::mover() {
    qreal nuevoX = x();
    qreal nuevoY = y();

    if (tipoMovimiento == LINEA_RECTA) {
        nuevoX += direccion * velocidadX;
    } else if (tipoMovimiento == ONDA) {
        nuevoX += direccion * velocidadX;
        nuevoY = y() + amplitudOnda * qSin(anguloOnda);
        anguloOnda += 0.1;
    }

    if (nuevoX < 0 || nuevoX + anchoCuadro > 800) {
        direccion *= -1;
        QTransform transform;
        transform.scale(direccion, 1);
        setTransform(transform);

        tipoMovimiento = (QRandomGenerator::global()->bounded(2) == 0) ? LINEA_RECTA : ONDA;


    }

    setPos(nuevoX, nuevoY);

    QList<QGraphicsItem *> colisiones = collidingItems();
    for (auto &objeto : colisiones) {
        Jugador *jugador = dynamic_cast<Jugador *>(objeto);
        if (jugador) {
            jugador->recibirDanio(1); // Reduce la vida del jugador
            return;
        }
    }
}

void EnemigoEsquivable::actualizarSprite() {
    cuadroActual = (cuadroActual + 1) % 6;
    setPixmap(spriteSheet.copy(cuadroActual * anchoCuadro, 0, anchoCuadro, altoCuadro));
}

void EnemigoEsquivable::setSize(int width, int height) {
    anchoCuadro = width;
    altoCuadro = height;
    setPixmap(spriteSheet.copy(0, 0, anchoCuadro, altoCuadro));
}

