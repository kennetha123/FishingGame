#pragma once
#include <array>
#include "item.h"
#include <memory>
class Inventory
{
public:
	Inventory();

	inline void addGold(size_t value) { gold += value; }
	inline void decreaseGold(size_t value) { gold -= value; }
	inline size_t getGold() { return gold; }
	void addBait(size_t index, size_t amount);
	inline size_t getBaitPrice(size_t index) { return baits[index].getPrice(); }
	inline size_t getBaitAmount(size_t index) { return baits[index].getAmount(); }
	inline std::string getBaitName(size_t index) { return baits[index].getName(); }
	inline size_t getBaitSize() { return baits.size(); }
	void setActivePole(std::shared_ptr<Pole> pole);
	std::shared_ptr<Pole> getActivePole() { return activePole; }
private:
	size_t gold = 0;
	std::array<Bait, 3> baits;
	std::shared_ptr<Pole> activePole;
};