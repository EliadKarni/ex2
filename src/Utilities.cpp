#include <stdlib.h>
#include <iostream>
#include "Utilities.h"
#include "io.h"
#include "Map.h"
#include "Location.h"

void terminate(const std::string &errorMessage) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}

int receiveKey() {
    for (auto exit = false; !exit; ) {
        auto c = Keyboard::getch();
        switch (c)
        {
        case 0:
        case SPECIAL_KEY:
            return handleSpecialKey();
            break;
        default:
            return handleRegularKey(c);
            break;
        }
    }
    return 0;
}

int handleRegularKey(int c)
{
    switch (c)
    {
    case KB_ESCAPE:
        return KB_ESCAPE;
    default:
        std::cout << "Unknown regular key pressed (code = " << c << ")\n";
        break;
    }

    return c;
}

int handleSpecialKey()
{
    auto c = Keyboard::getch();
    switch (c)
    {
    case KB_UP:
        return KB_UP;
    case KB_DOWN:
        return KB_DOWN;
    case KB_LEFT:
        return KB_LEFT;
    case KB_RIGHT:
        return KB_RIGHT;
    default:
        std::cout << "Unknown special key pressed (code = " << c << ")\n";
        break;
    }
    return 0;
}

void moveObject(const Map& map, const Location& init, const Location& dest, char symbol) {
    if (map.mapException(init) && map.mapException(dest)) {
        Screen::setLocation(init);
        std::cout << map.getContent(init);
        Screen::setLocation(dest);
        std::cout << symbol;
    }
}