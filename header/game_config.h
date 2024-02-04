#pragma once
#include "json.hpp"

struct Data
{
	
};

class Config {
public:
    // economy
    int STARTING_GOLD;
    int GOLD_GOAL;

    // fishing
    int MIN_FISH_TODAY;
    int MAX_FISH_TODAY;

    // price
    std::vector<int> RED_SMALL_PRICE;
    std::vector<int> RED_MED_PRICE;
    std::vector<int> RED_BIG_PRICE;
    std::vector<int> BLUE_SMALL_PRICE;
    std::vector<int> BLUE_MED_PRICE;
    std::vector<int> BLUE_BIG_PRICE;
    std::vector<int> GREEN_SMALL_PRICE;
    std::vector<int> GREEN_MED_PRICE;
    std::vector<int> GREEN_BIG_PRICE;

    // pole
    int SMALL_POLE;
    int MEDIUM_POLE;
    int BIG_POLE;

    // bait
    int RED_BAIT;
    int BLUE_BAIT;
    int GREEN_BAIT;

    static Config& getInstance() 
    {
        static Config instance("../config/game_config.json");
        return instance;
    }

    Config(Config const&) = delete;
    void operator=(Config const&) = delete;

private:
    Config(const std::string& configFile) 
    {
        loadConfig(configFile);
    }

private:
    void loadConfig(const std::string& configFile);
};