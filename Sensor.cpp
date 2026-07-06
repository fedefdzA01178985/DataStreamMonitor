#include "Sensor.h"

// IMPLEMENTACION

//Constructor

Sensor::Sensor(std::string n, float u) {
    nombre = n;
    umbral = u;
    valorActual = 0.0; // Lo iniciamos en cero por seguridad
}

// Getters

std::string Sensor::getNombre() {
    return nombre;
}

float Sensor::getUmbral() {
    return umbral;
}

// Setters

void Sensor::setUmbral(float u) {
    umbral = u;
}

void Sensor::setNombre(std::string n) {
    nombre = n;
}

// Imprimir Datos

void Sensor::imprimirDatos() {
    std::cout << "Sensor: " << nombre << " | Umbral configurado: " << umbral << " | Ultimo valor: " << valorActual << std::endl;
}