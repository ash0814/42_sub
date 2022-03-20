#include "Brain.hpp"

#include <sstream>

Brain::Brain()
{
	std::cout << "I have soooo many IDEAs!!" << std::endl;
	this->setBrain("IDEA");
}

void Brain::setBrain(std::string id)
{
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << i + 1;
		ideas[i] = id + " [" + ss.str() + "]";
	}
}

std::string Brain::getBrain(int n)
{
	return ideas[n];
}

Brain::~Brain()
{
	std::cout << "I have NO IDEA" << std::endl;
}