#ifndef SPEAR_H
#define SPEAR_H

#include "enemigo.h"

class spear : public enemigo {
    public:
    /*
        Recibe la nueva x e y
        Verifica si es una pos v'alida (no hay nadie ahi parado, no se va del mapa, no hay un obstaculo)
        Si no puede, no se mueve
        Si puede, se mueve
    */
    virtual void moverse(uint32_t nueva_posX, uint32_t nueva_posY) override;
    
    /*
        Recibe el soldado que va a ser atacado (podria decidir que soldado atacar aca adentro tambien...)
        Se verifica si puede gritar o no. Si puede, lo hace; si no puede, seguimos de largo.
    */
    virtual void atacar(soldado& soldado) override;
};

#endif //SPEAR_H