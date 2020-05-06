/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:59:10 by mbrave            #+#    #+#             */
/*   Updated: 2020/01/19 23:33:05 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.hpp"
#include "art.hpp"

static int starcounter;

int makeStars(GameWorld *gw)
{
    starcounter = 4;
	int i = 20;
    int b = 0;
	int x = randomizer(gw->getMaxX());
	int y = randomizer(gw->getMaxY());
	b = starCount % starcounter;
	if (b == 0)
		b = 1;
	if (((starcounter + starCount) % 2) == 0)
		while (i-- >= 20)
		{
			mvprintw(y, x, "%c", star1);
			wrefresh(stdscr);
			y += 2;
		}
	else if (((starcounter + starCount) % 3) == 0)
		while (i-- >= 20)
		{
			mvprintw(y++, x, "%c", star2);
			wrefresh(stdscr);
			y += 2;
		}
	else if (((starcounter + starCount) % 5) == 0)
		while (i-- >= 20)
		{
			mvprintw(y++, x, "%c", star3);
			wrefresh(stdscr);
			y += 2;
		}
	else if (((starcounter + starCount) % 7) == 0)
		while (i-- >= 20)
		{
			mvprintw(y++, x, "%c", star4);
			wrefresh(stdscr);
			y += 2;
		}
	// else if ((i + starCount) % 13 == 0)
	//     mvprintw(randomizer(gw->getMaxY()), randomizer(gw->getMaxX()), "%s", star5);
	// else if ((i + starCount) % 17 == 0)
	//     mvprintw(randomizer(gw->getMaxY()), randomizer(gw->getMaxX()), "%s", star6);
	starCount += 13;
	if (starCount == gw->getMaxX())
		starCount = 11;
	else
		starCount = randomizer(starCount / b);
	return (0);
}

int render(GameWorld *gw)
{
	//raw();						// Line buffering disabled
	clear();
	box(gw->_menu, ' ', 0);
	time_t now = time(0);
	mvwprintw(gw->_menu, 3, 1, "Lives: %d\n", gw->getPlayer()->_hit_points);
	mvwprintw(gw->_menu, 3, gw->getMaxX() / 3, "Score: %d\n", gw->getPlayer()->score);
	mvwprintw(gw->_menu, 3, (gw->getMaxX() / 3) * 2, "Time: %d\n", (int)difftime(now, gw->_clockpace));
	makeStars(gw);
	gw->renderEnemies();
	mvprintw(gw->getPlayer()->_y_cord, gw->getPlayer()->_x_cord, "%c", gw->getPlayer()->getSymbol()); //why can't i get this to work with the object?
	wrefresh(stdscr);																				  // Print it on to the real screen, only refreshes what's been changed, important
	wrefresh(gw->_menu);
	return 0;
}

GameWorld *makeWindow(Player *player)
{
	int max_col;
	int max_row;
	initscr();							// Startd curses mode, important
	getmaxyx(stdscr, max_col, max_row); //gives the number of columns and the number of rows in a given window
	WINDOW * menuwin = newwin(6, max_col - 6, 3, 3);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);
	player->StartPosition(max_col, max_row);
	time_t now = time(0);
	BigBoss *bb = new BigBoss(max_row);
	GameWorld *gm = new GameWorld(player, bb, max_row, max_col, menuwin, now);

	//	resize_term(max_row, max_col);
	//populate(max_row, max_col);
	return (gm);
}
