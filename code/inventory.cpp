#include "inventory.h"

Inventory::Inventory() : baits
{
	Bait(Color::red, "Red", 1),
	Bait(Color::blue, "Blue", 2),
	Bait(Color::green, "Green", 3)
}
{}

void Inventory::addBait(size_t index, size_t amount)
{
	if (index < baits.size()) 
	{
		baits[index].addAmount(amount);
	}
}

void Inventory::setActivePole(std::shared_ptr<Pole> pole)
{
	activePole = pole;
}
