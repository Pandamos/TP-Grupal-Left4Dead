#ifndef SOLDADO_H
#define SOLDADO_H

#include <cstdint>
#include "arma.h"
//#include "enemigo.h" //<-- implica un include circular

class soldado {
    private:
    uint32_t vida;
    uint32_t posX;
    uint32_t posY;
    //arma arma; //<-- no le gusta que sea una clase virtual lpm

    public:
    explicit soldado(uint32_t vida_inicial, uint32_t posX_inicial, uint32_t posY_inicial) : 
        vida(vida_inicial), posX(posX_inicial), posY(posY_inicial) { }
    void moverse(uint32_t nueva_posX, uint32_t nueva_posY);
    //void atacar(enemigo enemigo);

};

#endif //SOLDADO_H