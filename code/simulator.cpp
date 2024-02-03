#include "simulator.h"
#include "dialogue.h"
#include "utils.h"
#include <cmath>
void Simulator::generateFishToday()
{
	fishes_prize.emplace_back(Fish(Color::red, Size::small, 1, 5));
	fishes_prize.emplace_back(Fish(Color::blue, Size::small, 3, 5));
	fishes_prize.emplace_back(Fish(Color::green, Size::small, 5));

	fishes_prize.emplace_back(Fish(Color::red, Size::medium, 5, 10));
	fishes_prize.emplace_back(Fish(Color::blue, Size::medium, 8, 10));
	fishes_prize.emplace_back(Fish(Color::green, Size::medium, 10));

	fishes_prize.emplace_back(Fish(Color::red, Size::big, 10, 15));
	fishes_prize.emplace_back(Fish(Color::blue, Size::big, 13, 15));
	fishes_prize.emplace_back(Fish(Color::green, Size::big, 15));
}

void Simulator::generateFishForecast(int fish_min, int fish_max)
{
	// generate number of fish in size
	const int total_fish = Utils::randomize(fish_min, fish_max);
	int temp_fish = total_fish;
	small_fish = Utils::randomize(fish_min, temp_fish);
	temp_fish -= small_fish;
	medium_fish = Utils::randomize(fish_min, temp_fish);
	temp_fish -= medium_fish;
	big_fish = temp_fish;

	// generate number of fish in color
	float temp_color = total_fish;
	red_fish = Utils::randomize(fish_min, temp_color);
	red_percent = Utils::percentage(red_fish, total_fish);
	temp_color -= red_fish;
	blue_fish = Utils::randomize(fish_min, temp_color);
	blue_percent = Utils::percentage(blue_fish, total_fish);
	temp_color -= blue_fish;
	green_fish = temp_color;
	green_percent = Utils::percentage(green_fish, total_fish);

	Dialogue::print("Today, we're seeing ", small_fish, " small fish,", medium_fish, " medium fish,", big_fish, " big fish.");
	Dialogue::print(red_percent, "% are red, ", blue_percent, "% are blue, ", green_percent, "% are green.");
}

void Simulator::generateResult()
{
	Dialogue::print("Generating the day...");

	int starting_index = 0;
	int fish_used = 0;
	switch (inventory.getActivePole()->getPoleSize())
	{
	case Size::small:
		starting_index = 0;
		fish_used = small_fish;
	case Size::medium:
		starting_index = 3;
		fish_used = medium_fish;
	case Size::big:
		starting_index = 6;
		fish_used = big_fish;
	}

	for (size_t i = 0; i < inventory.getBaitSize(); i++)
	{
		int gold_prize = 0;
		int fish_caught = 0;
		float percent = 0;

		switch (i)
		{
		case 2:
			percent = green_percent;
		case 1:
			percent = blue_percent;
		case 0:
			percent = red_percent;
		}

		Dialogue::print(inventory.getBaitName(i), " amount : ", inventory.getBaitAmount(i));
		int fish_price = fishes_prize[starting_index + i].getPrice();
		if (inventory.getBaitAmount(i) > 0)
		{

			int fish_exist = std::round(fish_used * (percent / 100));
			if (inventory.getBaitAmount(i) > fish_exist)
			{
				fish_caught = fish_exist;
				gold_prize += fish_exist * fish_price;
			}
			else
			{
				fish_caught = inventory.getBaitAmount(i);
				gold_prize += inventory.getBaitAmount(i) * fish_price;
			}
		}

		inventory.addGold(gold_prize);
		Dialogue::print("You got ", fish_caught, " ", inventory.getBaitName(i), " fish caught with price ", fish_price, " and you got total of : ", gold_prize, " gold!");
	}

	Dialogue::print("Money : ", inventory.getGold());
}

