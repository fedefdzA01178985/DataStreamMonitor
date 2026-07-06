#include "SensorRed.h"
#include <iostream>
#include <cstdlib>

// Como es una simulacion, se van a usar datos generados random

SensorRed::SensorRed(float u) : Sensor("Red", u) {
    trafico = 0.0;
}

float SensorRed::medirMetrica() {
    trafico = rand() % 101; // Simula consumo de RAM de 0% a 100%
    return trafico;        // Regresa el valor directo al Monitor
}

void SensorRed::imprimirDatos() {
    std::cout << "Sensor Red -> Trafico Actual: " << trafico
              << " MB/s | Umbral Configurado: " << getUmbral() << " MB/s" << std::endl;
}

float SensorRed::getTrafico() {
    return trafico;
}

bool SensorRed::operator== (const SensorRed& s) {
    return (this->trafico == s.trafico);
}