#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "jugador.h"
#include "enemigo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mov_enem();
    void limpiarEscena();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void volverSeleccionNiveles();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QTimer *timer;
    int cont;
    Enemigo *enem1;
    Jugador *jug1; // Guardar el puntero a Jugador para conectar señales
};

#endif // MAINWINDOW_H
