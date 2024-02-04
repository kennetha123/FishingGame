#include "simulator.h"
#include "dialogue.h"
#include "utils.h"
#include "game_config.h"
#include <cmath>
#include <algorithm>

void Simulator::generateFishToday()
{
	fishes_prize.emplace_back(Fish(Color::red, Size::small, Config::getInstance().RED_SMALL_PRICE[0], Config::getInstance().RED_SMALL_PRICE[1]));
	fishes_prize.emplace_back(Fish(Color::blue, Size::small, Config::getInstance().BLUE_SMALL_PRICE[0], Config::getInstance().BLUE_SMALL_PRICE[1]));
	fishes_prize.emplace_back(Fish(Color::green, Size::small, Config::getInstance().GREEN_SMALL_PRICE[0]));

	fishes_prize.emplace_back(Fish(Color::red, Size::medium, Config::getInstance().RED_MED_PRICE[0], Config::getInstance().RED_MED_PRICE[1]));
	fishes_prize.emplace_back(Fish(Color::blue, Size::medium, Config::getInstance().BLUE_MED_PRICE[0], Config::getInstance().BLUE_MED_PRICE[1]));
	fishes_prize.emplace_back(Fish(Color::green, Size::medium, Config::getInstance().GREEN_MED_PRICE[0]));

	fishes_prize.emplace_back(Fish(Color::red, Size::big, Config::getInstance().RED_BIG_PRICE[0], Config::getInstance().RED_BIG_PRICE[1]));
	fishes_prize.emplace_back(Fish(Color::blue, Size::big, Config::getInstance().BLUE_BIG_PRICE[0], Config::getInstance().BLUE_BIG_PRICE[1]));
	fishes_prize.emplace_back(Fish(Color::green, Size::big, Config::getInstance().GREEN_BIG_PRICE[0]));
}

void Simulator::generateFishForecast(int fish_min, int fish_max)
{
	const int total_fish = Utils::randomize(fish_min, fish_max);

	// if size too small, assign all to small fish.
	if (total_fish <= 2) {
		small_fish = total_fish;
		medium_fish = 0;
		big_fish = 0;
	}
	else {
		// generate number of fish in size
		int temp_fish = total_fish;
		small_fish = Utils::randomize(fish_min, std::max(fish_min, temp_fish - 2));
		temp_fish -= small_fish;
		medium_fish = Utils::randomize(fish_min, std::max(fish_min, temp_fish - 1));
		temp_fish -= medium_fish;
		big_fish = temp_fish;
	}

	// generate number of fish in color
	float temp_color = total_fish;
	if (total_fish <= 2) {
		red_fish = Utils::randomize(fish_min, std::max(fish_min, (int)temp_color - 1));
		temp_color -= red_fish;
		blue_fish = 0;
		green_fish = temp_color;
	}
	else {
		red_fish = Utils::randomize(fish_min, std::max(fish_min, (int)temp_color - 2));
		temp_color -= red_fish;
		blue_fish = Utils::randomize(fish_min, std::max(fish_min, (int)temp_color - 1));
		temp_color -= blue_fish;
		green_fish = temp_color;
	}

	float red_percent = Utils::percentage(red_fish, total_fish);
	float blue_percent = Utils::percentage(blue_fish, total_fish);
	float green_percent = Utils::percentage(green_fish, total_fish);

	Dialogue::print("Today, we're seeing ", small_fish, " small fish, ", medium_fish, " medium fish, ", big_fish, " big fish.");
	Dialogue::print(red_percent, "% are red, ", blue_percent, "% are blue, ", green_percent, "% are green.");

	percentages = { red_percent, blue_percent, green_percent };
}

void Simulator::generateResult()
{
	Dialogue::print("Generating the day...");

	int starting_index = 0;
	int fish_size_in_pool = 0;
	switch (inventory.getActivePole()->getPoleSize())
	{
	case Size::small:
		starting_index = 0;
		fish_size_in_pool = small_fish;
		break;
	case Size::medium:
		starting_index = 3;
		fish_size_in_pool = medium_fish;
		break;
	case Size::big:
		starting_index = 6;
		fish_size_in_pool = big_fish;
		break;
	}

#ifdef GAME_DEBUG
	Dialogue::print("red : ", percentages[0], "% | blue : ", percentages[1], "% | green : ", percentages[2], "%");
	Dialogue::print("Fish in the pool : ", fish_size_in_pool);
#endif

	for (size_t i = 0; i < inventory.getBaitSize(); i++)
	{
		int gold_prize = 0;
		int fish_caught = 0;
		float percent = percentages[i];

		Dialogue::print(inventory.getBaitName(i), " amount : ", inventory.getBaitAmount(i));
		int fish_price = fishes_prize[starting_index + i].getPrice();
		if (inventory.getBaitAmount(i) > 0)
		{
			int fish_exist = std::round(fish_size_in_pool * (percent / 100));
			fish_caught = std::min(inventory.getBaitAmount(i), fish_exist);
			gold_prize = fish_caught * fish_price;
			inventory.addGold(gold_prize);
		}

		Dialogue::print("You got ", fish_caught, " ", inventory.getBaitName(i), " fish caught with price ", fish_price, " and you got total of : ", gold_prize, " gold!");
	}

	Dialogue::print("Money : ", inventory.getGold());

	if (inventory.getGold() > 100)
	{
		Dialogue::print("Congratulation, YOU WIN!");
	}
	else if (inventory.getGold() < 100)
	{
		Dialogue::print("Unfortunately, YOU LOSE...");
	}
	else
	{
		Dialogue::print("You still have to work hard.");
	}
}

