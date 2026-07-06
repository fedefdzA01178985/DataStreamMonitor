#ifndef EVIDENCIA2_MONITOR_H
#define EVIDENCIA2_MONITOR_H

#include <string>

#include "Sensor.h"
#include "Alerta.h"

class Monitor {
private:
    //Arreglo para guardar 10 apuntadores de Sensores
    Sensor* sensores[10];
    int cantidadSensores; // Contador de Sensores

    //Arreglo para guardar hasta 50 objetos Alerta
    Alerta alertas[50];
    int cantidadAlertas; // Contador de Alertas

    std::string nombreSistema;

public:
    Monitor(std::string nombre);

    std::string getNombreSistema();
    void setNombreSistema(std::string n);

    void agregarSensor(Sensor* s);
    void ejecutarCiclo();
    void generarReporte();

};

#endif //EVIDENCIA2_MONITOR_H
