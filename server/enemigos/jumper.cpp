#include "jumper.h"

void jumper::moverse(uint32_t nueva_posX, uint32_t nueva_posY) {
    //aca saltamos as'i que no verificamos si hay obstaculos en el medio,
    //el jumper los salta (decision de disenio nuestra, les va?)

    //se mueve a la nueva posicion
    //hace danio si en esa posicion hay un soldado (porque le cae encima) <-- esto en atacar, aca no tengo la data del soldado
}

void jumper::atacar(soldado& soldado) {\
    //no se especifica de que otra forma el jumper ataca.
    //si el jumper solo ataca saltando encima de alguien, aca deberiamos llamar a moverse
    //y luego a atacar (?)


    // algo asi
    //moverse(soldado.posX, soldado.posY);
    //soldado.daniar(DANIO_JUMPER)
}