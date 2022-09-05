#include <ncurses.h>
#include <string>
#include <iostream>
#include "Menu.h"
#include "Display.h"
#include "SenseHat.h"
#include "Sensors.h"

using namespace std;

void Menu::CreateMenu()
{
    // we need my display class
    Display display;

    // init ncurses
    initscr();
    noecho();
    cbreak();

    // get sscreen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // create window
    WINDOW * menuwin = newwin(6, xMax-12, yMax-8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    // use arrow keys
    keypad(menuwin, true);

    string options[4] = 
    {
        " - Write authors name to display",
        " - Write temperature to display",
        " - Write humidity to display",
        " - Write pressure to display"
    };
    int option;
    int selected = 0;

    // menu loop
    while(1)
    {
        // write the menu options onto the terminal
        for(int i = 0; i < 4; i++)
        {
            if (i == selected) {
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i+1, 1, options[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        
        option = wgetch(menuwin);


        switch(option) {
            // handle trying to "go out of bounds"
            case 119: // actual KEY_UP not working, using w
                selected--;
                if (selected == -1)
                    selected = 3;
                break;
            case 115: // actual KEY_DOWN not working, using s
                selected++;
                if (selected == 4)
                    selected = 0;
                break;
            case 100: // actual KEY_ENTER not working, using d
                // if user presses the right execute function depending on the selected option
                switch(selected) {
                    // writes my name to the display
                    case 0:
                        clear();
                        printw("Writing text to the display");
                        refresh();

                        display.DisplayText("feeeeedt man :)");
                        break;
                    case 1:
                        clear();
                        printw("Writing the temperature to the display");
                        refresh();

                        display.DisplayTemperature();
                        break;
                    case 2:
                        clear();
                        printw("Wrtiting the humidity to the display");
                        refresh();

                        display.DisplayHumidity();
                        break;
                    case 3:
                        clear();
                        printw("Writing the pressure to the display");
                        refresh();

                        display.DisplayPressure();
                        break;
                }
            default:
                std::cout << "default break";
                break;
        }
        
        if (option == 10)
            break;
        
        printw("\nYou choose option: %s", options[selected].c_str());
    }
}
