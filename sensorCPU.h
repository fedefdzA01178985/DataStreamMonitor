#ifndef EVIDENCIA2_SENSORCPU_H
#define EVIDENCIA2_SENSORCPU_H

#include "Sensor.h"

class SensorCPU : public Sensor {
private:
    float cargaCPU;

public:
    SensorCPU(float u);
    float medirMetrica() override;
    void imprimirDatos();
    float getCargaCPU();
    bool operator==(const SensorCPU& s) const;
};

#endif //EVIDENCIA2_SENSORCPU_H
