#ifndef DISPLAY_H
#define DISPLAY_H

using namespace std;

class Display
{
    public:
        Display();

        void DisplayText(string displayText);
        void DisplayTemperature();
        void DisplayHumidity();
        void DisplayPressure();
};
#endif