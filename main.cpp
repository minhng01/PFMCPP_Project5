/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include "OvenStove.h"
#include "Camera.h"
#include "Laptop.h"
#include "System.h"
#include "Kitchen.h"
#include "Wrappers.h"

int main()
{
    OvenStove::FoodItem chicken;
    std::cout << "Food item name: " << chicken.name << "\n";
    chicken.getFoodName();
    chicken.storeInFridge(1, 5);
    std::cout << "Expiration day remain: " << chicken.expirationDayRemain << std::endl;
    chicken.clean("Water");
    chicken.season("Salt");
    chicken.cut(4, "knife");
    std::cout << "\n";

    OvenStoveWrapper oldOvenStove(new OvenStove());
    std::cout << "Oven stove brand name: " << oldOvenStove.pointerToOvenStove->brandName << "\n";
    oldOvenStove.pointerToOvenStove->getOvenBrand();
    oldOvenStove.pointerToOvenStove->cookFoodOnBurner(0, 4);
    std::cout << "Number of burner available to use: " << oldOvenStove.pointerToOvenStove->numberOfBurner << std::endl;
    oldOvenStove.pointerToOvenStove->broilFood(chicken, 375, 5);
    oldOvenStove.pointerToOvenStove->bakeFood(chicken, 275, 60, 0, true);
    oldOvenStove.pointerToOvenStove->lightUp(false);
    std::cout << "\n";

    Camera::Lens myLens;
    std::cout << "Lens model: " << myLens.model << "\n";
    myLens.getLensModel();
    myLens.adjustFocalLength(180);
    myLens.cover();
    myLens.zoom(0.5f);
    myLens.getFocus(50);
    std::cout << "\n";

    CameraWrapper camera(new Camera());
    std::cout << "Camera brand name: " << camera.pointerToCamera->brandName << "\n";
    camera.pointerToCamera->getCameraBrand();
    camera.pointerToCamera->adjustWhiteBalanceMode(3);
    camera.pointerToCamera->shootPhoto(myLens, 'A', false);
    camera.pointerToCamera->recordVideo(myLens, 40);
    camera.pointerToCamera->playFlash(true);
    std::cout << "\n";

    LaptopWrapper laptop(new Laptop());
    std::cout << "Brand model name: " << laptop.pointerToLaptop->modelName << "\n";
    std::cout << laptop.pointerToLaptop->numberOfFileOnDisk(10, 200, 11, 15) << " files stored\n";
    std::cout << "Available storage left: " << laptop.pointerToLaptop->storageSize << std::endl;
    laptop.pointerToLaptop->connectToWifi(false);
    std::cout << laptop.pointerToLaptop->checkAvailableOSUpdate(3);
    laptop.pointerToLaptop->playAudio(2, 30, "Stereo speaker");
    std::cout << "\n";

    SystemWrapper system(new System());
    std::cout << "System camera resolution: " << system.pointerToSystem->webcam.resolution << "\n";
    system.pointerToSystem->getWebcamResolution();
    system.pointerToSystem->turnOnSystem(*laptop.pointerToLaptop);
    system.pointerToSystem->recordVideo(*camera.pointerToCamera, myLens);
    std::cout << "\n";

    KitchenWrapper kitchen(new Kitchen());
    std::cout << "Main ingredient weight: " << kitchen.pointerToKitchen->mainIngredient.weight << "\n";
    kitchen.pointerToKitchen->getIngredientWeight();
    kitchen.pointerToKitchen->makeDinner(*oldOvenStove.pointerToOvenStove, chicken);
    kitchen.pointerToKitchen->clean(*oldOvenStove.pointerToOvenStove, chicken);
    std::cout << "\n";

    std::cout << "good to go!" << std::endl;
}
