#include "Gra.h"



Gra::Gra()
{
	this->score = 0;
	this->toScore = SIZE1 + (SIZE2 * 2);
	this->level = 0;
	this->life = 3;
	this->gameState = MAIN_MENU;
	this->isWin = false;
	this->isLose = false;
	this->readBestScore();
}


Gra::~Gra()
{
}

void Gra::readBestScore()
{
	std::fstream file;
	file.open("record.txt", std::ios::in);
	if (!file.good())
		exit(EXIT_FAILURE);
	else
	{
		char tmp[10];
		//file.getline(tmp, 10);
		file >> tmp;
		this->highScore = atoi(tmp);
	}
	file.close();
}

void Gra::paddleBounce(Vector2f position, Vector2f size, Kulka *k) //wektory od paletki
{
	//skucie
	if ((k->getPositionVector().y + k->getDiameter()) >= position.y + 10)
	{
		this->life--;
		k->setIsDrawn(false);
		k->setIsStarted(false);
		if (this->life < 0)
		{
			this->score += (this->life * 5) + int(k->getDifficultyFactor() * 40);
			this->isLose = true;
			this->gameState = END;
		}
	}
	//odbicie
	if ((k->getPositionVector().y + k->getDiameter()) >= position.y)
	{
		if ((k->getPositionVector().x + (k->getDiameter() / 2)) >= position.x
			&& (k->getPositionVector().x + (k->getDiameter() / 2) < position.x + (size.x / 6)))
		{
			k->setMovementVector(-2, -1);
			k->setMovementFactor(PIERW_2);
		}
		if ((k->getPositionVector().x + (k->getDiameter() / 2)) >= position.x + (size.x / 6)
			&& (k->getPositionVector().x + (k->getDiameter() / 2) < position.x + ((size.x / 6) * 2)))
		{
			k->setMovementVector(-1, -1);
			k->setMovementFactor(PIERW_5);
		}
		if ((k->getPositionVector().x + (k->getDiameter() / 2)) >= position.x + ((size.x / 6) * 2)
			&& (k->getPositionVector().x + (k->getDiameter() / 2) < position.x + ((size.x / 6) * 3)))
		{
			k->setMovementVector(-1, -2);
			k->setMovementFactor(PIERW_2);
		}
		if ((k->getPositionVector().x + (k->getDiameter() / 2)) >= position.x + ((size.x / 6) * 3)
			&& (k->getPositionVector().x + (k->getDiameter() / 2) < position.x + ((size.x / 6) * 4)))
		{
			k->setMovementVector(1, -2);
			k->setMovementFactor(PIERW_2);
		}
		if ((k->getPositionVector().x + (k->getDiameter() / 2)) >= position.x + ((size.x / 6) * 4)
			&& (k->getPositionVector().x + (k->getDiameter() / 2) < position.x + ((size.x / 6) * 5)))
		{
			k->setMovementVector(1, -1);
			k->setMovementFactor(PIERW_5);
		}
		if ((k->getPositionVector().x + (k->getDiameter() / 2)) >= position.x + ((size.x / 6) * 5)
			&& (k->getPositionVector().x + (k->getDiameter() / 2) <= position.x + (size.x)))
		{
			k->setMovementVector(2, -1);
			k->setMovementFactor(PIERW_2);
		}
	}
}

void Gra::wallBounce(Vector2f size, Kulka *k) //wektor tla
{
	if ((k->getPositionVector().x <= 8))
	{
		k->setPosition(9, k->getPositionVector().y);
		k->setMovementVector(-k->getMovementVector().x, k->getMovementVector().y);
	}
	if (k->getPositionVector().x + k->getDiameter() >= (size.x - 8))
	{
		k->setPosition(size.x - 9 - k->getDiameter(), k->getPositionVector().y);
		k->setMovementVector(-k->getMovementVector().x, k->getMovementVector().y);
	}
	if (k->getPositionVector().y <= 8)
	{
		k->setPosition(k->getPositionVector().x, 9);
		k->setMovementVector(k->getMovementVector().x, -k->getMovementVector().y);
	}
}


void Gra::blockBounce(Kulka *k, Blok1 *b1, int size1, Blok2 *b2, int size2, Blok5 *b5, int size5)
{
	for (int i = 0; i < size1; i++)
	{
		if (!b1[i].getIsDestroyed()
			&& (k->getPositionVector().x + k->getDiameter() >= b1[i].getPositionVector().x)
			&& (k->getPositionVector().x <= b1[i].getPositionVector().x + b1[i].getSizeVector().x)
			&& (k->getPositionVector().y + (k->getDiameter() / 2) >= b1[i].getPositionVector().y)
			&& (k->getPositionVector().y + (k->getDiameter() / 2) <= b1[i].getPositionVector().y + b1[i].getSizeVector().y))
		{
			b1[i].setIsDestroyed(true);
			k->setMovementVector(-k->getMovementVector().x, k->getMovementVector().y);
			k->setBlockFactor(b1[i].getFactor());
			this->score++;
		}
		if (!b1[i].getIsDestroyed()
			&& (k->getPositionVector().y + k->getDiameter() >= b1[i].getPositionVector().y)
			&& (k->getPositionVector().y <= b1[i].getPositionVector().y + b1[i].getSizeVector().y)
			&& (k->getPositionVector().x + (k->getDiameter() / 2) >= b1[i].getPositionVector().x)
			&& (k->getPositionVector().x + (k->getDiameter() / 2) <= b1[i].getPositionVector().x + b1[i].getSizeVector().x))
		{
			b1[i].setIsDestroyed(true);
			k->setMovementVector(k->getMovementVector().x, -k->getMovementVector().y);
			k->setBlockFactor(b1[i].getFactor());
			this->score++;
		}
	}
	for (int i = 0; i < size2; i++)
	{
		if (!b2[i].getIsDestroyed()
			&& (k->getPositionVector().x + k->getDiameter() >= b2[i].getPositionVector().x)
			&& (k->getPositionVector().x <= b2[i].getPositionVector().x + b2[i].getSizeVector().x)
			&& (k->getPositionVector().y + (k->getDiameter() / 2) >= b2[i].getPositionVector().y)
			&& (k->getPositionVector().y + (k->getDiameter() / 2) <= b2[i].getPositionVector().y + b2[i].getSizeVector().y))
		{
			b2[i].setIsDestroyed(true);
			k->setMovementVector(-k->getMovementVector().x, k->getMovementVector().y);
			k->setBlockFactor(b2[i].getFactor());
			this->score += 2;
		}
		if (!b2[i].getIsDestroyed()
			&& (k->getPositionVector().y + k->getDiameter() >= b2[i].getPositionVector().y)
			&& (k->getPositionVector().y <= b2[i].getPositionVector().y + b2[i].getSizeVector().y)
			&& (k->getPositionVector().x + (k->getDiameter() / 2) >= b2[i].getPositionVector().x)
			&& (k->getPositionVector().x + (k->getDiameter() / 2) <= b2[i].getPositionVector().x + b2[i].getSizeVector().x))
		{
			b2[i].setIsDestroyed(true);
			k->setMovementVector(k->getMovementVector().x, -k->getMovementVector().y);
			k->setBlockFactor(b2[i].getFactor());
			this->score += 2;
		}
	}
	for (int i = 0; i < size5; i++)
	{
		if (!b5[i].getIsDestroyed())
		{
			if ((k->getPositionVector().x + k->getDiameter() >= b5[i].getPositionVector().x)
				&& (k->getPositionVector().x <= b5[i].getPositionVector().x + (b5[i].getSizeVector().x / 2))
				&& (k->getPositionVector().y + (k->getDiameter() / 2) >= b5[i].getPositionVector().y)
				&& (k->getPositionVector().y + (k->getDiameter() / 2) <= b5[i].getPositionVector().y + b5[i].getSizeVector().y))
			{
				k->setPosition(b5[i].getPositionVector().x - k->getDiameter() - 1, k->getPositionVector().y);
				k->setMovementVector(-k->getMovementVector().x, k->getMovementVector().y);
			}
			if ((k->getPositionVector().x <= b5[i].getPositionVector().x + b5[i].getSizeVector().x)
				&& (k->getPositionVector().x + k->getDiameter() >= b5[i].getPositionVector().x + (b5[i].getSizeVector().x / 2))
				&& (k->getPositionVector().y + (k->getDiameter() / 2) >= b5[i].getPositionVector().y)
				&& (k->getPositionVector().y + (k->getDiameter() / 2) <= b5[i].getPositionVector().y + b5[i].getSizeVector().y))
			{
				k->setPosition(b5[i].getPositionVector().x + b5[i].getSizeVector().x + 1, k->getPositionVector().y);
				k->setMovementVector(-k->getMovementVector().x, k->getMovementVector().y);
			}
			if ((k->getPositionVector().y + k->getDiameter() >= b5[i].getPositionVector().y)
				&& (k->getPositionVector().y <= b5[i].getPositionVector().y + (b5[i].getSizeVector().y / 2))
				&& (k->getPositionVector().x + (k->getDiameter() / 2) >= b5[i].getPositionVector().x)
				&& (k->getPositionVector().x + (k->getDiameter() / 2) <= b5[i].getPositionVector().x + b5[i].getSizeVector().x))
			{
				k->setPosition(k->getPositionVector().x, b5[i].getPositionVector().y - k->getDiameter() - 1);
				k->setMovementVector(k->getMovementVector().x, -k->getMovementVector().y);
			}
			if ((k->getPositionVector().y + k->getDiameter() >= b5[i].getPositionVector().y)
				&& (k->getPositionVector().y <= b5[i].getPositionVector().y + b5[i].getSizeVector().y)
				&& (k->getPositionVector().x + (k->getDiameter() / 2) >= b5[i].getPositionVector().x)
				&& (k->getPositionVector().x + (k->getDiameter() / 2) <= b5[i].getPositionVector().x + b5[i].getSizeVector().x))
			{
				k->setPosition(k->getPositionVector().x, b5[i].getPositionVector().y + b5[i].getSizeVector().y + 1);
				k->setMovementVector(k->getMovementVector().x, -k->getMovementVector().y);
			}
		}
	}
}

void Gra::Level1(Blok1* b1, Blok2* b2, Blok5* b5)
{
	int lines = 13;
	int columns = 6;
	for (int i = 0; i < columns; i++)
		for (int j = 0; j < lines; j++)
		{
			if (i < (columns / 2))
				b1[i * lines + j].setPosition(float(60 + (40 * i)), float(40 + (20 * j)));
			else
				b1[i * lines + j].setPosition(float(700 - (40 * (i - 3))), float(40 + (20 * j)));
		}
	columns = 4;
	for (int i = 0; i < columns; i++)
		for (int j = 0; j < lines; j++)
		{
			if (i < columns / 2)
				b2[i * lines + j].setPosition(float(220 + (40 * i)), float(80 + (20 * j)));
			else
				b2[i * lines + j].setPosition(float(540 - (40 * (i - 2))), float(80 + (20 * j)));
		}
	columns = 2;
	for (int i = 0; i < columns; i++)
		for (int j = 0; j < lines; j++)
		{
			if (i < columns / 2)
				b5[i * lines + j].setPosition(float(340 + (40 * i)), float(120 + (20 * j)));
			else
				b5[i * lines + j].setPosition(float(420 - (40 * (i - 1))), float(120 + (20 * j)));
		}
}

void Gra::Closing(RenderWindow *w)
{
	while (w->pollEvent(this->closeEvent))
	{
		if (this->closeEvent.type == Event::Closed)
			w->close();
	}
}

void Gra::Pause()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
			this->setGameState(PAUSE);
}

void Gra::Victory(Kulka *k)
{
	if (this->score >= this->toScore)
	{
		this->score += (this->life * 10) + int(k->getDifficultyFactor() * k->getDifficultyFactor() * 25);
		this->gameState = END;
		this->isWin = true;
	}
}

void Gra::saveBestScore()
{
	this->highScore = this->score;
	std::fstream file;
	file.open("record.txt", std::ios::out);
	if (!file.good())
		exit(EXIT_FAILURE);
	else
		file << this->highScore;
	file.close();
}

int Gra::getScore()
{
	return this->score;
}

int Gra::getLevel()
{
	return this->level;
}

int Gra::getGameState()
{
	return this->gameState;
}

bool Gra::getIsWin()
{
	return this->isWin;
}

bool Gra::getIsLose()
{
	return this->isLose;
}

int Gra::getLife()
{
	return this->life;
}

int Gra::getHighScore()
{
	return this->highScore;
}

void Gra::setLevel(int a)
{
	this->level = a;
}

void Gra::setGameState(int nr)
{
	this->gameState = nr;
}

void Gra::setIsWin(bool is)
{
	this->isWin = is;
}

void Gra::setIsLose(bool is)
{
	this->isLose = is;
}

void Gra::setScore(int a)
{
	this->score = a;
}

void Gra::setLife(int a)
{
	this->life = a;
}

void Gra::setHighScore(int a)
{
	this->highScore = a;
}