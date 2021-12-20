#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct OvenStove
{
    std::string brandName;
    int numberOfBurner;
    int numberOfRack;
    float ovenCapacity;
    int warrantyDuration;

    struct FoodItem
    {
        std::string type;
        std::string name;
        float weight;
        bool isSeasoned;
        int expirationDayRemain;

        FoodItem();
        ~FoodItem();

        void getFoodName();
        void storeInFridge(int dayRemain, int expirationDuration);
        void clean(std::string cleaningType = "Salted water") const;
        void season(std::string mainCondiment = "Pepper");
        void cut(int numberOfPortion = 3, std::string tool = "Long knife");

        JUCE_LEAK_DETECTOR(FoodItem)
    };

    OvenStove();
    ~OvenStove();

    void getOvenBrand();
    void cookFoodOnBurner(int threshold, int numberOfAvailableBurner);
    void broilFood(const FoodItem& food, int temperature, int durationInMinute);
    void bakeFood(const FoodItem& food, int temperature, int durationInMinute, int rackId, bool preHeat) const;
    void lightUp(bool lightStatus);

    FoodItem mainIngredient;

    JUCE_LEAK_DETECTOR(OvenStove)
};
