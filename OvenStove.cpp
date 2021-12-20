#include "OvenStove.h"

OvenStove::OvenStove() : brandName("GE"),
                        numberOfBurner(4),
                        numberOfRack(2),
                        ovenCapacity(5.0f),
                        warrantyDuration(12)
{
    std::cout << "----------constructing OvenStove----------" << "\n";
}

OvenStove::~OvenStove()
{
    std::cout << "----------destructing OvenStove----------" << "\n";
}

OvenStove::FoodItem::FoodItem() : type("Poultry"),
                                name("Chicken breast"),
                                weight(1.0f),
                                isSeasoned(false),
                                expirationDayRemain(7)
{
    std::cout << "----------constructing FoodItem----------" << "\n";
}

OvenStove::FoodItem::~FoodItem()
{
    std::cout << "----------destructing FoodItem----------" << "\n";
}

void OvenStove::FoodItem::getFoodName()
{
    std::cout << "Food item name (Part 2): " << this->name << "\n";
}

void OvenStove::FoodItem::storeInFridge(int threshold, int expirationDuration)
{
    expirationDayRemain = expirationDuration;
    
    while (expirationDayRemain > threshold)
    {
        std::cout << "There are " << expirationDayRemain << " days till expired. Keep in fridge.\n";
        --expirationDayRemain;
        
        if (expirationDayRemain <= threshold)
        {
            std::cout << "WARNING: Food is expired soon.\n";
            return;
        }
    }
}

void OvenStove::FoodItem::clean(std::string cleaningType) const
{
    if (expirationDayRemain <= 0)
    {
        std::cout << "Expired food!" << std::endl;
        return;
    }

    std::cout << "Days till expiration date: " << expirationDayRemain << "\n";

    std::cout << "Cleaning with " + cleaningType << std::endl;
}

void OvenStove::FoodItem::season(std::string mainCondiment)
{
    if (expirationDayRemain <= 0)
    {
        std::cout << "Expired food!" << std::endl;
        return;
    }

    std::cout << "Days till expiration date: " << expirationDayRemain << "\n"; 

    if (isSeasoned == false)
    {
        std::cout << "Season with " + mainCondiment << std::endl;
        isSeasoned = true;
    }

}

void OvenStove::FoodItem::cut(int numberOfPortion, std::string tool)
{
    if (expirationDayRemain <= 0)
    {
        std::cout << "Expired food!" << std::endl;
        return;
    }

    std::cout << "Days till expiration date: " << expirationDayRemain << "\n";

    if (numberOfPortion > 1)
    {
        std::cout << "Cut the food into " 
                + std::to_string(numberOfPortion) 
                + " with " 
                + tool 
                << std::endl;
    }
    else
    {
        std::cout << "Do nothing" << std::endl;
    }
}

void OvenStove::getOvenBrand()
{
    std::cout << "Oven stove brand name (Part 2): " << this->brandName << "\n";
}

void OvenStove::cookFoodOnBurner(int threshold, int totalBurner)
{
    numberOfBurner = totalBurner;
    
    while (numberOfBurner > threshold)
    {
        std::cout << "Cook food on burner no." << numberOfBurner << std::endl;
        --numberOfBurner;
        if (numberOfBurner <= threshold)
        {
            std::cout << "No burner left to cook food.\n";
            return;
        }
    }
}

void OvenStove::broilFood(const OvenStove::FoodItem& food, int temperature, int durationInMinute)
{
    std::cout << "Broiling " + food.name 
                    + " at " + std::to_string(temperature) + "F"
                    + " in " + std::to_string(durationInMinute) + " minutes" + "\n";
}

void OvenStove::bakeFood(const OvenStove::FoodItem& food, int temperature, int durationInMinute, int rackId, bool preHeat) const
{
    if (rackId < 0)
    {
        std::cout << "ERROR!" << std::endl;
        return;
    }

    if (preHeat == false)
    {
        std::cout << "Please pre heat oven before start!" << std::endl;
        return;
    }

    std::cout << "Baking " + food.name 
                    + " at " + std::to_string(temperature) + "F"
                    + " in " + std::to_string(durationInMinute) + " minutes" + "\n";
}

void OvenStove::lightUp(bool lightStatus)
{
    if (lightStatus == false)
    {
        std::cout << "Light ON" << std::endl;
        lightStatus = true;
    }
    else
    {
        std::cout << "Do NOTHING" << std::endl;
    }
}
