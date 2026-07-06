#include "SensorCPU.h"
#include <iostream>
#include <cstdlib> // Para generar números aleatorios (rand)
// Como es una simulación de que si leyera los datos de mi compu, o de computadoras en general
// Por proposito de este proyecto se van a generar numeros aleatorios

// IMPLEMENTACION

// --- Constructor ---
// Como el diagrama no pide "nombre" en los parámetros, nosotros se lo mandamos
// directamente a la clase base Sensor como "CPU" de forma interna.
SensorCPU::SensorCPU(float u) : Sensor("CPU", u) {
    cargaCPU = 0.0; // Inicializa en 0
}

float SensorCPU::medirMetrica() {
    cargaCPU = rand() % 101;
    return cargaCPU;
}

void SensorCPU::imprimirDatos() {
    // getUmbral() va a traer el 75.0 que le asignaste en el main
    std::cout << "Sensor CPU -> Carga Actual: " << cargaCPU
              << "% | Umbral Configurado: " << getUmbral() << "%" << std::endl;
}

float SensorCPU::getCargaCPU() {
    return cargaCPU;
}

bool SensorCPU::operator== (const SensorCPU& s) const {
    return (this->cargaCPU == s.cargaCPU);
}
