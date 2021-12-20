#pragma once
#include "OvenStove.h"

struct Kitchen
{
    OvenStove range;
    OvenStove::FoodItem mainIngredient;
    
    Kitchen();
    ~Kitchen();

    void getIngredientWeight();
    void makeDinner(const OvenStove& stove, const OvenStove::FoodItem& ingredient);
    void clean(const OvenStove& stove, const OvenStove::FoodItem& food);

    JUCE_LEAK_DETECTOR(Kitchen)
};
