#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "Data.h"
#include "SenseHat.h"

// global variables, yes, global because of multithreading
int temperature = 0;
int humidity = 0;
int pressure = 0;

SenseHat senseHat;

using namespace std;

// starts a new thread with the given function
void Data::SaveToCSVWorker()
{
    thread saveToCSVWorker(SaveToCSV);
}

//saves the vales a csv file
void Data::SaveToCSV()
{
    // Create and open a text file
    ofstream file("sensor-values.csv");
    file << "temperature, humidity, pressure";

    while(1)
    {
        // write the sensor values to the csv file
        file << temperature << ", " << humidity << ", " << pressure;

        // Close the file
        file.close();

        this_thread::sleep_for(chrono::seconds(5));
    }

}
