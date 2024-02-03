#pragma once
#include <array>
#include <memory>
#include "inventory.h"
#include "item.h"

class Shop
{
public:
	Shop(Inventory& inventory) : inventory(inventory), poles
	{
		Pole(Size::small, "Small Fishing Pole", 5),
		Pole(Size::medium, "Medium Fishing Pole", 10),
		Pole(Size::big, "Big Fishing Pole", 15)
	} {}
	void rentPole(Pole& pole);
	void buyBait(size_t index, size_t amount);
	void showPoleOption();
	void showBaitOption();
	Pole& getPole(unsigned int index);
private:
	Inventory& inventory;
	std::array<Pole, 3> poles;
};

