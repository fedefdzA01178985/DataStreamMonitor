#ifndef EVIDENCIA2_SENSOR_H
#define EVIDENCIA2_SENSOR_H

#include <iostream>
#include <string>

class Sensor {
private:
    std::string nombre;
    float umbral;
    float valorActual;

public:
    Sensor(std::string nombre, float umbral);
    virtual float medirMetrica() = 0;
    void imprimirDatos();

    std::string getNombre();
    float getUmbral();

    void setUmbral(float u);
    void setNombre(std::string n);
};

#endif //EVIDENCIA2_SENSOR_H
