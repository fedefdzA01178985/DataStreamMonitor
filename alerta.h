#ifndef EVIDENCIA2_ALERTA_H
#define EVIDENCIA2_ALERTA_H

#include <iostream>
#include <string>

class Alerta {
private:
    std::string nivel;
    std::string mensaje;
    float valorRegistrado;

public:
    Alerta();
    // Constructor
    Alerta(std::string n, std::string m, float v);

    // Getters
    std::string getNivel();
    std::string getMensaje();
    float getValorRegistrado();

    // Sobrecarga de igualdad
    bool operator==(const Alerta& otra) const;
};

#endif //EVIDENCIA2_ALERTA_H
