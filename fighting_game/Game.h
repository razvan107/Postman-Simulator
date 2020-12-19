#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp> 
#include "champion.h"
#include <iostream>
#include <string>


using namespace std;
using namespace sf;
class Game
{

	VideoMode videoMode;

	Font font;
	Text text;

	sf::Texture texture;
	Sprite sprite;

public:
	RenderWindow* window;
	champion player1;
	champion player2;
	Game();
	virtual ~Game();
	Event event;
	void update();
	void updateEvents();

	void prepareWindow();
	void prepareBackground();
	void prepareFont();

	void render();
	void renderIntro();
	bool running();
};

