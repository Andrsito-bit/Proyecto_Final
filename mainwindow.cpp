#include "mainwindow.h"
#include "Jugador.h"
#include "ui_mainwindow.h"
#include "QGraphicsPixmapItem"
#include "enemigo.h"
#include "QGraphicsRectItem"
#include "fondo.h"
#include "fondo2.h"
#include "nave.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 800, 600);  // Ajusta la escena al nuevo tamaño

    QGraphicsView *view = new QGraphicsView(this);
    view->resize(800, 600);
    view->setScene(escena);

    fondo *fond1 = new fondo();
    escena->addItem(fond1);

    Jugador *jug1 = new Jugador();
    escena->addItem(jug1);
    jug1->setPos(200,200);

    Enemigo *enem1 = new Enemigo();
    escena->addItem(enem1);
    enem1->setPos(200,200);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{




}


void MainWindow::on_pushButton_2_clicked()
{
    fondo2 *fond2 = new fondo2();
    escena->addItem(fond2);

    nave *nav1 = new nave();
    escena->addItem(nav1);
    nav1->setPos(200,200);




}





