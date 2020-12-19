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
		system("PAUSE");
		game.renderIntro();

		while (true)
		{
			game.player1.Show_name();

			//if (round) player1.Play_Round(player2, round); else  player2.Play_Round(player1, round);


			game.update();

			//CONSOLE								WINDOW
			//system("CLS");

			game.render(); //clean, draw, display 
			//player1.Show_all();player2.Show_all();



			//if (player1.Check_is_Dead()) return 1;		//anyone dead?
			//else if (player2.Check_is_Dead()) return 0;
			round = !round; roundCount++;
		}
	}
}