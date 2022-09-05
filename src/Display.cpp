#include <string>
#include "Display.h"
#include "SenseHat.h"
#include "Data.h"

using namespace std;

Display::Display()
{
    // setting for the display
    senseHat.Effacer();
    senseHat << setcouleur(senseHat.ConvertirRGB565(84, 84, 0)) << setrotation(270);
}

void Display::DisplayText(string displayText)
{
    while(1) {
        senseHat << displayText << flush;
        sleep(0.2);
    }    
}

void Display::DisplayTemperature()
{
    float x,y,z;
    int angle;

    while(1)
    {
        senseHat << "Temperature: " << temperature << flush;
        sleep(1);
    }
}

void Display::DisplayHumidity()
{
    while(1)
    {
        senseHat << "Humidity: " << humidity << flush;
        sleep(1);
    }
}

void Display::DisplayPressure()
{
    while(1)
    {
        senseHat << "Pressure: " << pressure << flush;
        sleep(1);
    }
}