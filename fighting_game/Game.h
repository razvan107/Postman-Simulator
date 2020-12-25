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
		Text midtext;

	Sprite BgSprite;
	RenderWindow* window;
	champion player1;
	champion player2;
	//champion* player3;
	Texture BgTexture;
	Texture P1Texture;
	Texture P2Texture;
	Sprite P1Sprite;
	Sprite P2Sprite;
	
	void prepareWindow();
	void preparePlayerTextures();
	void prepareFont();

	void prepareIntro();
	void renderIntro();

	void prepareFight();		
	void prepareBackground();

public:
	void Intro();
	void fight();

	int state = 0;
	Game();
	virtual ~Game();
	Event event;
	void update();
	void updateEvents();


	void render();

	bool running();
};

