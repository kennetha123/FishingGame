#include "utils.h"
#include <random>
#include <iostream>

size_t Utils::randomize(int min, int max)
{
	if (min >= max)
	{
		return min;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribution(min, max);

	return distribution(gen);
}

float Utils::percentage(float a, float b)
{
	if (b == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return 0;
	}

	return (a / b) * 100.0f;
}
