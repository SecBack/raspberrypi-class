#include <thread>
#include <chrono>
#include "Data.h"
#include "Sensors.h"

using namespace std;

// start getting values from the following sensors on a separate thread, to prevent blocking
void Sensors::Activate()
{
    thread temperatureThread(StartTemperatureSensor);
    thread humidityThread(StartHumiditySensor);
    thread pressureThread(StartPressureSensor);
}

// get temperature sensor value each second and set the global variable
void Sensors::StartTemperatureSensor()
{
    while(1)
    {
        temperature = senseHat.GetTemperature();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

// get humidity sensor value each second and set the global variable
void Sensors::StartHumiditySensor()
{
    while(1)
    {
        humidity = senseHat.GetHumidity();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

// get pressure sensor value each second and set the global variable
void Sensors::StartPressureSensor()
{
    while(1)
    {
        pressure = senseHat.GetPressure();
        this_thread::sleep_for(chrono::seconds(1));
    }
}
