#include "Monitor.h"
#include <iostream>
#include <string>

// IMPLEMENTACION

Monitor::Monitor(std::string nombre) {
    nombreSistema = nombre;
    cantidadSensores = 0;
    cantidadAlertas = 0;
}

// Getters

std::string Monitor::getNombreSistema() {
    return nombreSistema;
}

void Monitor::setNombreSistema(std::string n) {
    nombreSistema = n;
}

// Agregar Sensor

void Monitor::agregarSensor(Sensor* s) {
    if (cantidadSensores < 10) {
        sensores[cantidadSensores] = s; // Guardamos el apuntador del sensor
        cantidadSensores++;             // Aumentamos el contador
    } else {
        std::cout << "Error: No se pueden agregar mas sensores al monitor." << std::endl;
    }
}

// Ejecutar Ciclo
void Monitor::ejecutarCiclo() {
    std::cout << "=== Ejecutando ciclo de monitoreo para: " << nombreSistema << " ===" << std::endl;

    // Medire los valores de todos los sensores mediante polimorfismo y genera una alerta si alguno supera su umbral configurado.
    for (int i = 0; i < cantidadSensores; i++) {
        float valor = sensores[i]->medirMetrica();

        std::cout << "Sensor [" << sensores[i]->getNombre() << "] midio: " << valor << std::endl;

        // Comparo si el valor supera el umbral del sensor
        if (valor > sensores[i]->getUmbral()) {
            // Si el arreglo de alertas no está lleno, puedo crear una nueva alerta
            if (cantidadAlertas < 50) {
                // Creo un objeto Alerta y lo guardamos
                Alerta nuevaAlerta("CRITICO", "El valor supero el umbral tolerado", valor);
                alertas[cantidadAlertas] = nuevaAlerta;
                cantidadAlertas++;

                std::cout << " -> ALERTA GENERADA en " << sensores[i]->getNombre() << "!" << std::endl;
            }
        }
    }
    std::cout << "====================================================\n" << std::endl;
}

// Generar Reporte
void Monitor::generarReporte() {
    // Genero un reporte para mostrar las alertas registradas usando un for loop para revisar el numero de alertas
    std::cout << "====== REPORTE DE ALERTAS - SISTEMA: " << nombreSistema << " ======" << std::endl;
    std::cout << "Total de alertas registradas: " << cantidadAlertas << std::endl;

    if (cantidadAlertas == 0) {
        std::cout << "Todo bajo control. No se detectaron anomalias." << std::endl;
    } else {
        // Recorremos y mostramos cada alerta usando su getter
        for (int i = 0; i < cantidadAlertas; i++) {
            std::cout << "Alerta " << (i + 1) << " -> Nivel: " << alertas[i].getNivel()
                      << " | Mensaje: " << alertas[i].getMensaje()
                      << " | Valor: " << alertas[i].getValorRegistrado() << std::endl;
        }
    }
    std::cout << "============================================================\n" << std::endl;
}