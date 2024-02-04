#include "game_config.h"
#include <fstream>
#include <iostream>
#include <string>

void Config::loadConfig(const std::string& configFile)
{
    std::ifstream file(configFile);
    nlohmann::json jsonConfig;
    if (file.is_open()) 
    {
        file >> jsonConfig;

        STARTING_GOLD = jsonConfig["Economy"]["STARTING_GOLD"];
        GOLD_GOAL = jsonConfig["Economy"]["GOLD_GOAL"];
        MIN_FISH_TODAY = jsonConfig["Fishing"]["MIN_FISH_TODAY"];
        MAX_FISH_TODAY = jsonConfig["Fishing"]["MAX_FISH_TODAY"];
        RED_SMALL_PRICE = jsonConfig["Price"]["RED_SMALL_PRICE"].get<std::vector<int>>();
        RED_MED_PRICE = jsonConfig["Price"]["RED_MED_PRICE"].get<std::vector<int>>();
        RED_BIG_PRICE = jsonConfig["Price"]["RED_BIG_PRICE"].get<std::vector<int>>();
        BLUE_SMALL_PRICE = jsonConfig["Price"]["BLUE_SMALL_PRICE"].get<std::vector<int>>();
        BLUE_MED_PRICE = jsonConfig["Price"]["BLUE_MED_PRICE"].get<std::vector<int>>();
        BLUE_BIG_PRICE = jsonConfig["Price"]["BLUE_BIG_PRICE"].get<std::vector<int>>();
        GREEN_SMALL_PRICE = jsonConfig["Price"]["GREEN_SMALL_PRICE"].get<std::vector<int>>();
        GREEN_MED_PRICE = jsonConfig["Price"]["GREEN_MED_PRICE"].get<std::vector<int>>();
        GREEN_BIG_PRICE = jsonConfig["Price"]["GREEN_BIG_PRICE"].get<std::vector<int>>();
        SMALL_POLE = jsonConfig["Pole"]["SMALL_POLE"];
        MEDIUM_POLE = jsonConfig["Pole"]["MEDIUM_POLE"];
        BIG_POLE = jsonConfig["Pole"]["BIG_POLE"];
        RED_BAIT = jsonConfig["Bait"]["RED_BAIT"];
        BLUE_BAIT = jsonConfig["Bait"]["BLUE_BAIT"];
        GREEN_BAIT = jsonConfig["Bait"]["GREEN_BAIT"];

    }
    else 
    {
        std::cerr << "Could not open config file: " << configFile << std::endl;
    }
}
