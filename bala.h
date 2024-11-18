#ifndef BALA_H
#define BALA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Bala : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit Bala(qreal startX, qreal startY);

public slots:
    void mover();
};

#endif // BALA_H
