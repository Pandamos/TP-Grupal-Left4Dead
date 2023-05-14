#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <cstdint>

#include "../soldado/soldado.h"

/*
    Clase abstracta de la que todos los enemigos heredan
*/
class Enemigo {
    private:
    uint32_t vida;

    //reemplazar por clase Point
    uint32_t posX;
    uint32_t posY;

    public:
    explicit Enemigo(uint32_t vida_inicial, uint32_t posX_inicial, uint32_t posY_inicial) : 
        vida(vida_inicial), posX(posX_inicial), posY(posY_inicial) { }

    virtual bool nueva_posicion_es_valida(uint32_t nueva_posX, uint32_t nueva_posY) { return false; }
    virtual void moverse(uint32_t nueva_posX, uint32_t nueva_posY) = 0;
    virtual void atacar(soldado& soldado) = 0;

    /*
        Posible loop del enemigo
            Chequea si en range de ataque hay soldado a atacar.
            Si hay, ataca a alguno
            Si no hay, busca con la mirada. 
                Si encuentra, se mueve hacia el.
                Si no encuentra, se mueve a cualquier direccion.
    */
};

#endif //ENEMIGO_H