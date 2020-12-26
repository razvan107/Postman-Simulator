#include "champion.h"
#include "Game.h"
#include "Header.h"
using namespace std;

int main()
{//		
	Game game;
	bool round = 1;
	while (game.running())
	{
		game.Intro();
		wait(2);
		game.fight(round);
			//
	}
}