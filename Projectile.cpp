/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:58:31 by mbrave            #+#    #+#             */
/*   Updated: 2020/01/19 21:21:22 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

// ----------- Child Class Projectile ----------- //

Projectile::Projectile(void) {}

Projectile::Projectile(Player *p)
{
	_symbol = '|';
	_y_cord = p->_y_cord;
	_x_cord = p->_x_cord;
	_hit_points = 1;
	_max_hit_points = 1;
	_minus = 0;
}

Projectile::Projectile(Enemy *e)
{
	_symbol = '|';
	_y_cord = e->_y_cord;
	_x_cord = e->_x_cord;
	_hit_points = 1;
	_max_hit_points = 1;
	_minus = 1;
}

Projectile::~Projectile()
{
}

Projectile::Projectile(const Projectile &p)
{
	*this = p;
}

Projectile &Projectile::operator=(const Projectile &ProjectileObj)
{
	if (this != &ProjectileObj)
	{
		this->_symbol = ProjectileObj._symbol;
		this->_y_cord = ProjectileObj._y_cord;
		this->_x_cord = ProjectileObj._x_cord;
		this->_hit_points = ProjectileObj._hit_points;
		this->_hit_points = ProjectileObj._minus;
	}
	return (*this);
}

void Projectile::move()
{
	if (_minus == 0)
		_y_cord--;
	else
		_y_cord++;
}