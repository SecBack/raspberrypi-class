#ifndef DATA_H
#define DATA_H

#include "SenseHat.h"

extern int temperature;
extern int humidity;
extern int pressure;

extern SenseHat senseHat;

class Data
{
    public:
        static void SaveToCSV();
        void SaveToCSVWorker();
};
#endif