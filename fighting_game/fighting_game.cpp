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

		game.fight();
			//if (round) player1.Play_Round(player2, round); else  player2.Play_Round(player1, round);
	}
}