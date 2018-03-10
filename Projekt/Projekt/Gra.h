#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cstdlib>
#include "Kulka.h"
#include "Blok.h"
#include "Blok1.h"
#include "Blok2.h"
#include "Blok3.h"
#include "Blok4.h"
#include "Blok5.h"
using namespace sf;

const int SIZE1 = 78;
const int SIZE2 = 52;
const int SIZE3 = 26;

const int MAIN_MENU = 0;
const int HIGH_SCORES = 1;
const int SELECTION = 2;
const int GAME = 3;
const int PAUSE = 4;
const int END = 5;

class Gra
{
	int score;
	int toScore;
	int highScore;
	int level;
	int life;
	int gameState;
	Event closeEvent;
	Event pauseEvent;
	bool isWin;
	bool isLose;
public:
	Gra();
	~Gra();
	void readBestScore();
	void paddleBounce(Vector2f position, Vector2f size, Kulka *k); //wektory paletki
	void wallBounce(Vector2f size, Kulka *k); //wektor tla
	void blockBounce(Kulka *k, Blok1 *b1, int size1, Blok2 *b2, int size2, Blok5 *b5, int size5);
	void Level1(Blok1* b1, Blok2* b2, Blok5* b5);
	void Closing(RenderWindow *w);
	void Pause();
	void Victory(Kulka *k);
	void saveBestScore();
	//Gettery
	int getScore();
	int getLevel();
	int getGameState();
	bool getIsWin();
	bool getIsLose();
	int getLife();
	int getHighScore();
	//Settery
	void setLevel(int a);
	void setScore(int a);
	void setGameState(int nr);
	void setIsWin(bool is);
	void setIsLose(bool is);
	void setLife(int a);
	void setHighScore(int a);
};

