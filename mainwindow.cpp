#include "mainwindow.h"
#include "Jugador.h"
#include "ui_mainwindow.h"
#include "QGraphicsPixmapItem"
#include "enemigo.h"
#include "fondo.h"
#include "fondo2.h"
#include "nave.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene();
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0, 0, 800, 600);
    cont = 0;

    // Inicializar el temporizador solo una vez
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(mov_enem()));
}

void MainWindow::limpiarEscena()
{
    escena->clear();

    if (timer->isActive()) {
        timer->stop();
    }
    cont = 0;
}

void MainWindow::on_pushButton_clicked()
{
    limpiarEscena();
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);

    fondo *fond1 = new fondo();
    escena->addItem(fond1);

    Jugador *jug1 = new Jugador();
    escena->addItem(jug1);
    jug1->setFocus();  // Asegura que el jugador tenga el foco para recibir eventos de teclado
    jug1->setPos(100, 500);

    enem1 = new Enemigo();
    escena->addItem(enem1);
    enem1->setPos(0, 100);

    timer->start(100);
}

void MainWindow::mov_enem()
{
    if (enem1) {
        int newX = enem1->x() + ((cont % 2 == 0) ? 5 : -5); // Movimiento ida y vuelta
        enem1->setPos(newX, enem1->y());

        // Cambiar dirección si alcanza el borde
        if (newX <= 0 || newX >= 700) {
            cont++; // Cambia la dirección
        }
        enem1->setSprite();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    limpiarEscena();
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);

    fondo2 *fond2 = new fondo2();
    escena->addItem(fond2);

    nave *nav1 = new nave();
    escena->addItem(nav1);
    nav1->setFocus();
    nav1->setPos(200, 200);
}

MainWindow::~MainWindow()
{
    delete ui;
}


