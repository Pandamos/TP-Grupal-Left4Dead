#include "common_buffer.h"
#include <arpa/inet.h>
#include <iostream>
#include <iomanip>
#include <utility>

Buffer::Buffer() : index(0), read_index(0) {
}

Buffer::Buffer(Buffer&& other) {
    this->index = other.index;
    this->read_index = other.read_index;
    this->data = std::move(other.data);
    other.index = 0;
    other.read_index = 0;
}

Buffer& Buffer::operator=(Buffer&& other) {
    if (this == &other)
        return *this;

    this->index = other.index;
    this->read_index = other.read_index;
    this->data = std::move(other.data);
    other.index = 0;
    other.read_index = 0;
    return *this;
}

void Buffer::clear() {
    this->index = 0;
    this->read_index = 0;
    this->data.clear();
}

void Buffer::push_byte(const char value) {
    this->data.push_back(value);
    this->index++;
}

void Buffer::push_short(const uint16_t value) {
    uint16_t transfer = htons(value);
    char* hostval = reinterpret_cast<char*>(&transfer);
    this->data.push_back(hostval[0]);
    this->data.push_back(hostval[1]);
    this->index += 2;
}

void Buffer::push_message(const std::string &value) {
    this->push_short(value.size());

    for (auto letter : value)
        this->data.push_back(letter);
    this->index += value.size();
}

void Buffer::push_uint(const uint32_t value) {
    uint32_t transfer = htonl(value);
    char* vals = reinterpret_cast<char*>(&transfer);
    this->data.push_back(vals[0]);
    this->data.push_back(vals[1]);
    this->data.push_back(vals[2]);
    this->data.push_back(vals[3]);
    this->index += 4;
}

char Buffer::get_byte() {
    return this->data[this->index++];
}

uint16_t Buffer::get_short() {
    uint16_t value = ((this->data[this->index+1] << 8) & 0xff00)
                    | (this->data[this->index] & 0x00ff);
    this->index += 2;
    return ntohs(value);
}

std::string Buffer::get_message(const uint16_t size) {
    std::string message;
    message.resize(size);
    
    for (uint16_t i = 0; i < size; i++)
        message[i] = this->data[this->index+i];
    this->index += size;
    return message;
}

uint32_t Buffer::get_uint() {
    uint32_t value = *reinterpret_cast<uint32_t*>(&this->data[this->index]);
    this->index += 4;
    return ntohl(value);
}

// Estas funciones estan para mantener privados los atributos del buffer
// Y para centralizar y no repetir el codigo
// encargado de envio de informacion por el socket
bool Buffer::send_by(const Socket *skt) const {
    bool was_closed = false;
    skt->sendall(&this->data[0], this->index, &was_closed);
    return !was_closed;
}

bool Buffer::read_from(Socket *skt, unsigned int msgSize) {
    if (this->data.size() < (this->read_index + msgSize)) {
        this->data.resize(this->read_index + msgSize);
    }

    bool was_closed = false;
    skt->recvall(&this->data[this->read_index], msgSize, &was_closed);
    this->read_index += msgSize;
    return !was_closed;
}
