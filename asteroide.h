#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class Asteroide : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit Asteroide(QObject *parent = nullptr);

private slots:
    void mover();

private:
    qreal velocidadX; // Velocidad en el eje X
    qreal velocidadY; // Velocidad en el eje Y
};

#endif // ASTEROIDE_H
