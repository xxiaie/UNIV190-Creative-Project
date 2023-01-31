#include<iostream>
#include "house.h"
#include "defs.h"
using namespace std;

int main()
{
	House Game;
	intro();

	Game.dinKit();
	Game.live();
	Game.base();

	credits();

	return 0;
}