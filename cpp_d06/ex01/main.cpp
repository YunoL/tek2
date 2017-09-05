//
// main.cpp for main in /home/guillaume2.roux/rendu/cpp_d06/ex01
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Mon Jan  9 10:40:35 2017 Guillaume Roux
// Last update Mon Jan  9 10:40:36 2017 Guillaume Roux
//

#include <iostream>
#include <cstdlib>
#include <iomanip>

void 	calcul(float value, int temp)
{
	float result;

	if (temp == 1)
	{
		result = value * 9.0 / 5.0 + 32;
		std::cout << std::setw(16) << std::fixed << std::setprecision(3) << result << std::setw(16) << "Fahrenheit" << std::endl;
	}
	else
	{
		result = 5.0 / 9.0 * (value - 32);
		std::cout << std::setw(16) << std::fixed << std::setprecision(3) << result << std::setw(16) << "Celsius" << std::endl;
	}
}

int	check_type(std::string type)
{
	if (type == "Celsius")
		return 1;
	else if (type == "Fahrenheit")
		return 2;
	else
		return 0;
}

int	main(int argc, char **av)
{
	float	temp_value;
	std::string	temp_type;

	std::cin >> temp_value >> temp_type;
	if (std::cin.fail() || check_type(temp_type) == 0)
	{
		std::cerr << "Bad input !" << std::endl;
		return 1;
	}
	calcul(temp_value, check_type(temp_type));
	return 0;
}