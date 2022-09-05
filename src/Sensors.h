#ifndef SENSORS_H
#define SENSORS_H

#include "SenseHat.h"

using namespace std;

class Sensors
{
    public:
        void Activate();
        static void StartTemperatureSensor();
        static void StartHumiditySensor();
        static void StartPressureSensor();
};
#endif