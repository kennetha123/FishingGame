#include "shop.h"
#include "inventory.h"
#include "dialogue.h"
#include "simulator.h"
#include "game_config.h"

void clearConsole()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

int main()
{
    std::string answer;

    Inventory inventory;
    Shop shop(inventory);
    Simulator simulator(inventory);

    inventory.addGold(Config::getInstance().STARTING_GOLD);
    int day = 1;

    while (inventory.getGold() >= Config::getInstance().GOLD_GOAL)
    {
        Dialogue::print(" ");
        Dialogue::print("DAY ", day);
        Dialogue::print(" ");
        simulator.generateFishToday();
        simulator.generateFishForecast(Config::getInstance().MIN_FISH_TODAY, Config::getInstance().MAX_FISH_TODAY);
        Dialogue::print("Good morning Player! Rent your fishing pole!");
        Dialogue::print("Money : ", inventory.getGold());
        Dialogue::print("Answer with number : ");
        shop.showPoleOption();

        Dialogue::answer(answer);
        Pole& pole = shop.getPole(std::stoi(answer) - 1);
        shop.rentPole(pole);

        Dialogue::print("Money : ", inventory.getGold());
        Dialogue::print("Now it's time to put all your money into bait!");
        while (inventory.getGold() > 0)
        {
            shop.showBaitOption();
            Dialogue::answer(answer);
            size_t index = std::stoi(answer) - 1;
            Dialogue::print("How many?");
            Dialogue::answer(answer, true);
            size_t amount = std::stoi(answer);
            shop.buyBait(index, amount);
            Dialogue::print("Money : ", inventory.getGold());
        }
        simulator.generateResult();
        day++;
    }
}