#include "Game.h"

Game::Game()
{
	prepareWindow();
	prepareFont();
}

Game::~Game()
{
	delete  window;
}

void Game::update()
{
	updateEvents();
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
				window->close(); break;
		}
	}
}

void Game::prepareWindow()
{
	videoMode.height = 387;
	videoMode.width = 646;
	window = new RenderWindow(videoMode, "Arena");
}

void Game::prepareFont()
{

	if (!texture.loadFromFile("Resources\\Images\\bg.jpg"))
	{
		cout << "IMAGE NOT FOUND" << endl;
	}
	sprite.setTexture(texture);

	if (!font.loadFromFile("Resources\\Fonts\\font2.ttf"))
	{
		cout << "FONT NOT FOUND" << endl;
	}
	text.setFont(font);
	//text.setFillColor(Color::Red);
	text.setString("Arena(no virus) 2012");

}

void Game::render()
{
	window->draw(sprite);
	window->draw(text);
	window->display();
}

bool Game::running()
{
	return window->isOpen();
}
