#include "Game.h"
Game::Game():player1("the Postman", 1000, 1000, 1000), player2("Ted", 1000, 1000, 1000)
{
	prepareWindow();
	prepareBackground();
	prepareFont();
	preparePlayerTextures();
	prepareIntro();
}
Game::~Game()
{
	delete  window;
}

void Game::update()
{
	updateEvents(); //check if a button was pressed
	footer.setString(player1.show_all() +"   " + player2.show_all());
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
}

void Game::prepareIntro()
{
	header.setString(player1.Make_Fighter_Header(player2));
}


void Game::render()
{
	window->clear();
	//draw sprites
	window->draw(BgSprite);
	window->draw(P1Sprite);
	window->draw(P2Sprite);

	//draw the header over the sprites
	window->draw(header);
	window->draw(footer);
	window->display();
}
void Game::renderIntro()
{
	window->draw(BgSprite);

	window->draw(header);
}
bool Game::running()
{
	return window->isOpen();
}

