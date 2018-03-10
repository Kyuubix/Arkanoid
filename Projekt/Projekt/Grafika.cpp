#include "Grafika.h"



Blok2::Blok2()
{
	Wczytaj();
}


Blok2::~Blok2()
{
}

void Blok2::Wczytaj()
{
	if (!teksturaKulki.loadFromFile("grafika/ball.jpg"))
		exit (EXIT_FAILURE);
	if (!teksturaTla.loadFromFile("grafika/tlo.jpg"))
		exit(EXIT_FAILURE);
	if (!teksturaBlok1.loadFromFile("grafika/blok1.jpg"))
		exit(EXIT_FAILURE);
	if (!teksturaBlok2.loadFromFile("grafika/blok2.jpg"))
		exit(EXIT_FAILURE);
	if (!teksturaBlok3.loadFromFile("grafika/blok3.jpg"))
		exit(EXIT_FAILURE);
	if (!teksturaBlok4.loadFromFile("grafika/blok4.jpg"))
		exit(EXIT_FAILURE);
	if (!teksturaBlok5.loadFromFile("grafika/blok5.jpg"))
		exit(EXIT_FAILURE);
	Image zdjeciePaletki;
	if (!zdjeciePaletki.loadFromFile("grafika/paletka.jpg"))
		exit(EXIT_FAILURE);
	else
	{
		zdjeciePaletki.createMaskFromColor(Color::White, 0);
		teksturaPaletki.loadFromImage(zdjeciePaletki);
	}
}
