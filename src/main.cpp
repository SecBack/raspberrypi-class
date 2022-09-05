#include "Sensors.h"
#include "Menu.h"
#include "Data.h"

#include <iostream>

using namespace std;

int main()
{  
    // save the sensor values to a csv file in a time interval
    Data data;
    data.SaveToCSVWorker();

    // read values from the sensors in the background
    Sensors sensors;
    sensors.Activate();

    // create the menu
    Menu menu;
    menu.CreateMenu();

    return 0;
}
