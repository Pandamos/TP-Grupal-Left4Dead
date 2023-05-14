#ifndef COMMON_SRC_COMMON_BUFFER_H_
#define COMMON_SRC_COMMON_BUFFER_H_
class Buffer;

#include <vector>
#include <string>
#include <cstdint>
#include "common_socket_dipa.h"

class Buffer {
    private:
    Buffer(const Buffer &other) = delete;
    Buffer operator=(const Buffer &other) = delete;

    protected:
    unsigned int index;
    unsigned int read_index;
    std::vector<char> data;

    public:
    Buffer();

    Buffer(Buffer&&);
    Buffer& operator=(Buffer&&);

    void clear();
    void push_byte(const char value);
    void push_short(const uint16_t value);
    void push_uint(const uint32_t value);
    void push_message(const std::string &value);
    char get_byte();
    uint16_t get_short();
    uint32_t get_uint();
    std::string get_message(const uint16_t size);

    // Estas funciones estan para mantener privados los atributos del buffer
    // Y para centralizar y no repetir el codigo
    // encargado de envio de informacion por el socket
    virtual bool send_by(const Socket *skt) const;
    virtual bool read_from(Socket *skt, unsigned int msgSize);
};
#endif  // COMMON_SRC_COMMON_BUFFER_H_
