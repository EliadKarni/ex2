#pragma once

class PlayerState {
public:
	PlayerState();
	
	int getLifeState();
	int getScoreState();
	void die();
	void collectCoin(int level);
private:
	unsigned int life;
	unsigned int score;
};
