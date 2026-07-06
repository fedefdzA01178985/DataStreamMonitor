#include "Alerta.h"

// IMPLEMENTACION DE LA CLASE ALERTA

// Constructor
Alerta::Alerta() {
    nivel = "INFO";
    mensaje = "";
    valorRegistrado = 0.0;
}

Alerta::Alerta(std::string n, std::string m, float v) {
    nivel = n;
    mensaje = m;
    valorRegistrado = v;

}

// Getters
std::string Alerta::getNivel() {
    return nivel;

}

std::string Alerta::getMensaje() {
    return mensaje;

}

float Alerta::getValorRegistrado() {
    return valorRegistrado;

}

// --- Sobrecarga de igualdad ---
bool Alerta::operator==(const Alerta& otra) const {
    if (nivel == otra.nivel && mensaje == otra.mensaje && valorRegistrado == otra.valorRegistrado) {
        return true;
    } else {
        return false;
    }
}