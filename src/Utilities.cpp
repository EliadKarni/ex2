
//This is a general functions that help us to execute the game.


#include <stdlib.h>
#include <iostream>
#include "Utilities.h"
#include "io.h"
#include "Map.h"
#include "Location.h"
//========================================================================
/* input: string
 * output: print the error messege it got and exit from the program(-1)
*/
void terminate(const std::string &errorMessage) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}
//========================================================================
/* input: None.
 * output: The integer value of the key received by the user.
*/
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
//========================================================================
/* input: Key inputed by the user
 * output: print a messege that tell to the user about wrong key he inputed
*/
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
//========================================================================
/* input: None.
 * output: The integer value of the key received by the user.
*/
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
//========================================================================
/* input: 
 * output:
*/
void moveObject(const Map& map, const Location& init, const Location& dest, char symbol) {
    if (map.mapException(init) && map.mapException(dest)) {
        Screen::setLocation(init);
        std::cout << map.getContent(init);
        Screen::setLocation(dest);
        std::cout << symbol;
    }
}
