/* BoardReader
 * ===========================================================================
 */
 //---------------------------- include section -------------------------------
#include "BoardReader.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>

//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is .
 * input: .
 * output: .
*/
BoardReader::BoardReader() {
	this->m_boardReader.open(BOARD_PATH);
	if (!(this->m_boardReader.is_open())) {
		std::cerr << "opening boards files error!\n";
		exit(EXIT_FAILURE);
	}
}
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method .
 * input: .
 * output: .
*/

