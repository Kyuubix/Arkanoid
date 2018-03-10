#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gra.h"
using namespace sf;

const int TEXT_MENU = 20;
const int TEXT_GAME = 10;
const Color gray(170, 170, 170);
const Color silver(240, 240, 240);
const Color dark(0, 0, 0, 2);

class Gui
{
	Sprite background;
	Texture backgroundTexture;
	Sprite menu;
	Texture menuTexture;
	Sprite pause;
	RectangleShape pauseBackground;
	Text textMenu[TEXT_MENU];
	Text textGame[TEXT_GAME];
	Font fontMenu;
	Font fontGame;
public:
	Gui();
	~Gui();
	void readTexture();
	void readFont();
	void readTextMenu();
	void readTextGame();
	void updateScoreLife(int score, int life);
	void updateEndScore(int score);
	void updateHighScore(int score);
	void textCenter(int nr);
	void textBacklight(int nr, Vector2f mouse);
	//Przyciski
	void onPlayClick(Vector2f mouse, Gra *game);
	void onExitClick(Vector2f mouse);
	void onLevelClick(Vector2f mouse, Gra *game);
	void onDifficultyClick(Vector2f mouse, Kulka *k, Gra *game);
	void onStartClick(Vector2f mouse, Gra *game);
	void onBackClick(Vector2f mouse, Gra *game);
	void onResumeClick(Vector2f mouse, Gra *game, Kulka *k);
	void onMenuClick(Vector2f mouse, Gra *game, Kulka *k, Blok1 *b1, Blok2 *b2, Blok5 *b5);
	void onHighScoresClick(Vector2f mouse, Gra *game);
	//Gettery
	Sprite getBackground();
	Sprite getMenu();
	RectangleShape getPauseBackground();
	Vector2f getSizeVector();
	Text getTextMenu(int nr);
	Text getTextGame(int nr);
	//Settery:
	void setTextGame(int nr, char* name, Color color);
};

