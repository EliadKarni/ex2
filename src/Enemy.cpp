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
Location Enemy::getLocation() const{ return this->m_location; };
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method is update the enemy's location by the played turn.
 * input: The level map object, the player location on the map.
 * output: none.
*/
void Enemy::playTurn(const Map& map, const Location& playerLocation) {
	this->m_location = map.calcEnemyMove();
}