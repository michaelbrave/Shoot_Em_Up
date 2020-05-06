/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:59:02 by mbrave            #+#    #+#             */
/*   Updated: 2020/01/19 23:17:53 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameWorld.hpp"
#include "input.hpp"
#include "render.hpp"
#include "coreGameLogic.hpp"

int deathMenu()
{
	int input = 0;
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);

	clear();
	printw("You have died \n");
	printw("press 'q' to quit \n");
	//printw("press '1' to play again \n");
	while (input != 'q')
	{
		input = getch();
		switch (input)
		{
		//case 1:
		//	startGame();
		//	break;
		case 'q':
			printw("bye");
			break;
		}
	}
	return(0);
}


int collisionGrid()
{
	//object 1 vs object 2
	// if same = collision
	return (0);
}

int randomizer(int num)
{
	srand(time(NULL) | (getpid() << 16));
	int ans = rand() % num;
	return (ans);
}

int enemyLogic(GameWorld *gw)
{
	// for (int i = 0; i < 1000; i++)
	// {}
	int rando = rand();
	gw->addEnemy(new Enemy('X', gw->getMaxX()));
	if (randomizer(rando) == 1)
	{
		gw->addEnemy(new Enemy('X', gw->getMaxX()));
	}
	gw->updateEnemies();
	return (0);
}

int coreGameLogic(GameWorld *gw)
{
	gw->collisionChecking();
	usleep(20000);
	// printw("got this far \n");
	// getch();
	enemyLogic(gw);
	return (0);
}

int gamePlaying(GameWorld *gw)
{
	int input = 0;
	while (input != 'q' && gw->getPlayer()->_hit_points > 0) //or until you die
	{
		input = gameInput(gw);
		if (gw->getPlayer()->_hit_points <= 0)
			printw("you have died");
		coreGameLogic(gw);
		render(gw);
	}
	if (gw->getPlayer()->_hit_points <= 0)
		deathMenu();
	return (0);
}

// int colors ()
// {
// 	start_color();
// 	init_pair(1, COLOR_GREEN, COLOR_BLACK);
// 	init_pair(2, COLOR_BLUE, COLOR_BLACK);
// 	init_pair(3, COLOR_WHITE, COLOR_BLACK);
// 	init_pair(4, COLOR_RED, COLOR_BLACK);
// 	attron(COLOR_PAIR (1));
// 	printw("this is a test");
// 	attroff(COLOR_PAIR (1));
// 	return (0);
// }

int startGame()
{
	//colors();
	Player player1('^');
	GameWorld *gm = makeWindow(&player1); // created funciton for organization, see render.cpp
	gamePlaying(gm);
	delete(gm);
	endwin(); // Exit curses mode, important or else strangeness
	return(0);
}

int main()
{
	startGame();
	return (0);
}
