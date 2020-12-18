#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp> 
#include <iostream>
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

	Game();
	virtual ~Game();
	Event event;
	void update();
	void updateEvents();

	void prepareWindow();
	void prepareFont();

	void render();
	bool running();
};

