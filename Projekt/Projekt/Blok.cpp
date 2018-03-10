#include "Blok.h"



Blok::Blok()
{
}


Blok::~Blok()
{
}

void Blok::read()
{
	if (!blockTexture.loadFromFile(fileName))
		exit(EXIT_FAILURE);
	block.setTexture(blockTexture);
}

Sprite Blok::getBlock()
{
	return this->block;
}

bool Blok::getIsDestroyed()
{
	return this->isDestroyed;
}

Vector2f Blok::getPositionVector()
{
	return this->block.getPosition();
}

Vector2f Blok::getSizeVector()
{
	Vector2f ret;
	ret.y = this->block.getGlobalBounds().height;
	ret.x = this->block.getGlobalBounds().width;
	return ret;
}

float Blok::getFactor()
{
	return this->factor;
}

void Blok::setPosition(float x, float y)
{
	block.setPosition(x, y);
}

void Blok::setIsDestroyed(bool is)
{
	this->isDestroyed = is;
}