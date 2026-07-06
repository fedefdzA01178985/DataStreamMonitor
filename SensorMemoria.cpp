#include "SensorMemoria.h"
#include <iostream>
#include <cstdlib>

//Como es una simulacion no va leer los datos de la computadora
// Sino va simular lo el consumo de RAM hipotetico

// Inicializacion

SensorMemoria::SensorMemoria(float u) : Sensor("Memoria", u) {
    memoriaUsada = 0.0; // Inicializa en 0
}

float SensorMemoria::medirMetrica() {
    memoriaUsada = rand() % 101; // Simula consumo de RAM de 0% a 100%
    return memoriaUsada;        // Regresa el valor directo al Monitor
}

void SensorMemoria::imprimirDatos() {
    std::cout << "Sensor Memoria -> RAM Usada: " << memoriaUsada
              << "% | Umbral Configurado: " << getUmbral() << "%" << std::endl;
}

float SensorMemoria::getMemoriaUsada() {
    return memoriaUsada;
}

bool SensorMemoria::operator== (const SensorMemoria& s) {
    return (this->memoriaUsada == s.memoriaUsada);
}