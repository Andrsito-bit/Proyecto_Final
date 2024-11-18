#ifndef PROTAGONISTA_H
#define PROTAGONISTA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include <QTimer>

class Protagonista : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

protected:
    qreal x = 0;
    qreal y = 0;
    int vidas;
    bool invulnerable = false;
    QPixmap hojaSprites;
    QTimer *invulnerabilidadTimer;

public:
    Protagonista();
    virtual ~Protagonista();
    virtual void recibirDanio(int dan);
    int getVidas() const { return vidas; }
    bool isInvulnerable() const { return invulnerable; }

protected:
    void activarInvulnerabilidad(int duracion);
    void desactivarInvulnerabilidad();

signals:
    void protagonistaMuerto();
};

#endif // PROTAGONISTA_H
