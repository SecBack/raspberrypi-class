#include <string>
#include "Display.h"
#include "SenseHat.h"
#include "Data.h"

using namespace std;

Display::Display()
{
    // settings for the display
    senseHat.Effacer();
    senseHat << setcouleur(senseHat.ConvertirRGB565(84, 84, 0)) << setrotation(270);
}

// given a string, print it to the display
void Display::DisplayText(string displayText)
{
    while(1) {
        senseHat << displayText << flush;
        sleep(0.2);
    }    
}

// prints the temperature to the display
void Display::DisplayTemperature()
{
    while(1)
    {
        senseHat << "Temperature: " << temperature << flush;
        sleep(1);
    }
}

// prints the humidity to the display
void Display::DisplayHumidity()
{
    while(1)
    {
        senseHat << "Humidity: " << humidity << flush;
        sleep(1);
    }
}

// prints the pressure to the display
void Display::DisplayPressure()
{
    while(1)
    {
        senseHat << "Pressure: " << pressure << flush;
        sleep(1);
    }
}