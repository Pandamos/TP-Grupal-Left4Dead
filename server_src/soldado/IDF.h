#ifndef IDF_H
#define IDF_H

#include "arma.h"

class IDF : public arma {
    public:
    virtual void disparar()override;
    virtual void ataque_secundario() override;
    virtual void recargar();
};

#endif //IDF_H