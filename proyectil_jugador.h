#ifndef PROYECTILJUGADOR_H
#define PROYECTILJUGADOR_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QPixmap>

class ProyectilJugador : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    ProyectilJugador(int startX, int startY, int velocidad = -10);
    ~ProyectilJugador();

public slots:
    void mover();

private:
    void actualizarSprite(); // Método para actualizar el cuadro de animación

    int velocidad; // Velocidad de movimiento del proyectil
    int cuadroActual = 0; // Cuadro actual de la animación
    QPixmap hojaSprites; // Hoja de sprites que contiene la animación
    QTimer *timer; // Temporizador para el movimiento y la animación
};

#endif // PROYECTILJUGADOR_H
