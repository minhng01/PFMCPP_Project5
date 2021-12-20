#pragma once
#include "LeakedObjectDetector.h"

struct Laptop
{
    std::string modelName;
    float screenDisplay;
    int RAMSize;
    int storageSize;
    float weight;

    Laptop();
    ~Laptop();

    int numberOfFileOnDisk(int eachFileSize, int storageSizeLeft, int storageForOS, int maxNumOfFile);
    void connectToWifi(bool connectionStatus = false);
    std::string checkAvailableOSUpdate(int currentOSId);
    void playAudio(int audioFileId = 0, int volume = 50, std::string playMode = "Headphones");

    JUCE_LEAK_DETECTOR(Laptop)
};
