#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Paletka
{
private:
	Sprite paddle;
	Texture paddleTexture;
	Clock paddleClock;
	float time;             //czas jednej klatki
	float speedFactor;
public:
	Paletka(float mnPredkosci = 1.4);
	~Paletka();
	void read();
	void control(Vector2f rozmiar);
	//Gettery
	Sprite getPaddle();
	Vector2f getPositionVector();
	Vector2f getSizeVector();
};

