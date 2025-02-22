#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
private :
	std::string _name;

public :
	void announce(void);
	void makeName(std::string name);
	Zombie(std::string name);
	Zombie();
	~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif