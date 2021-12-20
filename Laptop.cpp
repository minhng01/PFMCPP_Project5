#include "Laptop.h"

Laptop::Laptop() : modelName("Thinkpad"),
                screenDisplay(15.6f),
                RAMSize(32),
                storageSize(2000),
                weight(6.2f)
{
    std::cout << "----------constructing Laptop----------" << "\n";
}

Laptop::~Laptop()
{
    std::cout << "----------destructing Laptop----------" << "\n";
}

int Laptop::numberOfFileOnDisk(int eachFileSize, int availableDiskStorage, int storageForOS, int maxNumOfFile)
{
    storageSize = availableDiskStorage;
    
    std::cout << "There is " << availableDiskStorage << "GB storage in total.\n";
    std::cout << "How many " << eachFileSize << "GB files that can be stored given that " 
                << storageForOS << " GB should be left for system operation and only "
                << maxNumOfFile << " maximum files that can be stored?\n";
    
    int numberOfFile = 0;
    for (int i = 1; i <= ((availableDiskStorage - storageForOS) / eachFileSize); ++i)
    {
        if (i > maxNumOfFile)
            return numberOfFile;

        storageSize -= eachFileSize;
        numberOfFile = i;
        std::cout << "Store file no." << i << ". Available storage left: " << storageSize << std::endl;
    }

    return numberOfFile;
}

void Laptop::connectToWifi(bool connectionStatus)
{
    if (connectionStatus == false)
    {
        connectionStatus = true;
    }

    std::cout << "You are connected to the Internet" << std::endl;
}

std::string Laptop::checkAvailableOSUpdate(int currentOSId)
{
    std::cout << "Storage size: " << storageSize << "GB\n";
    if (currentOSId < 10) // assume 10 is the latest OS id
    {
        return "Available update: Update OS version 10 \n";
    }

    return "OS up to date! \n";
}

void Laptop::playAudio(int audioFileId, int volume, std::string playMode)
{
    if (audioFileId < 0 || audioFileId > 99) // assume there is 100 audio files 
    {
        return;
    }

    if (volume > 70)
    {
        std::cout << "Warning: audio too loud!" << std::endl;
    }

    std::cout << "Playing audio file number " + std::to_string(audioFileId) 
                + " in mode: " + playMode 
                << std::endl; 
}
