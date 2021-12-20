#include "Kitchen.h"

Kitchen::Kitchen()
{
    std::cout << "----------constructing Kitchen----------" << "\n";
}

Kitchen::~Kitchen()
{
    std::cout << "----------destructing Laptop----------" << "\n";
}

void Kitchen::getIngredientWeight()
{
    std::cout << "Main ingredient weight (Part 2): " << this->mainIngredient.weight << "\n";
}

void Kitchen::makeDinner(const OvenStove& stove, const OvenStove::FoodItem& ingredient)
{
    std::cout << "Cooking dinner with " << ingredient.name << "...\n";
    stove.bakeFood(ingredient, 300, 60, 1, true);
}

void Kitchen::clean(const OvenStove& stove, const OvenStove::FoodItem& food)
{
    std::cout << "Cleaning kitchen...\n";
    std::cout << "Cleaning " << stove.brandName << " stove...\n";
    std::cout << "Cleaning " << stove.numberOfBurner << " stove burners...\n";
    std::cout << "Cleaning " << stove.numberOfRack << " oven racks...\n";
    std::cout << "Prep food...\n"; 
    food.clean("water");
}
