#include "bala.h"

Bala::Bala(qreal startX, qreal startY) {
    setPixmap(QPixmap(":/laser-bolts3.png").scaled(32, 32));
    setPos(startX, startY);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bala::mover);
    timer->start(50);
}

void Bala::mover() {
    setY(y() + 10); // Mover hacia abajo
    if (y() > 600) { // Fuera de la pantalla
        delete this;
    }
}
