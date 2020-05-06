/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:58:46 by mbrave            #+#    #+#             */
/*   Updated: 2020/01/19 17:59:42 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.hpp"

int gameInput(GameWorld *gw)
{
    int input = 0;
    noecho(); // Suppress the automatic echoing of typed characters, to have more control
    cbreak(); // one character at a time
    //    halfdelay(5); //timing based movement. I think this might be a bonus. But it's better.
    nodelay(stdscr, TRUE); // allows getch to work in a non blocking manner
    keypad(stdscr, TRUE);  //capture special keystrokes like Backspace or Delete or arrow keys, stdscr == standard screen
    curs_set(0);           //makes the cursor disappear
    input = getch();       // Wait for user input, one time
    switch (input)
    {
    case 'q':
        printw("exiting \n");
        break;
    case KEY_LEFT:
        gw->getPlayer()->_x_cord -= 2;
        if (gw->getPlayer()->_x_cord < 0)
            gw->getPlayer()->_x_cord = 0;
        break;
    case KEY_RIGHT:
        gw->getPlayer()->_x_cord += 2;
        if (gw->getPlayer()->_x_cord > gw->getMaxX())
            gw->getPlayer()->_x_cord = gw->getMaxX();
        break;
    case KEY_UP:
        gw->getPlayer()->_y_cord--;
        if (gw->getPlayer()->_y_cord < 0)
            gw->getPlayer()->_y_cord = 0;
        break;
    case KEY_DOWN:
        gw->getPlayer()->_y_cord++;
        if (gw->getPlayer()->_y_cord > gw->getMaxY())
            gw->getPlayer()->_y_cord = gw->getMaxY();
        break;
    case 'a':
        gw->getPlayer()->_x_cord -= 2;
        if (gw->getPlayer()->_x_cord < 0)
            gw->getPlayer()->_x_cord = 0;
        break;
    case 'd':
        gw->getPlayer()->_x_cord += 2;
        if (gw->getPlayer()->_x_cord > gw->getMaxX())
            gw->getPlayer()->_x_cord = gw->getMaxX();
        break;
    case 'w':
        gw->getPlayer()->_y_cord--;
        if (gw->getPlayer()->_y_cord < 0)
            gw->getPlayer()->_y_cord = 0;
        break;
    case 's':
        gw->getPlayer()->_y_cord++;
        if (gw->getPlayer()->_y_cord > gw->getMaxY())
            gw->getPlayer()->_y_cord = gw->getMaxY();
        break;
    case 32:
        gw->addProjectile(gw->getPlayer()->shoot());
        break;
    default:
        break;
    }
    return (input);
}
