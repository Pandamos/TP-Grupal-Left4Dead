#ifndef WITCH_H
#define WITCH_H

#include "enemigo.h"

class witch : public Enemigo {
    private:
    void gritar();

    /*
        En esta funci'on, se define si en esta iteracion, la bruja puede gritar o no.
        Si lo hace, se devuelve true. Si no lo hace, se devuelve false.
    */
    bool witch_puede_gritar();

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
        Bruja ataca
    */
    virtual void atacar(soldado& soldado) override;
};

#endif //WITCH_H