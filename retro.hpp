#ifndef RETRO_HPP
#define RETRO_HPP

#include <ncurses.h> //Master.hpp // ncurses.h includes stdio.h
#include <stdlib.h>
#include <iostream> //panel, menu and form extend the curses library
#include <unistd.h>
#include <ctime>
// #include "GameObject.hpp"
// #include "GameWorld.hpp"
// #include "Enemy.hpp"
// #include "Player.hpp"
// #include "Projectile.hpp"

// class GameWorld;
// class GameObject;
// class Enemy;
// class Player;
// class Projectile;

int randomizer(int num);
int deathMenu();
int startGame();

#endif
