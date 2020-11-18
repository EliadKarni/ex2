/* player_state
 * ===========================================================================
 *
 */
//---------------------------- include section -------------------------------
#include "player_state.h"
//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is building  the object using array of 3 received Vertexes.
 * input: array of 3 Vertexes.
 * output: none.
*/
PlayerState::PlayerState() : life(3), score(0) {}
//------------------------------ gets section --------------------------------
/*----------------------------------------------------------------------------
 * The get method 
 * input: 
 * output: .
*/
int PlayerState::getLifeState() { return(this->life);}
/*----------------------------------------------------------------------------
 * The get method
 * input:
 * output: .
*/
int PlayerState::getScoreState() { return(this->score);}
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method 
 * input: .
 * output: 
*/
void PlayerState::die() {
	if (this->life > 0)
		--this->life;
}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void PlayerState::collectCoin(int level) {
	this->score += level * 50;
}