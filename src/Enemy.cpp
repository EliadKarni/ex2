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
 * The get method
 * input:
 * output: .
*/
Location Enemy::getLocation() const{ return this->m_location; };
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Enemy::setLocation(const Location& newlocation) 
{ this->m_location = newlocation; }
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Enemy::playTurn(const Map& map, const Location& playerLocation) {
	this->m_location = map.FoolEnemy();
}