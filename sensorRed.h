#ifndef EVIDENCIA2_SENSORRED_H
#define EVIDENCIA2_SENSORRED_H

#include "sensor.h"

class SensorRed: public Sensor {
private:
    float trafico;
public:
    SensorRed(float u);
    float medirMetrica() override;
    void imprimirDatos();
    float getTrafico();
    bool operator==(const SensorRed& s);
};

#endif //EVIDENCIA2_SENSORRED_H
