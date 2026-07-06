#ifndef EVIDENCIA2_SENSORMEMORIA_H
#define EVIDENCIA2_SENSORMEMORIA_H

#include "sensor.h"

class SensorMemoria : public Sensor {
private:
    float memoriaUsada;
public:
    SensorMemoria(float u);
    float medirMetrica() override;
    void imprimirDatos();
    float getMemoriaUsada();
    bool operator==(const SensorMemoria& s);
};

#endif //EVIDENCIA2_SENSORMEMORIA_H
