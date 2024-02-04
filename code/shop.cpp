#include "shop.h"
#include "dialogue.h"
#include "game_config.h"

Shop::Shop(Inventory& inventory) : inventory(inventory), poles
{
	Pole(Size::small, "Small Fishing Pole", Config::getInstance().SMALL_POLE),
	Pole(Size::medium, "Medium Fishing Pole", Config::getInstance().MEDIUM_POLE),
	Pole(Size::big, "Big Fishing Pole", Config::getInstance().BIG_POLE)
} {}

void Shop::rentPole(Pole& pole)
{
	if (inventory.getGold() >= pole.getPolePrice())
	{
		inventory.setActivePole(std::make_shared<Pole>(pole));
		inventory.decreaseGold(pole.getPolePrice());
		Dialogue::print("Rent ", pole.getPoleName(), " !");
	}
	else
	{
		Dialogue::print("Not enough gold! Your gold : ", inventory.getGold(), " the pole price : ", pole.getPolePrice());
	}
}

void Shop::buyBait(size_t index, size_t amount)
{
	if (inventory.getGold() >= inventory.getBaitPrice(index) * amount)
	{
		inventory.addBait(index, amount);
		inventory.decreaseGold(inventory.getBaitPrice(index) * amount);
		Dialogue::print("Bought ", inventory.getBaitName(index)," ", amount, "x !");
	}
	else
	{
		Dialogue::print("Not enough gold! Your gold : ", inventory.getGold(), " the bait price : ", inventory.getBaitPrice(index) * amount);
	}

}

void Shop::showPoleOption()
{
	for (size_t i = 0; i < poles.size(); i++)
	{
		Dialogue::print(i + 1, ". ", poles[i].getPoleName(), " || Price : ", poles[i].getPolePrice());
	}
}

void Shop::showBaitOption()
{
	for (size_t i = 0; i < 3; i++)
	{
		Dialogue::print(i + 1, ". ", inventory.getBaitName(i), " || Price : ", inventory.getBaitPrice(i));
	}
}

Pole& Shop::getPole(unsigned int index)
{
	return poles[index];
}
