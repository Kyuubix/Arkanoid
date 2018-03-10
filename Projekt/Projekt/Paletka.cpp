#include "Paletka.h"


Paletka::Paletka(float mnPredkosci)
{
	this->speedFactor = mnPredkosci;
	this->time = 0.0f;
	read();
}


Paletka::~Paletka()
{
}

void Paletka::read()
{
	Image PaddleImage;
	if (!PaddleImage.loadFromFile("grafika/paletka.png"))
		exit(EXIT_FAILURE);
	PaddleImage.createMaskFromColor(Color::White, 0);
	paddleTexture.loadFromImage(PaddleImage);
	paddle.setTexture(paddleTexture);
	paddle.setPosition(400, 555);
}

void Paletka::control(Vector2f size)
{
	float TimeStep = 0.005f / this->speedFactor;
	this->time += this->paddleClock.restart().asSeconds();
	for (;  this->time >= TimeStep; this->time -= TimeStep)
	{
		if ((paddle.getPosition().x > 8) && (Keyboard::isKeyPressed(Keyboard::Left)))
				paddle.move(-1, 0);
		if ((paddle.getPosition().x + paddleTexture.getSize().x < size.x - 8)
			&& (Keyboard::isKeyPressed(Keyboard::Right)))
				paddle.move(1, 0);
	}
}

Sprite Paletka::getPaddle()
{
	return this->paddle;
}


Vector2f Paletka::getPositionVector()
{
	return this->paddle.getPosition();
}

Vector2f Paletka::getSizeVector()
{
	Vector2f ret;
	ret.x = this->paddle.getGlobalBounds().width;
	ret.y = this->paddle.getGlobalBounds().height;
	return ret;
}