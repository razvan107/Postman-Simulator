#include "Game.h"

Game::Game()
{
	this->prepareWindow();
	this->prepareFont();
}

Game::~Game()
{
	delete this-> window;
}

void Game::update()
{
	updateEvents();
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close(); break;

		case Event::KeyPressed:
			if (this->event.key.code == Keyboard::Escape)
				this->window->close(); break;
		}
	}
}

void Game::prepareWindow()
{
	this->videoMode.height = 387;
	this->videoMode.width = 646;
	this->window = new RenderWindow(this->videoMode, "Arena");
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
	return this->window->isOpen();
}
