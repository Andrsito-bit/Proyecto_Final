// proyectil.cpp
#include "proyectil1.h"
#include <QGraphicsScene>
#include <QList>
#include "Jugador.h" // Asegúrate de incluir el header del jugador para colisiones

Proyectil::Proyectil(qreal startX, qreal startY, qreal vX, qreal vY, QObject *parent)
    : QObject(parent), velocidadX(vX), velocidadY(vY), gravedad(0.5), cuadroActual(0), anchoCuadro(48), altoCuadro(48) {

    // Cargar el sprite sheet completo
    spriteSheet.load(":/projectile_sprite.png");

    // Configurar el primer cuadro del sprite
    setPixmap(spriteSheet.copy(cuadroActual * anchoCuadro, 0, anchoCuadro, altoCuadro));
    setPos(startX, startY);

    // Temporizador para actualizar la posición del proyectil
    timerMovimiento = new QTimer(this);
    connect(timerMovimiento, &QTimer::timeout, this, &Proyectil::actualizarPosicion);
    timerMovimiento->start(30); // Actualización cada 30 ms

    // Temporizador para la animación
    timerAnimacion = new QTimer(this);
    connect(timerAnimacion, &QTimer::timeout, this, &Proyectil::actualizarAnimacion);
    timerAnimacion->start(100); // Cambiar cuadro cada 100 ms
}

Proyectil::~Proyectil() {
    delete timerMovimiento;
    delete timerAnimacion;
}

void Proyectil::actualizarPosicion() {
    // Actualizar la posición usando la física de una parábola
    setPos(x() + velocidadX, y() + velocidadY);
    velocidadY += gravedad; // Aumenta la velocidad en Y debido a la gravedad

    // Verificar colisiones con otros objetos
    QList<QGraphicsItem *> colisiones = collidingItems();
    for (auto &objeto : colisiones) {
        if (dynamic_cast<Jugador *>(objeto)) {
            // Si colisiona con el jugador, puedes reducir su vida o aplicar daño
            scene()->removeItem(this); // Eliminar proyectil de la escena
            delete this;
            return;
        }
    }

    // Eliminar el proyectil si sale de la escena
    if (y() > scene()->height() || x() < 0 || x() > scene()->width()) {
        scene()->removeItem(this);
        delete this;
    }
}

void Proyectil::actualizarAnimacion() {
    // Cambiar al siguiente cuadro de la animación
    cuadroActual = (cuadroActual + 1) % 8; // Hay 8 cuadros en el sprite
    setPixmap(spriteSheet.copy(cuadroActual * anchoCuadro, 0, anchoCuadro, altoCuadro));
}
