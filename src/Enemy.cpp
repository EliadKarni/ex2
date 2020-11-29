/* Enemy
 * ===========================================================================
 *
 */
 //---------------------------- include section -------------------------------
#include "Enemy.h"
#include "Map.h"
#include "Location.h"
//------------------------------ gets section --------------------------------
/*----------------------------------------------------------------------------
 * The get get method return the enemy's location on the map.
 * input: none.
 * output: enemy's location on the map.
*/
Location Enemy::getLocation()const { return this->m_location; }
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method is update the enemy's location by the played turn.
 * input: The level map object, the player location on the map.
 * output: none.
*/
void Enemy::playTurn(const Map& map, const Location& playerLocation) {
	Location moveAns = this->m_location;
	
	if (isRightOf(playerLocation, getLocation()))
		moveAns = map.rightMove(getLocation());
	else if (isLeftOf(playerLocation, getLocation()))
		moveAns = map.leftMove(getLocation());
	if (moveAns == getLocation()) {
		if (isAboveOf(playerLocation, getLocation()))
			moveAns = map.upMove(getLocation());
		else
			moveAns = map.downMove(getLocation());
	}
	if (moveAns == getLocation())
		return;
	this->m_location = moveAns;
}