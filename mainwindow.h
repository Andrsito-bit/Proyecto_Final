#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "QGraphicsPixmapItem"
#include "enemigo.h"
#include "QGraphicsRectItem"
#include "fondo.h"
#include "fondo2.h"
#include "nave.h"

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
    void on_pushButton_2_clicked();
    void mov_enem();
    void on_pushButton_clicked();

private:
    void limpiarEscena();  // Nueva función para limpiar la escena

    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGraphicsScene *escena;
    QTimer *timer;
    int cont;
    Enemigo *enem1;
};
#endif // MAINWINDOW_H

