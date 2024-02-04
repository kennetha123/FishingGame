#pragma once
#include <array>
#include <memory>
#include "inventory.h"
#include "item.h"

class Shop
{
public:
	Shop(Inventory& inventory);
	void rentPole(Pole& pole);
	void buyBait(size_t index, size_t amount);
	void showPoleOption();
	void showBaitOption();
	Pole& getPole(unsigned int index);
private:
	Inventory& inventory;
	std::array<Pole, 3> poles;
};

