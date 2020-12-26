#include "champion.h"
#include "Game.h"
#include "Header.h"
using namespace std;

int main()
{//			name hp dmg armor
	Game game;

	while (game.running())
	{
		game.Intro();
		wait(2);
		game.fight();
			//
	}
}