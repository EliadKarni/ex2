/* ex2
 * ===========================================================================
 * Writen by:
 * Sharon Levi | ID: 311593313 | login: sharonlevi
 * Eliad Karni | ID: 206329104 | login: eliadka
 *
 *
 */

 //---------------------------- include section ------------------------------
#include <iostream>
#include <string.h>
#include "player_state.h"
#include "Controller.h"
//----------------------------- define section -------------------------------
#define NUM_OF_LEVELS 2
#define LEVEL1PATH "\levels\level.txt"
#define LEVEL2PATH "\levels\leve2.txt"

//------------------------------ using section -------------------------------
using std::cin;
using std::cout;
using std::endl;
//------------------------------ main section --------------------------------
int main()
{
	//--------------------- parameters declareation --------------------------
	std::string levelsPathes[NUM_OF_LEVELS] = { LEVEL1PATH, LEVEL2PATH };
	PlayerState playeState = PlayerState();
	
	//---------------------------------running levels---------------------------------------
	for (int i = 0; 
		i < NUM_OF_LEVELS && playeState.getLifeState() != 0; ++i) {
		Controller levelController = Controller(levelsPathes[i]);
		levelController.runGame(playeState);
	}

	return (EXIT_SUCCESS);
}
