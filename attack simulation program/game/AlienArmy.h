#pragma once
#include"gameHeader.h"

class AlienArmy :public Pixie
{
public:
	AlienArmy() :Pixie("enemy.bmp", 10.0, 100.0, ALIEN_ARMY) {}
};