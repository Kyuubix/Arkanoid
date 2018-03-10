#include "Blok1.h"



Blok1::Blok1()
{
	this->fileName = "grafika/blok1.jpg";
	this->factor = 1.0f;
	this->isDestroyed = false;
	read();
}


Blok1::~Blok1()
{
}
