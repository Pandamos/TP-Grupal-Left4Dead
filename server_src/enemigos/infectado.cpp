#include "infectado.h"

void infectado::moverse(uint32_t nueva_posX, uint32_t nueva_posY) {
    //el infectado puede caminar o correr (or exclusivo)
    //se tiene que verificar que el camino a la nueva pos sea posible en todo momento (no?)

    //si el camino a la nueva pos es posible en todo momento
    //if (!nueva_posicion_es_valida(nueva_posX, nueva_posY))
        //el infectado no se mueve

    //if (puede_correr)
        // mmmmmm pero si puede correr, en el mismo tiempo deberia llegar mas lejos
        // o en menos tiempo llegar a la nueva pos
    //else
        // como distingo aca si puede correr o no? cambia la pos 
        //(porque el t es cte) o cambia el t (porque la pos es cte)?
}

void infectado::atacar(soldado& soldado) {
    //baja el danio estandar del soldado
    //soldado.bajar_vida(DANIO_INFECTADO)
}