#include "fondo.h"

fondo::fondo()
{
    hojaSprites.load(":/cyberpunk-corridor-PREVIEW.png");

    // Ajuste de la imagen al tamaño de la ventana  sin escalado
    setPixmap(hojaSprites.scaled(800, 600, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    setPos(0, 0); // Coloca el fondo en la esquina superior izquierda
}
