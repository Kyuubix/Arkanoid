#include "Gui.h"



Gui::Gui()
{
	readTexture();
	readFont();
	readTextMenu();
	readTextGame();
	this->pauseBackground.setFillColor(Color(dark));
	this->pauseBackground.setSize(Vector2f(800, 600));
	this->pauseBackground.setPosition(0, 0);
}


Gui::~Gui()
{
}

void Gui::readTexture()
{
	if (!this->backgroundTexture.loadFromFile("grafika/tlo.jpg"))
		exit(EXIT_FAILURE);
	this->background.setTexture(this->backgroundTexture);
	background.setPosition(0, 0);
	if (!this->menuTexture.loadFromFile("grafika/menu.jpg"))
		exit(EXIT_FAILURE);
	this->menu.setTexture(this->menuTexture);
	menu.setPosition(0, 0);
}

void Gui::readFont()
{
	if (!this->fontMenu.loadFromFile("czcionka/impact.ttf"))
		exit(EXIT_FAILURE);
	if (!this->fontGame.loadFromFile("czcionka/pala.ttf"))
		exit(EXIT_FAILURE);
}

void Gui::readTextMenu()
{
	textMenu[0].setFont(fontMenu);
	textMenu[0].setCharacterSize(60);
	textMenu[0].setStyle(Text::Bold);
	textMenu[0].setString("Wreacking Ball Arkanoid");
	textMenu[0].setFillColor(silver);
	textMenu[0].setOutlineColor(Color::Blue);
	textMenu[0].setOutlineThickness(3);
	textMenu[0].setPosition(400 - (textMenu[0].getGlobalBounds().width / 2), 60);

	textMenu[1].setFont(fontMenu);
	textMenu[1].setCharacterSize(50);
	textMenu[1].setStyle(Text::Bold);
	textMenu[1].setString("PLAY");
	textMenu[1].setFillColor(gray);
	textMenu[1].setOutlineThickness(2);
	textMenu[1].setPosition(400 - (textMenu[1].getGlobalBounds().width / 2), 230);

	textMenu[2].setFont(fontMenu);
	textMenu[2].setCharacterSize(50);
	textMenu[2].setStyle(Text::Bold);
	textMenu[2].setString("HIGH SCORES");
	textMenu[2].setFillColor(gray);
	textMenu[2].setOutlineThickness(2);
	textMenu[2].setPosition(400 - (textMenu[2].getGlobalBounds().width / 2), 350);

	textMenu[3].setFont(fontMenu);
	textMenu[3].setCharacterSize(50);
	textMenu[3].setStyle(Text::Bold);
	textMenu[3].setString("QUIT");
	textMenu[3].setFillColor(gray);
	textMenu[3].setOutlineThickness(2);
	textMenu[3].setPosition(400 - (textMenu[3].getGlobalBounds().width / 2), 470);

	textMenu[4].setFont(fontMenu);
	textMenu[4].setCharacterSize(35);
	textMenu[4].setString("LEVEL 1");
	textMenu[4].setFillColor(gray);
	textMenu[4].setOutlineThickness(2);
	textMenu[4].setPosition(200 - (textMenu[4].getGlobalBounds().width / 2), 250);

	textMenu[5].setFont(fontMenu);
	textMenu[5].setCharacterSize(35);
	textMenu[5].setString("LEVEL 2");
	textMenu[5].setFillColor(gray);
	textMenu[5].setOutlineThickness(2);
	textMenu[5].setPosition(400 - (textMenu[5].getGlobalBounds().width / 2), 250);

	textMenu[6].setFont(fontMenu);
	textMenu[6].setCharacterSize(35);
	textMenu[6].setString("LEVEL 3");
	textMenu[6].setFillColor(gray);
	textMenu[6].setOutlineThickness(2);
	textMenu[6].setPosition(600 - (textMenu[6].getGlobalBounds().width / 2), 250);

	textMenu[7].setFont(fontMenu);
	textMenu[7].setCharacterSize(35);
	textMenu[7].setString("EASY");
	textMenu[7].setFillColor(gray);
	textMenu[7].setOutlineThickness(2);
	textMenu[7].setPosition(200 - (textMenu[7].getGlobalBounds().width / 2), 350);

	textMenu[8].setFont(fontMenu);
	textMenu[8].setCharacterSize(35);
	textMenu[8].setString("MEDIUM");
	textMenu[8].setFillColor(gray);
	textMenu[8].setOutlineThickness(2);
	textMenu[8].setPosition(400 - (textMenu[8].getGlobalBounds().width / 2), 350);

	textMenu[9].setFont(fontMenu);
	textMenu[9].setCharacterSize(35);
	textMenu[9].setString("HARD");
	textMenu[9].setFillColor(gray);
	textMenu[9].setOutlineThickness(2);
	textMenu[9].setPosition(600 - (textMenu[9].getGlobalBounds().width / 2), 350);

	textMenu[10].setFont(fontMenu);
	textMenu[10].setCharacterSize(50);
	textMenu[10].setString("START");
	textMenu[10].setFillColor(gray);
	textMenu[10].setPosition(600 - (textMenu[10].getGlobalBounds().width / 2), 480);

	textMenu[11].setFont(fontMenu);
	textMenu[11].setCharacterSize(50);
	textMenu[11].setString("BACK");
	textMenu[11].setFillColor(gray);
	textMenu[11].setPosition(200 - (textMenu[11].getGlobalBounds().width / 2), 480);

	textMenu[12].setFont(fontMenu);
	textMenu[12].setCharacterSize(50);
	textMenu[12].setString("RESUME");
	textMenu[12].setFillColor(gray);
	textMenu[12].setOutlineThickness(1);
	textMenu[12].setOutlineColor(Color::Black);
	textMenu[12].setPosition(400 - (textMenu[12].getGlobalBounds().width / 2), 160);

	textMenu[13].setFont(fontMenu);
	textMenu[13].setCharacterSize(50);
	textMenu[13].setString("MAIN MENU");
	textMenu[13].setFillColor(gray);
	textMenu[13].setOutlineThickness(1);
	textMenu[13].setOutlineColor(Color::Black);
	textMenu[13].setPosition(400 - (textMenu[13].getGlobalBounds().width / 2), 410);
}

void Gui::readTextGame()
{
	textGame[0].setFont(fontGame);
	textGame[0].setCharacterSize(15);
	textGame[0].setStyle(Text::Bold);
	textGame[0].setString("SCORE");
	textGame[0].setPosition(100, 575);
	textGame[0].setFillColor(gray);
	textGame[0].setOutlineColor(Color::Blue);
	textGame[0].setOutlineThickness(1);

	textGame[1].setFont(fontGame);
	textGame[1].setCharacterSize(15);
	textGame[1].setStyle(Text::Bold);
	textGame[1].setPosition(180, 575);
	textGame[1].setFillColor(gray);
	textGame[1].setOutlineColor(Color::Blue);
	textGame[1].setOutlineThickness(1);

	textGame[2].setFont(fontGame);
	textGame[2].setCharacterSize(140);
	textGame[2].setStyle(Text::Bold);
	textGame[2].setFillColor(silver);
	textGame[2].setOutlineThickness(4);

	textGame[3].setFont(fontGame);
	textGame[3].setCharacterSize(50);
	textGame[3].setStyle(Text::Bold);
	textGame[3].setString("YOUR SCORE:");
	textGame[3].setPosition(180, 575);
	textGame[3].setPosition(400 - (textGame[3].getGlobalBounds().width / 2) - 20, 250);
	textGame[3].setFillColor(gray);
	textGame[3].setOutlineColor(Color::Blue);
	textGame[3].setOutlineThickness(1);

	textGame[4].setFont(fontGame);
	textGame[4].setCharacterSize(50);
	textGame[4].setStyle(Text::Bold);
	textGame[4].setPosition(180, 575);
	textGame[4].setPosition(400 + (textGame[3].getGlobalBounds().width / 2), 250);
	textGame[4].setFillColor(gray);
	textGame[4].setOutlineColor(Color::Blue);
	textGame[4].setOutlineThickness(1);

	textGame[5].setFont(fontGame);
	textGame[5].setCharacterSize(15);
	textGame[5].setStyle(Text::Bold);
	textGame[5].setString("LIFE");
	textGame[5].setPosition(610, 575);
	textGame[5].setFillColor(gray);
	textGame[5].setOutlineColor(Color::Blue);
	textGame[5].setOutlineThickness(1);

	textGame[6].setFont(fontGame);
	textGame[6].setCharacterSize(15);
	textGame[6].setStyle(Text::Bold);
	textGame[6].setPosition(680, 575);
	textGame[6].setFillColor(gray);
	textGame[6].setOutlineColor(Color::Blue);
	textGame[6].setOutlineThickness(1);

	textGame[7].setFont(fontGame);
	textGame[7].setCharacterSize(30);
	textGame[7].setStyle(Text::Bold);
	textGame[7].setString("NEW RECORD!");
	textGame[7].setPosition(180, 575);
	textGame[7].setPosition(400 - (textGame[7].getGlobalBounds().width / 2), 330);
	textGame[7].setFillColor(gray);
	textGame[7].setOutlineColor(Color::Blue);
	textGame[7].setOutlineThickness(1);

	textGame[8].setFont(fontGame);
	textGame[8].setCharacterSize(50);
	textGame[8].setStyle(Text::Bold);
	textGame[8].setString("BEST SCORE:");
	textGame[8].setPosition(180, 575);
	textGame[8].setPosition(400 - (textGame[3].getGlobalBounds().width / 2) - 20, 280);
	textGame[8].setFillColor(gray);
	textGame[8].setOutlineColor(Color::Blue);
	textGame[8].setOutlineThickness(1);

	textGame[9].setFont(fontGame);
	textGame[9].setCharacterSize(50);
	textGame[9].setStyle(Text::Bold);
	textGame[9].setPosition(180, 575);
	textGame[9].setPosition(400 + (textGame[8].getGlobalBounds().width / 2), 280);
	textGame[9].setFillColor(gray);
	textGame[9].setOutlineColor(Color::Blue);
	textGame[9].setOutlineThickness(1);
}

void Gui::updateScoreLife(int score, int life)
{
	textGame[1].setString(std::to_string(score));
	textGame[6].setString(std::to_string(life));
}

void Gui::updateEndScore(int score)
{
	textGame[4].setString(std::to_string(score));
}

void Gui::updateHighScore(int score)
{
	textGame[9].setString(std::to_string(score));
}

void Gui::textBacklight(int nr, Vector2f mouse)
{
	for (int i = 1; i <= nr; i++)
		if (textMenu[i].getGlobalBounds().contains(mouse))
			textMenu[i].setFillColor(silver);
		else
			textMenu[i].setFillColor(gray);
}

void Gui::textCenter(int nr)
{
	textGame[nr].setPosition(400 - (textGame[nr].getGlobalBounds().width / 2), 50);
}

//Przyciski

void Gui::onPlayClick(Vector2f mouse, Gra *game)
{
	if ((Mouse::isButtonPressed(sf::Mouse::Left)) && (textMenu[1].getGlobalBounds().contains(mouse)))
		game->setGameState(SELECTION);
}

void Gui::onExitClick(Vector2f mouse)
{
	if ((Mouse::isButtonPressed(sf::Mouse::Left)) && (textMenu[3].getGlobalBounds().contains(mouse)))
		exit(EXIT_SUCCESS);
}


void Gui::onLevelClick(Vector2f mouse, Gra *game)
{
	if (Mouse::isButtonPressed(sf::Mouse::Left))
	{
		for (int i = 0; i < 3; i++)
		{
			if (textMenu[4 + (i % 3)].getGlobalBounds().contains(mouse))
			{
				game->setLevel((i % 3) + 1);
				textMenu[4 + (i % 3)].setFillColor(silver);
				textMenu[4 + (i % 3)].setOutlineColor(Color::Red);
				textMenu[4 + ((i + 1) % 3)].setFillColor(gray);
				textMenu[4 + ((i + 2) % 3)].setFillColor(gray);
				textMenu[4 + ((i + 1) % 3)].setOutlineColor(Color::Black);
				textMenu[4 + ((i + 2) % 3)].setOutlineColor(Color::Black);
			}
		}
	}
}

void Gui::onDifficultyClick(Vector2f mouse, Kulka *k, Gra *game)
{
	if (Mouse::isButtonPressed(sf::Mouse::Left))
	{
		for (int i = 0; i < 3; i++)
		{
			if (textMenu[7 + (i % 3)].getGlobalBounds().contains(mouse))
			{
				switch (i % 3)
				{
				case 0:
					k->setDifficultyFactor(1.0f);
					game->setLife(3);
					break;
				case 1:
					k->setDifficultyFactor(1.2f);
					game->setLife(2);
					break;
				case 2:
					k->setDifficultyFactor(1.4f);
					game->setLife(1);
					break;
				}
				textMenu[7 + (i % 3)].setFillColor(silver);
				textMenu[7 + (i % 3)].setOutlineColor(Color::Red);
				textMenu[7 + ((i + 1) % 3)].setFillColor(gray);
				textMenu[7 + ((i + 2) % 3)].setFillColor(gray);
				textMenu[7 + ((i + 1) % 3)].setOutlineColor(Color::Black);
				textMenu[7 + ((i + 2) % 3)].setOutlineColor(Color::Black);
			}
		}
	}

}

void Gui::onStartClick(Vector2f mouse, Gra *game)
{
	if ((Mouse::isButtonPressed(sf::Mouse::Left)) && (textMenu[10].getGlobalBounds().contains(mouse)))
	{
		game->setGameState(GAME);
		for (int i = 0; i < 3; i++)
		{
			textMenu[4 + i].setOutlineColor(Color::Black);
			textMenu[7 + i].setOutlineColor(Color::Black);
		}
	}

}

void Gui::onBackClick(Vector2f mouse, Gra *game)
{
	if ((Mouse::isButtonPressed(sf::Mouse::Left)) && (textMenu[11].getGlobalBounds().contains(mouse)))
		game->setGameState(MAIN_MENU);
}

void Gui::onResumeClick(Vector2f mouse, Gra *game, Kulka *k)
{
	if ((Mouse::isButtonPressed(sf::Mouse::Left)) && (textMenu[12].getGlobalBounds().contains(mouse)))
	{
		game->setGameState(GAME);
		k->resetClock();
	}
}

void Gui::onMenuClick(Vector2f mouse, Gra *game, Kulka *k, Blok1 *b1, Blok2 *b2, Blok5 *b5)
{
	if ((Mouse::isButtonPressed(sf::Mouse::Left)) && (textMenu[13].getGlobalBounds().contains(mouse)))
	{
		game->setGameState(MAIN_MENU);
		game->setLevel(0);
		game->setScore(0);
		game->setIsWin(false);
		game->setIsLose(false);
		k->setIsDrawn(false);
		k->setIsStarted(false);
		k->setBlockFactor(1.0f);
		for (int i = 0; i < SIZE1; i++)
			b1[i].setIsDestroyed(false);
		for (int i = 0; i < SIZE2; i++)
			b2[i].setIsDestroyed(false);
		for (int i = 0; i < SIZE3; i++)
			b5[i].setIsDestroyed(false);
	}
}

void Gui::onHighScoresClick(Vector2f mouse, Gra *game)
{
	if ((Mouse::isButtonPressed(sf::Mouse::Left)) && (textMenu[2].getGlobalBounds().contains(mouse)))
		game->setGameState(HIGH_SCORES);
}

Sprite Gui::getBackground()
{
	return this->background;
}

RectangleShape Gui::getPauseBackground()
{
	return this->pauseBackground;
}

Sprite Gui::getMenu()
{
	return this->menu;
}

Vector2f Gui::getSizeVector()
{
	Vector2f ret;
	ret.x = this->background.getGlobalBounds().width;
	ret.y = this->background.getGlobalBounds().height;
	return ret;
}

Text Gui::getTextMenu(int nr)
{
	return this->textMenu[nr];
}

Text Gui::getTextGame(int nr)
{
	return this->textGame[nr];
}

void Gui::setTextGame(int nr, char* name, Color color)
{
	textGame[nr].setString(name);
	textGame[nr].setOutlineColor(color);
}