cmake_minimum_required(VERSION 4.2)
project(Evidencia2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Evidencia2 main.cpp
        alerta.h
        Alerta.cpp
        sensor.h
        Sensor.cpp
        monitor.h
        Monitor.cpp
        sensorCPU.h
        SensorCPU.cpp
        sensorMemoria.h
        SensorMemoria.cpp
        sensorRed.h
        SensorRed.cpp)
