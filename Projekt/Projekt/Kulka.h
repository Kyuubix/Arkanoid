#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace sf;

const float PIERW_2 = float(sqrt(2));
const float PIERW_5 = float(sqrt(5));

class Kulka
{
private:
	CircleShape ball;
	Texture ballTexture;
	Clock ballClock;
	float movementFactor;
	float blockFactor;
	float difficultyFactor;
	float radius;
	float timeFrame;
	Vector2f movementVector;
	Vector2f positionVector;
	bool isStarted;
	bool isDrawn;
	int drawnPosition;

public:
	Kulka(float r = 4.0f);
	~Kulka();
	void read();
	void ballStart(Vector2f position, Vector2f size);
	void movement();
	//Gettery
	CircleShape getBall();
	float getDiameter();
	Vector2f getMovementVector();
	Vector2f getPositionVector();
	float getMovementFactor();
	bool getIsStarted();
	float getDifficultyFactor();
	//Settery
	void setPosition(float x, float y);
	void setMovementVector(float x, float y);
	void setMovementFactor(float m);
	void setBlockFactor(float m);
	void setDifficultyFactor(float m);
	void resetClock();
	void setIsStarted(bool is);
	void setIsDrawn(bool is);
};

