# Data Stream Monitor

Simulador de un sistema de monitoreo de recursos de cómputo (CPU, memoria RAM y tráfico de red), inspirado en herramientas como el Administrador de Tareas. El sistema aplica umbrales configurables por componente y genera alertas automáticas cuando alguno de ellos se excede.

> Proyecto desarrollado para la materia **Programación Orientada a Objetos (TC1030.306)** — Tecnológico de Monterrey.

## Descripción

En entornos con producción de software o centros de datos, monitorear el estado de los recursos del sistema es indispensable para garantizar el máximo rendimiento posible. **Data Stream Monitor** simula ese proceso: administra distintos sensores (CPU, memoria y red), cada uno con un umbral configurado por un administrador, y evalúa continuamente si el valor medido supera dicho umbral. Cuando esto ocurre, se genera una alerta con nivel de criticidad, mensaje y valor registrado.

Por limitaciones de alcance del proyecto, los datos se generan de forma simulada (aleatoria) en lugar de leerse de hardware real; sin embargo, el diseño está pensado para poder extenderse a mediciones reales en el futuro sin modificar la lógica central del sistema.

## Funcionalidades

- Monitoreo de tres tipos de componentes: **CPU**, **Memoria RAM** y **Red**.
- Umbrales configurables de forma independiente para cada sensor.
- Generación automática de alertas cuando un valor medido supera su umbral.
- Reporte de alertas por sistema, incluyendo nivel, mensaje y valor registrado.
- Comparación de sensores mediante sobrecarga del operador `==`.
- Simulación polimórfica de múltiples sensores gestionados por una sola clase `Monitor`.

## Diseño orientado a objetos

El proyecto aplica los pilares fundamentales de POO en C++:

| Concepto | Aplicación en el proyecto |
|---|---|
| **Clases abstractas** | `Sensor` es una clase abstracta con la función virtual pura `medirMetrica()`, lo que impide instanciar un sensor genérico y obliga a cada subclase a implementar su propia lógica de medición. |
| **Herencia** | `SensorCPU`, `SensorMemoria` y `SensorRed` heredan públicamente de `Sensor`, reutilizando atributos y métodos comunes (nombre, umbral, valor actual). |
| **Polimorfismo** | `Monitor` almacena punteros a `Sensor` y ejecuta `medirMetrica()` sobre cada uno sin conocer su tipo concreto; la vtable de C++ resuelve la llamada correcta en tiempo de ejecución. |
| **Composición** | `Monitor` contiene arreglos de `Sensor` y `Alerta` (no hereda de ellos), respetando el principio de "componer antes que heredar". |
| **Encapsulamiento** | Atributos como `nombre`, `umbral`, `valorActual`, `cargaCPU`, `memoriaUsada` y `trafico` son privados, accesibles solo mediante getters/setters. |
| **Sobrecarga de operadores** | `operator==` implementado en `SensorCPU`, `SensorMemoria` y `Alerta` para comparar objetos según criterios específicos de igualdad. |

### Diagrama de clases (UML)

![Diagrama UML](DiagramaUML.png)

### Clases principales

| Clase | Función |
|---|---|
| `Sensor` (abstracta) | Modelo base para cualquier sensor derivado; define la interfaz común. |
| `SensorCPU` | Simula y reporta el porcentaje de uso de CPU. |
| `SensorMemoria` | Simula y reporta el porcentaje de uso de RAM. |
| `SensorRed` | Simula y reporta el tráfico de red en MB/s. |
| `Alerta` | Encapsula un evento de umbral superado (nivel, mensaje, valor). |
| `Monitor` | Administra los sensores, ejecuta ciclos de monitoreo y genera reportes de alertas. |

## Ejemplo de ejecución

```
====================================================
                DATA STREAM MONITOR
====================================================

>>> CASO 1: Creando objetos derivados y mostrando datos
Datos iniciales de los sensores:
Sensor CPU -> Carga Actual: 37% | Umbral Configurado: 75%
Sensor Memoria -> RAM Usada: 32% | Umbral Configurado: 80%
Sensor Red -> Trafico Actual: 21 MB/s | Umbral Configurado: 50 MB/s
----------------------------------------------------

>>> CASO 2: Calculando metricas con metodos sobrescritos (.medirMetrica())
Metrica calculada individualmente para CPU: 50%
Metrica calculada individualmente para RAM: 60%
----------------------------------------------------

>>> CASO 3: Demostrando polimorfismo con el Monitor
=== Ejecutando ciclo de monitoreo para: Server-DataCenter-01 ===
Sensor [CPU] midio: 64
Sensor [Memoria] midio: 95
 -> ALERTA GENERADA en Memoria!
Sensor [Red] midio: 43
====================================================

======  REPORTE DE ALERTAS - SISTEMA: Server-DataCenter-01  ======
Total de alertas registradas: 2
Alerta 1 -> Nivel: CRITICO | Mensaje: El valor supero el umbral tolerado | Valor: 95
Alerta 2 -> Nivel: CRITICO | Mensaje: El valor supero el umbral tolerado | Valor: 86
============================================================

>>> CASO 4: Usando la sobrecarga de operadores (==)
Comparando si cpuA tiene la misma carga actual que cpuB...
Resultado: Los sensores de CPU tienen cargas distintas actuales.
====================================================
Process finished with exit code 0
```

## Cómo compilar y ejecutar

Este proyecto usa **CMake** y fue desarrollado en **CLion**.

### Requisitos
- Compilador compatible con C++11 o superior (g++, clang, MSVC)
- CMake 3.10 o superior

### Pasos

```bash
git clone https://github.com/TU-USUARIO/DataStreamMonitor.git
cd DataStreamMonitor
mkdir build
cd build
cmake ..
cmake --build .
./Evidencia2      # o Evidencia2.exe en Windows
```

## Limitaciones conocidas

- Los sensores se almacenan en un arreglo estático de tamaño fijo (`Sensor*[10]`); si se intentan registrar 10 o más sensores, el sistema genera un error.
- Las alertas se almacenan en un arreglo estático (`Alerta[50]`); al superar las 50 alertas registradas, las nuevas dejan de guardarse.
- Los datos de los sensores son simulados con valores generados aleatoriamente; no se conectan a hardware real.

## Posibles mejoras futuras

- Sustituir los arreglos estáticos por `std::vector` para eliminar los límites fijos de sensores y alertas.
- Integrar lectura de datos reales del sistema en lugar de valores simulados.
- Adaptar el sistema para monitorear múltiples computadoras de una red o compañía en tiempo real.

## Autor

**Federico Manuel Fernández Peña**
Proyecto Integrador — Programación Orientada a Objetos (TC1030.306)
Tecnológico de Monterrey
