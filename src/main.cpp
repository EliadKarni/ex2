/* ex2
 * ===========================================================================
 * Writen by:
 * Sharon Levi | ID: 311593313 | login: sharonlevi
 * Eliad Karni | ID: 206329104 | login: eliadka
 *
 *
 */

 //---------------------------- include section ------------------------------
#include <fstream>
#include "player_state.h"
#include "Controller.h"
//----------------------------- define section -------------------------------
#define BOARD_PATH "\levels\level.txt"

//------------------------------ using section -------------------------------
using std::vector;
using std::string;
using std::ifstream;
//------------------------------ main section --------------------------------
int main()
{
	//--------------------- parameters declareation --------------------------
	PlayerState playeState = PlayerState();
	Controller gameContraller = Controller();
	std::ifstream boardReader;

	boardReader.open(BOARD_PATH);
	if (!boardReader.is_open()){
		std::cerr << "game loading eroor!\n";
		return EXIT_FAILURE;
	}
	//---------------------------------running games---------------------------------------
	gameContraller.runGame(boardReader);

	return (EXIT_SUCCESS);
}
