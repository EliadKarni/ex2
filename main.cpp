#include <iostream>
#include <cstdlib> // for std::system()
#include "io.h"
#include "Controller.h"

const int KB_ESCAPE = 27;

bool handleRegularKey(int c);
void handleSpecialKey();

int main()
{
    Controller GameManager;
    GameManager.runGame(); 
}

bool handleRegularKey(int c)
{
    switch (c)
    {
    case 'A':
        std::cout << "A pressed\n";
        break;
    case 'a':
        std::cout << "a pressed\n";
        break;
    case KB_ESCAPE:
        std::cout << "Escape pressed. Exiting...\n";
        return true;
    default:
        std::cout << "Unknown regular key pressed (code = " << c << ")\n";
        break;
    }

    return false;
}

void handleSpecialKey()
{
    auto c = Keyboard::getch();
    switch (c)
    {
    case KB_UP:
        std::cout << "Arrow Up pressed\n";
        break;
    case KB_DOWN:
        std::cout << "Arrow Down pressed\n";
        break;
    case KB_LEFT:
        std::cout << "Arrow Left pressed\n";
        break;
    case KB_RIGHT:
        std::cout << "Arrow Right pressed\n";
        break;
    default:
        std::cout << "Unknown special key pressed (code = " << c << ")\n";
        break;
    }
}
