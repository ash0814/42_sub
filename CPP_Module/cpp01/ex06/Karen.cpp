#include "./Karen.hpp"
#include <iostream>

void Karen::debug(void)
{
	std::cout << "[DEBUG]\n" << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
	<< " I just love it!" << std::endl;
}

void Karen::info(void)
{
	std::cout << "[INFO]\n" << "I cannot believe adding extra bacon cost more money."
	<<" You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "[WARNING]\n" << "I think I deserve to have some extra bacon for free."
	<< " I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void)
{
	std::cout << "[ERROR]\n" << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
	void (Karen::*ptr[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	std::string lv[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int cmd;
	for (int i = 0; i < 4; i++){
		if (level == lv[i]) {
			cmd = i;
		}
	}
	switch (cmd)
	{
	case 0:
		(this->*ptr[0])();
	case 1:
		(this->*ptr[1])();
		cmd--;
	case 2:
		(this->*ptr[2])();
		cmd--;
	case 3:
		(this->*ptr[3])();
		cmd--;
	default:
		break;
	}
	std::cout << std::endl;
}

Karen::Karen()
{
}

Karen::~Karen()
{
}