#include "Game.h"
Game::Game() :player1("the Postman", 1000, 10, 10), player2("Ted", 1000, 20, 1)
{
	prepareWindow();
	prepareFont();
	preparePlayerTextures();
}
Game::~Game()
{
	delete  window;
}

void Game::update(bool round)
{
	updateEvents(round);

}
void Game::updateEvents(bool& round)
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close(); break;

		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
			{
				window->close(); break;
			}
			if (event.key.code == Keyboard::Num1)
			{
				player1.Basic_attack(player2);
				round = !round;
				break;
			}
			if (event.key.code == Keyboard::Num4)
			{
				player1.Self_heal(1);
				//round = !round;
				break;
			}

		}
	}
	switch (state)
	{
	case 1:
		break;
	case 2:
		//update footer
		if (round)
		{
			midtext.setString(player1.Make_Action_Header(player2));
		}
		else
		{
			midtext.setString(player2.Make_Action_Header(player1));
		}
		footer.setString(player1.show_all() + "   " + player2.show_all());

		break;
	}

}

void Game::prepareWindow()
{
	videoMode.width = 646;
	videoMode.height = 387;
	window = new RenderWindow(videoMode, "Arena");
	window->setKeyRepeatEnabled(false);
	window->setFramerateLimit(20);
}
void Game::prepareBackground()
{

	if (!BgTexture.loadFromFile("Resources\\Images\\bg.png"))
	{
		cout << "BG NOT FOUND" << endl;
	}

	BgSprite.setTexture(BgTexture);
}
void Game::preparePlayerTextures()
{
	//PLAYER1

	if (!P1Texture.loadFromFile("Resources\\Images\\P1Texture.png"))
	{
		cout << "p1 NOT FOUND" << endl;
	}
	P1Sprite.setTexture(P1Texture);
	P1Sprite.setPosition(Vector2f(80, 150));

	//move P1 in place
	P1Sprite.setScale(Vector2f(3, 3));


	//PLAYER 2

	if (!P2Texture.loadFromFile("Resources\\Images\\P2Texture.png"))
	{
		cout << "p2 NOT FOUND" << endl;
	}

	P2Sprite.setTexture(P2Texture);
	P2Sprite.setScale(Vector2f(3, 3));
	//move P2 in place
	P2Sprite.setPosition(Vector2f(280, 150));
}
void Game::prepareFont()
{
	if (!font.loadFromFile("Resources\\Fonts\\font.ttf"))
	{
		cout << "FONT NOT FOUND" << endl;
	}
	header.setFont(font);
	header.setFillColor(Color::Black);
	header.setCharacterSize(20);

	footer.setFont(font);
	footer.setFillColor(Color::Black);
	footer.setCharacterSize(15);
	footer.move(Vector2f(0, 360));

	midtext.setFont(font);
	midtext.setFillColor(Color::Black);
	midtext.setCharacterSize(20);
}
void Game::prepareIntro()
{
	Game::state = 1;
	header.setString(player1.Make_Fighter_Header(player2));
}


void Game::render()
{
	window->clear();
	switch (Game::state)
	{
	case 1://intro
	{
		window->draw(BgSprite);
		window->draw(header);
		window->display();
		break;
	}
	case 2://fight
	{
		window->draw(BgSprite);
		window->draw(P1Sprite);
		window->draw(P2Sprite);

		//window->draw(header);
		window->draw(midtext);
		window->draw(footer);
		break;
	}
	}
	window->display();
}
void Game::renderIntro()
{
	window->clear(Color::White);
	window->draw(BgSprite);
	window->draw(header);
	window->display();
}
void Game::Intro()
{
	prepareIntro();
	update();
	renderIntro();
}
void Game::prepareFight()
{
	midtext.setString(player1.Make_Action_Header(player2));
	midtext.move(Vector2f(50, 60));
	prepareBackground();
	state = 2;
}
void Game::fight(bool round)
{
	
	prepareFight();
	while (true)
	{


		update(&round);
		render();

		//if (player1.Check_is_Dead()) { cout << "p2 wins"; }
		//else if (player2.Check_is_Dead()) { cout << "p1 wins"; }
	}
}
bool Game::running()
{
	return window->isOpen();
}

