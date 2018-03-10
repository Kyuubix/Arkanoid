#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Blok2
{
public:
	Blok2();
	~Blok2();
	void Wczytaj();
protected:
	Texture teksturaKulki;
	Texture teksturaPaletki;
	Texture teksturaTla;
	Texture teksturaBlok1;
	Texture teksturaBlok2;
	Texture teksturaBlok3;
	Texture teksturaBlok4;
	Texture teksturaBlok5;
};

