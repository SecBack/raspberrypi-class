#include <thread>
#include <chrono>
#include "Data.h"
#include "Sensors.h"

using namespace std;

void Sensors::Activate()
{
    thread temperatureThread(StartTemperatureSensor);
    thread humidityThread(StartHumiditySensor);
    thread pressureThread(StartPressureSensor);
}

void Sensors::StartTemperatureSensor()
{
    while(1)
    {
        temperature = senseHat.GetTemperature();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void Sensors::StartHumiditySensor()
{
    while(1)
    {
        humidity = senseHat.GetHumidity();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void Sensors::StartPressureSensor()
{
    while(1)
    {
        pressure = senseHat.GetPressure();
        this_thread::sleep_for(chrono::seconds(1));
    }
}
