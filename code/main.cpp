#include "shop.h"
#include "inventory.h"
#include "dialogue.h"
#include "simulator.h"

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
	inventory.addGold(100);

    simulator.generateFishToday();
    simulator.generateFishForecast(1, 100);

	Dialogue::print("Good morning Player! Rent your fishing pole!");
	Dialogue::print("Money : ", inventory.getGold());
	Dialogue::print("Answer with number : ");
	shop.showPoleOption();

    int option = -1;
    while (true) {
        std::cin >> answer;
        try {
            option = std::stoi(answer) - 1; 
            if (option >= 0 && option <= 2) 
            {
                break;
            }
            else {
                Dialogue::print("The answer is not in the option...");
            }
        }
        catch (const std::invalid_argument& e) 
        {
            Dialogue::print("Please enter a valid number.");
        }
        catch (const std::out_of_range& e) 
        {
            Dialogue::print("The number entered is too large.");
        }
    }	

	Pole& pole = shop.getPole(std::stoi(answer) - 1);
	shop.rentPole(pole);

	Dialogue::print("Money : ", inventory.getGold());
	Dialogue::print("Now it's time to put all your money into bait!");
    while (inventory.getGold() > 0)
    {
        shop.showBaitOption();
        std::cin >> answer;
        size_t index = std::stoi(answer) - 1;
        Dialogue::print("How many?");
        std::cin >> answer;
        size_t amount = std::stoi(answer);
        shop.buyBait(index, amount);
        Dialogue::print("Money : ", inventory.getGold());
    }
    simulator.generateResult();
}