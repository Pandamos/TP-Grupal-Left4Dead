#ifndef ARMA_H
#define ARMA_H

#include <cstdint>

/*
    Clase abstracta de la que todas las armas heredan
*/
class arma {
    private:
    uint32_t balas_restantes;

    public:
    arma();
    virtual void disparar() = 0;
    virtual void ataque_secundario() = 0;
    virtual void recargar();
};

#endif //ARMA_H