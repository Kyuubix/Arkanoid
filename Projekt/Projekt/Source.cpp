#include <SFML/Graphics.hpp>
#include "Kulka.h"
#include "Paletka.h"
#include "Gui.h"
#include "Blok.h"
#include "Blok1.h"
#include "Blok2.h"
#include "Blok3.h"
#include "Blok4.h"
#include "Blok5.h"
#include "Gra.h"
#include <iostream>


using namespace sf;

void main()
{
	Kulka k;
	Paletka p;
	Gra game;
	Gui gui;
	Blok1 b1[SIZE1];
	Blok2 b2[SIZE2];
	Blok5 b5[SIZE3];
	RenderWindow windowAplication(VideoMode(800, 600, 32), "WRECKING BALL Beta 1.2");
	game.Level1(b1, b2, b5);
	while (windowAplication.isOpen())
	{
		Vector2f mousePosition(Mouse::getPosition(windowAplication));
		game.Closing(&windowAplication);
		switch (game.getGameState())
		{
		case MAIN_MENU:
			gui.onPlayClick(mousePosition, &game);
			gui.onHighScoresClick(mousePosition, &game);
			gui.onExitClick(mousePosition);
			gui.textBacklight(3, mousePosition);
			windowAplication.draw(gui.getMenu());
			windowAplication.draw(gui.getTextMenu(0));
			windowAplication.draw(gui.getTextMenu(1));
			windowAplication.draw(gui.getTextMenu(2));
			windowAplication.draw(gui.getTextMenu(3));
			windowAplication.display();
			break;
		case HIGH_SCORES:
			gui.textBacklight(13, mousePosition);
			gui.updateHighScore(game.getHighScore());
			gui.onMenuClick(mousePosition, &game, &k, b1, b2, b5);
			windowAplication.draw(gui.getMenu());
			windowAplication.draw(gui.getTextMenu(0));
			windowAplication.draw(gui.getTextMenu(13));
			windowAplication.draw(gui.getTextGame(8));
			windowAplication.draw(gui.getTextGame(9));
			windowAplication.display();
			break;
		case SELECTION:
			gui.textBacklight(11, mousePosition);
			gui.onLevelClick(mousePosition, &game);
			gui.onDifficultyClick(mousePosition, &k, &game);
			gui.onStartClick(mousePosition, &game);
			gui.onBackClick(mousePosition, &game);
			windowAplication.draw(gui.getMenu());
			windowAplication.draw(gui.getTextMenu(0));
			windowAplication.draw(gui.getTextMenu(4));
			windowAplication.draw(gui.getTextMenu(5));
			windowAplication.draw(gui.getTextMenu(6));
			windowAplication.draw(gui.getTextMenu(7));
			windowAplication.draw(gui.getTextMenu(8));
			windowAplication.draw(gui.getTextMenu(9));
			windowAplication.draw(gui.getTextMenu(10));
			windowAplication.draw(gui.getTextMenu(11));
			windowAplication.display();
			break;
		case GAME:
			game.Victory(&k);
			gui.updateScoreLife(game.getScore(), game.getLife());
			p.control(gui.getSizeVector());
			game.wallBounce(gui.getSizeVector(), &k);
			game.blockBounce(&k, b1, SIZE1, b2, SIZE2, b5, SIZE3);
			if (k.getIsStarted())
				game.paddleBounce(p.getPositionVector(), p.getSizeVector(), &k);
			else
				k.ballStart(p.getPositionVector(), p.getSizeVector());
			windowAplication.clear();
			windowAplication.draw(gui.getBackground());
			if (!(game.getIsLose() || game.getIsWin()))
			{
				k.movement();
				windowAplication.draw(k.getBall());
			}
			windowAplication.draw(p.getPaddle());
			for (int i = 0; i < SIZE1; i++)
				if (!b1[i].getIsDestroyed())
					windowAplication.draw(b1[i].getBlock());
			for (int i = 0; i < SIZE2; i++)
				if (!b2[i].getIsDestroyed())
					windowAplication.draw(b2[i].getBlock());
			for (int i = 0; i < SIZE3; i++)
				if (!b5[i].getIsDestroyed())
					windowAplication.draw(b5[i].getBlock());
			windowAplication.draw(gui.getTextGame(0));
			windowAplication.draw(gui.getTextGame(1));
			windowAplication.draw(gui.getTextGame(5));
			windowAplication.draw(gui.getTextGame(6));
			windowAplication.display();	
			game.Pause();
			break;
		case PAUSE:
			gui.textBacklight(13, mousePosition);
			gui.onResumeClick(mousePosition, &game, &k);
			gui.onMenuClick(mousePosition, &game, &k, b1, b2, b5);
			windowAplication.draw(gui.getPauseBackground());
			windowAplication.draw(gui.getTextMenu(12));
			windowAplication.draw(gui.getTextMenu(13));
			windowAplication.display();
			break;
		case END:
			if (game.getIsWin())
				gui.setTextGame(2, "You win!", Color::Green);
			if (game.getIsLose())
				gui.setTextGame(2, "You lose :(", Color::Red);
			gui.textCenter(2);
			gui.updateEndScore(game.getScore());
			gui.textBacklight(13, mousePosition);
			gui.onMenuClick(mousePosition, &game, &k, b1, b2, b5);
			windowAplication.draw(gui.getMenu());
			windowAplication.draw(gui.getTextGame(2));
			windowAplication.draw(gui.getTextGame(3));
			windowAplication.draw(gui.getTextGame(4));
			if (game.getHighScore() <= game.getScore())
			{
				windowAplication.draw(gui.getTextGame(7));
				game.saveBestScore();
			}
			windowAplication.draw(gui.getTextMenu(13));
			windowAplication.display();
			break;
		}
	}
}