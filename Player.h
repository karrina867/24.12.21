#pragma once
#include"Creature.h"
class Player :public Creature {
private:
	int m_level;
public:
	Player(string name, char symbol='@', int hp=10, int damage=1, int gold=0, int level=1) :
		Creature( name,  symbol, hp, damage, gold) ,m_level{level}
	{}
	int getLevel() { return m_level; }
	void levelUp();
	bool hasWon();
};
