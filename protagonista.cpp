#include "protagonista.h"

Protagonista::Protagonista() : invulnerabilidadTimer(new QTimer(this)) {
    connect(invulnerabilidadTimer, &QTimer::timeout, this, &Protagonista::desactivarInvulnerabilidad);
}

Protagonista::~Protagonista() {
    delete invulnerabilidadTimer;
}


void Protagonista::recibirDanio(int dan) {
    if (invulnerable) return;

    vidas = vidas-dan;
    if (vidas <= 0) {
        emit protagonistaMuerto();
    } else {
        activarInvulnerabilidad(2000); // 2 segundos de invulnerabilidad
    }
}

void Protagonista::activarInvulnerabilidad(int duracion) {
    invulnerable = true;
    setOpacity(0.5); // Indicador visual
    invulnerabilidadTimer->start(duracion);
}

void Protagonista::desactivarInvulnerabilidad() {
    invulnerable = false;
    setOpacity(1.0);
    invulnerabilidadTimer->stop();
}
