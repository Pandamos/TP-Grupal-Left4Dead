#ifndef PARTIDA_H_
#define PARTIDA_H_

class partida /*: public Thread */{
    private:
    //Queue<action>* queue_partida;
    //std::vector<Queue<GameState_DTO> queues_clients; ???
    
    public:
    partida();

    /*
        Aca voy a tnener un loop asi
        1. try_pop() // porque no quiero que el timer se pare si no hya nada que poppear, el tiempo deberia seguir pasando
        2. actualizo_modelo
        3. pusheo nuevo modelo a queues de clientes (o lo hago luego de x cantidad de poppeos?)
    */
    //virtual void run() override;
};

#endif //PARTIDA_H_
