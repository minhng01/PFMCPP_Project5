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




#include "iostream"
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */
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

struct OvenStoveWrapper
{
    OvenStoveWrapper(OvenStove* ptr) : pointerToOvenStove(ptr) {}
    ~OvenStoveWrapper()
    {
        delete pointerToOvenStove;
    }
    OvenStove* pointerToOvenStove = nullptr;
};

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

/*
 copied UDT 2:
 */
struct Camera
{
    std::string brandName = "Canon";
    float resolution = 26.7f;
    int numberOfShootingMode = 5;
    int numberOfWhiteBalanceMode = 5;
    int currentWhiteBalanceMode = 1;
    float weight = 2.2f;

    struct Lens
    {
        std::string model = "Canon EF-S";
        int maxFocalLengthInMM = 300;
        int minFocalLengthInMM = 55;
        int currentFocalLengthInMM = 150;
        int filterDiameterInMM = 58;
        float weightInOz = 13.2f;
        
        Lens();
        ~Lens();
        
        void getLensModel();
        void adjustFocalLength(int target);
        void cover();
        void zoom(float zoomMode = 1.0f);
        void getFocus(double distanceToObject) const;

        JUCE_LEAK_DETECTOR(Lens)
    };

    Camera();
    ~Camera();

    void getCameraBrand();
    void adjustWhiteBalanceMode(int target);
    void shootPhoto(const Lens& currentLens, char shootingMode = 'A', bool lowLight = false);
    void recordVideo(const Lens& currentLens, int durationInSecond) const;
    void playFlash(bool lowLightIntensity = true);

    Lens includedLens;

    JUCE_LEAK_DETECTOR(Camera)
};

struct CameraWrapper
{
    CameraWrapper(Camera* ptr) : pointerToCamera(ptr) {}
    ~CameraWrapper()
    {
        delete pointerToCamera;
    }
    Camera* pointerToCamera = nullptr;
};

Camera::Lens::Lens()
{
    std::cout << "----------constructing Lens----------" << "\n";
}

Camera::Lens::~Lens()
{
    std::cout << "----------destructing Lens----------" << "\n";
}

Camera::Camera()
{
    std::cout << "----------constructing Camera----------" << "\n";
}

Camera::~Camera()
{
    std::cout << "----------destructing Camera----------" << "\n";
}

void Camera::Lens::getLensModel()
{
    std::cout << "Lens model (Part 2): " << this->model << "\n";
}

void Camera::Lens::adjustFocalLength(int target)
{
    while (currentFocalLengthInMM != target) //adjust in step of 5 unit. Assuming the focal length is product of 5
    {
        if (currentFocalLengthInMM >= maxFocalLengthInMM)
        {
            currentFocalLengthInMM =  maxFocalLengthInMM;
            return;
        }
        
        if (currentFocalLengthInMM <= minFocalLengthInMM)
        {
            currentFocalLengthInMM =  minFocalLengthInMM;
            return;
        }

        if (currentFocalLengthInMM < target)
        {   
            std::cout << "Increased current focal length: " << currentFocalLengthInMM << std::endl;
            currentFocalLengthInMM += 5;
        }
        else if (currentFocalLengthInMM > target)
        {
            std::cout << "Increased current focal length: " << currentFocalLengthInMM << std::endl;
            currentFocalLengthInMM -= 5;
        }
    }

    std::cout << "Current focal length: " << currentFocalLengthInMM << "\n";
}

void Camera::Lens::cover()
{
    std::cout << model << ": covering lens..." << "\n";
}

void Camera::Lens::zoom(float zoomMode)
{
    std::cout << "Focal length: " << minFocalLengthInMM << "mm-" << maxFocalLengthInMM << "mm\n";

    if (zoomMode < 1.0f)
    {
        std::cout << "Zoom OUT" << std::endl;
    }
    else if (zoomMode > 1.0f)
    {
        std::cout << "Zoom IN" << std::endl;
    }
    else
    {
        std::cout << "Original" << std::endl;
    }
}

void Camera::Lens::getFocus(double distanceToObject) const
{
    if (distanceToObject < 1)
    {
        std::cout << "Too close. Please move further." << std:: endl;
    }
    else if (distanceToObject > 100)
    {
        std::cout << "Too far. Please move closer." << std:: endl;
    }
    else
    {
        // get focus on object
        std::cout << "Focus ready..." << std::endl;
    }
}

void Camera::getCameraBrand()
{
    std::cout << "Camera brand name (Part 2): " << this->brandName << "\n";
}

void Camera::adjustWhiteBalanceMode(int target)
{
    while (currentWhiteBalanceMode != target) //adjust in step of 5 unit. Assuming the focal length is product of 5
    {
        if (currentWhiteBalanceMode >= numberOfWhiteBalanceMode)
        {
            currentWhiteBalanceMode = numberOfWhiteBalanceMode;
            return;
        }
        
        if (currentWhiteBalanceMode < 1)
        {
            currentWhiteBalanceMode = 1;
            return;
        }

        if (currentWhiteBalanceMode < target)
        {   
            std::cout << "Current white balance mode: " << currentWhiteBalanceMode << std::endl;
            ++currentWhiteBalanceMode;
        }
        else if (currentWhiteBalanceMode > target)
        {
            std::cout << "Current white balance mode: " << currentWhiteBalanceMode << std::endl;
            --currentWhiteBalanceMode;
        }
    }

    std::cout << "Current white balance mode: " << currentWhiteBalanceMode << "\n";
}

void Camera::shootPhoto(const Camera::Lens& currentLens, char shootingMode, bool lowLight)
{
    currentLens.getFocus(50); // assume default value 50 for photo
    
    std::cout << "Resolution: " << resolution << "px\n";

    if (shootingMode == 'A')
    {
        std::cout << "Taking photo in auto mode \n";
        playFlash(lowLight); // auto mode play flash if low light
    }
    else if (shootingMode == 'M')
    {
        std::cout << "Please choose shutter speed" << std::endl;
        std::cout << "Flash option";
    }
}

void Camera::recordVideo(const Camera::Lens& currentLens, int durationInSecond) const
{
    currentLens.getFocus(70); // assume default value 70 for video
    std::cout << "Recording...";
    // record video
    std::cout << " duration: " + std::to_string(durationInSecond) + " seconds \n"; 
}

void Camera::playFlash(bool lowLightIntensity)
{
    if (lowLightIntensity == true)
    {
        std::cout << "Playing flash..." << "\n";
    }
}

/*
 copied UDT 3:
 */
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

struct LaptopWrapper
{
    LaptopWrapper(Laptop* ptr) : pointerToLaptop(ptr) {}
    ~LaptopWrapper()
    {
        delete pointerToLaptop;
    }
    Laptop* pointerToLaptop = nullptr;
};

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

/*
 new UDT 4:
 with 2 member functions
 */
struct System
{
    Laptop mainControl;
    Camera webcam;
    Camera::Lens lens;

    System();
    ~System();

    void getWebcamResolution();
    void turnOnSystem(const Laptop& computer);
    void recordVideo(const Camera& camera, const Camera::Lens& defaultLens);

    JUCE_LEAK_DETECTOR(System)
};

struct SystemWrapper
{
    SystemWrapper(System* ptr) : pointerToSystem(ptr) {}
    ~SystemWrapper()
    {
        delete pointerToSystem;
    }
    System* pointerToSystem = nullptr;
};

System::System()
{
    std::cout << "----------constructing System----------" << "\n";
}

System::~System()
{
    std::cout << "----------destructing System----------" << "\n";
}

void System::getWebcamResolution()
{
    std::cout << "System camera resolution (Part 2): " << this->webcam.resolution << "\n";
}

void System::turnOnSystem(const Laptop& computer)
{
    std::cout << "Turning on system...\n";
    std::cout << "System info: \n";
    std::cout << "Screen display: " << computer.screenDisplay << "\n";
    std::cout << "RAM: " << computer.RAMSize << "\n";
}

void System::recordVideo(const Camera& camera, const Camera::Lens& defaultLens)
{
    std::cout << "Using lens " << defaultLens.model << "\n";
    camera.recordVideo(defaultLens, 60);
}

/*
 new UDT 5:
 with 2 member functions
 */
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

struct KitchenWrapper
{
    KitchenWrapper(Kitchen* ptr) : pointerToKitchen(ptr) {}
    ~KitchenWrapper()
    {
        delete pointerToKitchen;
    }
    Kitchen* pointerToKitchen = nullptr;
};

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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

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
