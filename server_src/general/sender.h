/*
    ARME ESTA CLASE POR LAS DUDAS, NO SE SI LA VAMOS A USAR O SI USAMOS CLIENT DIRECTAMENTE
*/

#ifndef SENDER_H_
#define SENDER_H_

class sender /*: public Thread*/ {
    private:
    //protocolo& request;
    //Queue<GameState_DTO>* queue_player;

    public:
    sender();
    /*
        Esta funcion 
            1. hace try_pop de la queue_player
            2. si no levanta nada, no envia nada... sigue? busy wait?
            3. si levanta algo, es un nuevo game_state_dto para mandar por el socket
            4. llama a request.send_game_state(Game_State_DTO)
    */
    //virtual void run() override;
};
#endif //SENDER_H_
