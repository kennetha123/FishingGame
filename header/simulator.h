#pragma once
#include <vector>
#include "item.h"
#include "inventory.h"

class Simulator
{
public:
	Simulator(Inventory& invent) : inventory(invent) {}
	void generateFishToday();
	void generateFishForecast(int fish_min, int fish_max);
	void generateResult();
private:
	std::vector<Fish> fishes_prize;
	Inventory& inventory;
	int small_fish = 0;
	int medium_fish = 0;
	int big_fish = 0;
	int red_fish = 0;
	int blue_fish = 0;
	int green_fish = 0;
	float red_percent = 0.0f;
	float blue_percent = 0.0f;
	float green_percent = 0.0f;
};