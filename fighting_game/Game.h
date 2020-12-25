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
	Text header;
	Text footer;

	Sprite BgSprite;
	RenderWindow* window;

	champion player1;
	champion player2;
	//champion player1(string& name, int health, int base_damage, int armor);
	//champion player2(string& name, int health, int base_damage, int armor);

	Texture BgTexture;
	Texture P1Texture;
	Texture P2Texture;
	Sprite P1Sprite;
	Sprite P2Sprite;
	void prepareWindow();
	void prepareBackground();
	void preparePlayerTextures();
	void prepareFont();
public:

	Game();
	virtual ~Game();
	Event event;
	void update();
	void updateEvents();


	void render();
	void renderIntro();
	bool running();
};

