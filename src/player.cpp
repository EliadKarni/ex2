/* Player
 * ===========================================================================
 *
 */
 //---------------------------- include section -------------------------------
#include "Player.h"
#include "Map.h"
#include "Location.h"
//------------------------------ gets section --------------------------------
/*----------------------------------------------------------------------------
 * The get method is return the player's currect location.
 * input: none.
 * output: player's currect location.
*/
Location Player::getLocation() const { return this->m_location; };
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method is playing the player turn by the demanded method.
 * input: level's map.
 * output: none.
*/
void Player::PlayTurn(const Map &map){
	Location newLocation = this->m_location;
	while (this->m_location == newLocation)
		newLocation = 
		map.isMovePossible(this->m_location, Keyboard::getch());
}