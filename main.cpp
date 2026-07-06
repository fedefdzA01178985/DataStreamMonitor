#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Monitor.h"
#include "SensorCPU.h"
#include "SensorMemoria.h"
#include "SensorRed.h"

int main() {
    // Inicializamos la semilla para los números aleatorios (rand)
    std::srand(std::time(nullptr));

    std::cout << "====================================================" << std::endl;
    std::cout << "                  DATA STREAM MONITOR               " << std::endl;
    std::cout << "====================================================\n" << std::endl;

    // Caso 1: Crear objetos de las clases derivadas y mostrar sus datos con imprimirDatos().
    std::cout << ">>> CASO 1: Creando objetos derivados y mostrando datos" << std::endl;
    SensorCPU cpuPrototipo(75.0);       // Umbral de 75%
    SensorMemoria ramPrototipo(80.0);   // Umbral de 80%
    SensorRed redPrototipo(50.0);       // Umbral de 50 MB/s

    cpuPrototipo.medirMetrica();
    ramPrototipo.medirMetrica();
    redPrototipo.medirMetrica();

    std::cout << "Datos iniciales de los sensores:" << std::endl;
    cpuPrototipo.imprimirDatos();
    ramPrototipo.imprimirDatos();
    redPrototipo.imprimirDatos();

    // Si el valor actual del CPU, RAM o Red, llegan a exceder al Umbral se debe que no hay una alerta registrada
    // El codigo con Alertas se utiliza en el Caos #3

    std::cout << "----------------------------------------------------\n" << std::endl;


    // -------------------------------------------------------------------------
    // CASO 2: Calcular valores específicos usando métodos sobrescritos
    // -------------------------------------------------------------------------
    std::cout << ">>> CASO 2: Calculando metricas con metodos sobrescritos (.medirMetrica())" << std::endl;
    // Llamamos directamente a la versión sobrescrita de cada clase
    float valorCPU = cpuPrototipo.medirMetrica();
    float valorRAM = ramPrototipo.medirMetrica();

    std::cout << "Metrica calculada individualmente para CPU: " << valorCPU << "%" << std::endl;
    std::cout << "Metrica calculada individualmente para RAM: " << valorRAM << "%" << std::endl;
    std::cout << "----------------------------------------------------\n" << std::endl;


    // -------------------------------------------------------------------------
    // CASO 3: Demostrar polimorfismo recorriendo un arreglo de apuntadores
    // -------------------------------------------------------------------------
    std::cout << ">>> CASO 3: Demostrando polimorfismo con el Monitor" << std::endl;
    Monitor miMonitor("Server-DataCenter-01");

    // Creamos sensores dinámicos (apuntadores) para meterlos al Monitor
    Sensor* cpuServidor = new SensorCPU(70.0);     // Umbral 70%
    Sensor* ramServidor = new SensorMemoria(85.0); // Umbral 85%
    Sensor* redServidor = new SensorRed(60.0);     // Umbral 60 MB/s

    // Los agregamos al arreglo polimorfico del monitor (Sensor* sensores[10])
    miMonitor.agregarSensor(cpuServidor);
    miMonitor.agregarSensor(ramServidor);
    miMonitor.agregarSensor(redServidor);

    // Ejecutamos ciclos de monitoreo. Internamente recorre el arreglo con un for
    // y manda a llamar a medirMetrica() e imprimirDatos() de forma polimorfica.
    miMonitor.ejecutarCiclo();
    miMonitor.ejecutarCiclo(); // Lo corremos dos veces para simular el paso del tiempo

    // Mostramos el reporte global de alertas generadas
    miMonitor.generarReporte();
    std::cout << "----------------------------------------------------\n" << std::endl;


    // -------------------------------------------------------------------------
    // CASO 4: Usar la sobrecarga de operadores (comparar dos objetos)
    // -------------------------------------------------------------------------
    std::cout << ">>> CASO 4: Usando la sobrecarga de operadores (==)" << std::endl;
    SensorCPU cpuA(50.0);
    SensorCPU cpuB(50.0);

    // Forzamos a que tengan el mismo valor de carga actual para probar la igualdad
    cpuA.medirMetrica();
    // Hacemos que cpuB simule hasta que sea igual a cpuA para demostrar el operador
    // O simplemente creamos dos objetos estáticos para comparar sus estados.
    std::cout << "Comparando si cpuA tiene la misma carga actual que cpuB..." << std::endl;

    if (cpuA == cpuB) {
        std::cout << "Resultado: Ambos sensores de CPU tienen exactamente la misma carga." << std::endl;
    } else {
        std::cout << "Resultado: Los sensores de CPU tienen cargas distintas actuales." << std::endl;
    }
    std::cout << "====================================================" << std::endl;


    // Limpieza de memoria dinámica por buena práctica
    delete cpuServidor;
    delete ramServidor;
    delete redServidor;

    return 0;
}