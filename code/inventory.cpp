#include "inventory.h"
#include "game_config.h"

Inventory::Inventory() : baits
{
	Bait(Color::red, "Red", Config::getInstance().RED_BAIT),
	Bait(Color::blue, "Blue", Config::getInstance().BLUE_BAIT),
	Bait(Color::green, "Green", Config::getInstance().GREEN_BAIT)
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
