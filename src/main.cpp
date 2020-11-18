/* ex2
 * ===========================================================================
 * Writen by:
 * Sharon Levi | ID: 311593313 | login: sharonlevi
 * Eliad Karni | ID: 206329104 | login: eliadka
 *
 *
 */

 //---------------------------- include section -------------------------------
#include <iostream>
#include "player_state.h"
//------------------------------ using section -------------------------------
using std::cin;
using std::cout;
using std::endl;
//------------------------------ main section --------------------------------
int main()
{
	PlayerState state = PlayerState();
	cout << "life is: "<< state.getLifeState() << endl
		<< "score is: " << state.getScoreState()<< endl;
	return 0;
}
