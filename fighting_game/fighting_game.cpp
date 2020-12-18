#include "champion.h"
#include "Game.h"
#include "Header.h"
using namespace std; 

int main()
{//			name hp dmg armor
	champion ashe("Ashe", 2000, 100, 22);
	champion enemy("Darius", 2000, 100, 22);
	Game game;

	while (game.running())
	{
		bool round = 1;
		bool roundCount = 1;
		ashe.Show_Fight_Intro(enemy);
		//wait(1);
		while (true)
		{
			//pick who makes a move
			//CONSOLE 
			//if (round) ashe.Play_Round(enemy, round); else  enemy.Play_Round(ashe, round);
			//WINDOW


			game.update();

			//wait(2);	
			//CONSOLE								WINDOW
			system("CLS");						
			game.render();
			ashe.Show_all();enemy.Show_all();



			if (ashe.Check_is_Dead()) return 1;		//anyone dead?
			else if (enemy.Check_is_Dead()) return 0;
			round = !round; roundCount++;
		}
	}
}