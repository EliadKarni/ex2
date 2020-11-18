#pragma once
#define NUM_OF_LIFE 3
#define COIN_SCORE 50
#define LEVEL_UP_SCORE 50

class PlayerState {
public:
	PlayerState();
	
	int getLifeState()const;
	int getScoreState()const;
	void die();
	void collectCoin(int level);
private:
	unsigned int life;
	unsigned int score;
};
