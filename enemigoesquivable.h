#ifndef ENEMIGOESQUIVABLE_H
#define ENEMIGOESQUIVABLE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QtMath> // Para funciones trigonométricas

class EnemigoEsquivable : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    EnemigoEsquivable(qreal startX, qreal startY, QObject *parent = nullptr);
    ~EnemigoEsquivable();

    void setSize(int width, int height); // Cambiar tamaño del enemigo

signals:
    void colisionConJugador(); // Emitir cuando colisiona con el jugador

private slots:
    void mover();           // Cambiar la posición del enemigo
    void actualizarSprite(); // Cambiar el cuadro de animación

private:
    enum Movimiento { LINEA_RECTA, ONDA }; // Tipos de movimiento
    Movimiento tipoMovimiento;
    qreal velocidadX;    // Velocidad horizontal
    qreal velocidadY;    // Velocidad vertical
    qreal amplitudOnda;  // Amplitud de la onda para el movimiento sinusoidal
    qreal anguloOnda;    // Ángulo para la función seno
    qreal direccion;     // Dirección (-1 = izquierda, 1 = derecha)

    QPixmap spriteSheet; // Hoja de sprites
    QTimer *timerMovimiento; // Temporizador para el movimiento
    QTimer *timerAnimacion;  // Temporizador para la animación
    int cuadroActual;        // Cuadro actual de la animación
    int anchoCuadro;         // Ancho de cada cuadro en el sprite
    int altoCuadro;          // Alto de cada cuadro en el sprite
};

#endif // ENEMIGOESQUIVABLE_H
