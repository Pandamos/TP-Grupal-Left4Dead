#ifndef PRINTER_H_
#define PRINTER_H_

#include <mutex>
#include <string>
#include <iostream>

struct printer {
    public:
    /* 
        Recibido el mensaje, toma el mutex e imprime
        lo necesario por consola, sin problemas de RC
    */
    static void print(const std::string& msg) {
        std::mutex static printer_mutex;
        std::lock_guard<std::mutex> lock(printer_mutex);
        std::cout << msg << std::endl;
    }
};
#endif
