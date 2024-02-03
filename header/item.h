#pragma once
#include <string>
#include "utils.h"

enum class Color
{
	red,
	blue,
	green
};

enum class Size
{
	small,
	medium,
	big
};

class Bait
{
public:
	Bait(Color bait_color, const std::string& bait_name, size_t bait_price) : color(bait_color), name(bait_name), price(bait_price) {}
	inline size_t getPrice() { return price; }
	inline void addAmount(size_t value) { amount += value; }
	inline std::string getName() { return name; }
	inline size_t getAmount() { return amount; }
private:
	std::string name;
	Color color;
	size_t price = 0;
	size_t amount = 0;
};

class Pole
{
public:
	Pole(Size pole_size, const std::string& pole_name, size_t pole_price) : size(pole_size), name(pole_name), price(pole_price) {}
	inline std::string& getPoleName() { return name; }
	inline size_t getPolePrice() { return price; }
	inline Size getPoleSize() { return size; }
private:
	std::string name;
	size_t price = 0;
	Size size;
};

class Fish
{
public:
	Fish(Color fish_color, Size fish_size, int price_min, int price_max) : color(fish_color), size(fish_size) 
	{
		price = Utils::randomize(price_min, price_max);
	}

	Fish(Color fish_color, Size fish_size, int fish_price) : color(fish_color), size(fish_size), price(fish_price) {}
	inline size_t getPrice() { return price; }
private:
	Color color;
	Size size;
	size_t price = 0;
};