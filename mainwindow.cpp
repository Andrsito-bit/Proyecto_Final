#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fondo.h"
#include "fondo2.h"
#include "nave.h"
#include "enemigoesquivable.h"
#include "asteroide.h"
#include "naveenemiga.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene();
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0, 0, 800, 600);
    cont = 0;

    // Cargar la imagen de fondo inicial
    QPixmap fondoInicio(":/homer_back.PNG");
    QGraphicsPixmapItem *fondoItem = new QGraphicsPixmapItem(fondoInicio.scaled(800, 600, Qt::KeepAspectRatioByExpanding));
    escena->addItem(fondoItem);
    fondoItem->setZValue(-1); // Asegurar que el fondo esté detrás de los botones

    // Temporizador para el movimiento
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(mov_enem()));
}

void MainWindow::limpiarEscena() {
    escena->clear();

    if (timer->isActive()) {
        timer->stop();
    }

}

void MainWindow::on_pushButton_clicked()
{
    // Cargar el nivel 1 con el fondo y los personajes adecuados
    limpiarEscena();
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);

    // Agregar fondo para el nivel 1
    fondo *fond1 = new fondo();
    escena->addItem(fond1);

    // Crear y agregar al jugador en el nivel 1
    jug1 = new Jugador();
    escena->addItem(jug1);
    jug1->setFocus(); // Enfocar para recibir teclas
    jug1->setPos(100, 500);

    // Crear y agregar al enemigo esquivable en el nivel 1
    EnemigoEsquivable *enemigoEsquivable = new EnemigoEsquivable(0, 470);
    escena->addItem(enemigoEsquivable);

    // Crear y agregar al enemigo regular en el nivel 1
    enem1 = new Enemigo();
    escena->addItem(enem1);
    enem1->setPos(0, 100);


    // Conectar señales de muerte para regresar al menú solo en el nivel 1
    connect(jug1, &Jugador::protagonistaMuerto, this, &MainWindow::volverSeleccionNiveles);
    connect(enem1, &Enemigo::enemigoMuerto, this, &MainWindow::volverSeleccionNiveles);

    // Conectar la colisión del enemigo esquivable con el jugador
    connect(enemigoEsquivable, &EnemigoEsquivable::colisionConJugador, this, [this]() {
        if (jug1) {
            jug1->recibirDanio(1);
        }
    });

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

void MainWindow::on_pushButton_2_clicked() {
    limpiarEscena();
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);

    fondo2 *fond2 = new fondo2();
    escena->addItem(fond2);

    Nave *nav1 = new Nave();
    escena->addItem(nav1);
    nav1->setFocus();
    nav1->setPos(200, 200);

    for (int i = 0; i < 4; ++i) {
        Asteroide *asteroide = new Asteroide();
        asteroide->setPos(rand() % 700 + 50, rand() % 300 + 50);
        escena->addItem(asteroide);
    }

    EnemigoNave *enemigo = new EnemigoNave();
    enemigo->setPos(150, 50);
    escena->addItem(enemigo);

    EnemigoNave *enemigo2 = new EnemigoNave();
    enemigo2->setPos(600, 50);
    escena->addItem(enemigo2);

    connect(nav1, &Nave::protagonistaMuerto, this, &MainWindow::volverSeleccionNiveles); // Conectar señal
}


void MainWindow::volverSeleccionNiveles() {
    limpiarEscena();
    ui->pushButton->setVisible(true);  // Botón para seleccionar nivel 1
    ui->pushButton_2->setVisible(true);  // Botón para seleccionar nivel 2
    QPixmap fondoInicio(":/homer_back.PNG");
    QGraphicsPixmapItem *fondoItem = new QGraphicsPixmapItem(fondoInicio.scaled(800, 600, Qt::KeepAspectRatioByExpanding));
    escena->addItem(fondoItem);
    fondoItem->setZValue(-1); // Asegurar que el fondo esté detrás de los botones

}

MainWindow::~MainWindow()
{
    delete ui;
}
