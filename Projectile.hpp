/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:58:38 by mbrave            #+#    #+#             */
/*   Updated: 2020/01/19 18:00:27 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "GameObject.hpp"

class Player;
class Enemy;

class Projectile : public GameObject
{
private:
	int _minus;

public:
	Projectile(void);
	Projectile(Player *p);
	Projectile(Enemy *e);
	Projectile(const Projectile &Projectile);
	Projectile &operator=(const Projectile &Projectile);
	~Projectile(void);
	void move();
};

#endif
