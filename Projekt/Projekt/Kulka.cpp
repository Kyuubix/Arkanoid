#include "Kulka.h"


Kulka::Kulka(float r)
{
	this->radius = r;
	this->movementFactor = 1.0f;
	this->blockFactor = 1.0f;
	this->difficultyFactor = 1.0f;
	this->movementVector.x = 0;
	this->movementVector.y = 0;
	this->timeFrame = 0.0f;
	this->isStarted = false; 
	this->isDrawn = false;
	read();
}


Kulka::~Kulka()
{
	//this->czySkucie = true;
}

void Kulka::read()
{
	if (!ballTexture.loadFromFile("grafika/ball.png"))
		exit(EXIT_FAILURE);
	ball.setRadius(this->radius);
	ball.setTexture(&ballTexture);
}


void Kulka::ballStart(Vector2f position, Vector2f size) //wektory paletki
{
	if (!this->isDrawn)
	{
		std::srand(unsigned int(time(NULL)));
		this->drawnPosition = std::rand() % int(size.x);
		this->isDrawn = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		this->isStarted = true;
		return;
	}
	ball.setPosition(position.x + this->drawnPosition - (ball.getLocalBounds().width / 2), position.y - ball.getLocalBounds().height);
}

void Kulka::movement()
{
	float TimeStep = 0.015f / (this->movementFactor * this->blockFactor * this->difficultyFactor);
	this->timeFrame += this->ballClock.restart().asSeconds();
	for (; this->timeFrame >= TimeStep; this->timeFrame -= TimeStep)
	{
		ball.move(movementVector);
	}
}

CircleShape Kulka::getBall()
{
	return this->ball;
}

float Kulka::getDiameter()
{
	return round(this->radius * 2);
}

Vector2f Kulka::getMovementVector()
{
	return this->movementVector;
}

Vector2f Kulka::getPositionVector()
{
	return this->ball.getPosition();
}

bool Kulka::getIsStarted()
{
	return this->isStarted;
}

float Kulka::getDifficultyFactor()
{
	return this->difficultyFactor;
}

void Kulka::setPosition(float x, float y)
{
	this->ball.setPosition(x, y);
}

void Kulka::setMovementVector(float x, float y)
{
	this->movementVector.x = x;
	this->movementVector.y = y;
}

float Kulka::getMovementFactor()
{
	return this->movementFactor;
}

void Kulka::setMovementFactor(float m)
{
	this->movementFactor = m;
}

void Kulka::setBlockFactor(float m)
{
	this->blockFactor = m;
}

void Kulka::setDifficultyFactor(float m)
{
	this->difficultyFactor = m;
}

void Kulka::resetClock()
{
	this->ballClock.restart();
}

void Kulka::setIsStarted(bool is)
{
	this->isStarted = is;
}

void Kulka::setIsDrawn(bool is)
{
	this->isDrawn = is;
}
