#include "witch.h"

bool witch::witch_puede_gritar() {
    //verificacion probabilistica (?) de si la bruja puede gritar ahora
    //si es asi, return true -- else return false
    return false;
}

void gritar() {
    //genera m'as infectdos
    //cuantos? no se especifica en el enunciado
}

void witch::moverse(uint32_t nueva_posX, uint32_t nueva_posY) {
    //chequea si puede moverse
    //  si puede, lo hace --> no tiene movimiento especial, se mueve a velocidad normal
    //  si no puede, se queda parada? cambia de direccion? Enunciado no aclara, decision nuestra de disenio

}
    
void witch::atacar(soldado& soldado) {
    //if (witch_puede_gritar)
        //gritar();
    
    //no se especifica como ataca la bruja, o si solo grita...
    //podemos asumir que la bruja no lastima (mas facil)
    //o que si nos paramos "cerca", la bruja nos saca danio

    //if (soldado_cerca())
        //daniar_soldado(DANIO_WITCH)
}