#ifndef BIGBOSS_HPP
#define BIGBOSS_HPP

#include "GameObject.hpp"

class BigBoss : public GameObject
{
private:
	std::string _string;

public:
	int on;
	BigBoss(int max);
	BigBoss();
	~BigBoss();
	BigBoss(const BigBoss &);
	BigBoss & operator = (const BigBoss &);
	std::string getString() const;
};

#endif