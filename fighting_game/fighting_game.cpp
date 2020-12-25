#include "champion.h"
#include "Game.h"
#include "Header.h"
using namespace std;

int main()
{//			name hp dmg armor
	Game game;
	
	while (game.running())
	{
		bool round = 1;
		bool roundCount = 1;
		game.Intro();

		game.fight();

			//if (round) player1.Play_Round(player2, round); else  player2.Play_Round(player1, round);


			//if (player1.Check_is_Dead()) return 1;		//anyone dead?
			//else if (player2.Check_is_Dead()) return 0;
		round = !round; roundCount++;
	}
}