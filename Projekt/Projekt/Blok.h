#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Blok
{
protected:
	Sprite block;
	Texture blockTexture;
	float factor;
	bool isDestroyed;
	char* fileName;
public:
	Blok();
	~Blok();
	void read();
	//Getter
	Sprite getBlock();
	bool getIsDestroyed();
	Vector2f getPositionVector();
	Vector2f getSizeVector();
	float getFactor();
	//Setter
	void setPosition(float x, float y);
	void setIsDestroyed(bool is);
};

