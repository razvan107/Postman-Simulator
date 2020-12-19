#include "Game.h"

Game::Game()
{
	prepareWindow();
	prepareBackground();
	prepareFont();
	champion player1("Ashe", 2000, 100, 22);
	champion player2("Damian", 2000, 100, 22);
}

Game::~Game()
{
	delete  window;
}

void Game::update()
{
	updateEvents(); //check if a button was pressed
}

void Game::updateEvents()
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

		}
	}
}

void Game::prepareWindow()
{
	videoMode.width = 646;
	videoMode.height = 387;
	window = new RenderWindow(videoMode, "Arena");
	window->setFramerateLimit(60);
}
void Game::prepareBackground()
{
	if (!texture.loadFromFile("Resources\\Images\\bg.png"))
	{
		cout << "BG NOT FOUND" << endl;
	}
	sprite.setTexture(texture);
}
void Game::prepareFont()
{
	if (!font.loadFromFile("Resources\\Fonts\\font2.ttf"))
	{
		cout << "FONT NOT FOUND" << endl;
	}
	text.setFont(font);
	text.setFillColor(Color::Black);
}


void Game::render()
{
	window->clear();
	window->draw(sprite);
	window->draw(text);
	window->display();
}

void Game::renderIntro()
{
	string intro;
	intro = player1.Show_Fight_Intro(player2);
	text.setString(intro);
	window->draw(text);
}

bool Game::running()
{
	return window->isOpen();
}

