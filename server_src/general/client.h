#ifndef CLIENT_H_
#define CLIENT_H_

class client /*: public Thread */{
    private:
    //protocol request;
    
    public:
    client();

    /*
        En este run se verifica si el cliente quiere joinear una partida existente
        o si se quiere crear una nueva partida

        se ejecuta el codigo necesario para cada caso.
    */
    //virtual void run() override;
};

#endif //CLIENT_H_
