/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 */

#include <iostream>

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

        void storeInFridge(int dayRemain, int expirationDuration);
        void clean(std::string cleaningType = "Salted water");
        void season(std::string mainCondiment = "Pepper");
        void cut(int numberOfPortion = 3, std::string tool = "Long knife");
    };

    OvenStove();
    ~OvenStove();

    void cookFoodOnBurner(int threshold, int numberOfAvailableBurner);
    void broilFood(FoodItem food, int temperature, int durationInMinute);
    void bakeFood(FoodItem food, int temperature, int durationInMinute, int rackId, bool preHeat);
    void lightUp(bool lightStatus);

    FoodItem mainIngredient;
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

void OvenStove::FoodItem::storeInFridge(int threshold, int expirationDuration){
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

void OvenStove::FoodItem::clean(std::string cleaningType)
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

void OvenStove::broilFood(OvenStove::FoodItem food, int temperature, int durationInMinute)
{
    std::cout << "Broiling " + food.name 
                    + " at " + std::to_string(temperature) + "F"
                    + " in " + std::to_string(durationInMinute) + " minutes" + "\n";
}

void OvenStove::bakeFood(OvenStove::FoodItem food, int temperature, int durationInMinute, int rackId, bool preHeat)
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
        
        void adjustFocalLength(int target);
        void cover();
        void zoom(float zoomMode = 1.0f);
        void getFocus(double distanceToObject);
    };

    Camera();
    ~Camera();

    void adjustWhiteBalanceMode(int target);
    void shootPhoto(Lens currentLens, char shootingMode = 'A', bool lowLight = false);
    void recordVideo(Lens currentLens, int durationInSecond);
    void playFlash(bool lowLightIntensity = true);

    Lens includedLens;
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

void Camera::Lens::getFocus(double distanceToObject)
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

void Camera::shootPhoto(Camera::Lens currentLens, char shootingMode, bool lowLight)
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

void Camera::recordVideo(Camera::Lens currentLens, int durationInSecond)
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

    void turnOnSystem(Laptop computer);
    void recordVideo(Camera camera, Camera::Lens defaultLens);
};

System::System()
{
    std::cout << "----------constructing System----------" << "\n";
}

System::~System()
{
    std::cout << "----------destructing System----------" << "\n";
}

void System::turnOnSystem(Laptop computer)
{
    std::cout << "Turning on system...\n";
    std::cout << "System info: \n";
    std::cout << "Screen display: " << computer.screenDisplay << "\n";
    std::cout << "RAM: " << computer.RAMSize << "\n";
}

void System::recordVideo(Camera camera, Camera::Lens defaultLens)
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

    void makeDinner(OvenStove stove, OvenStove::FoodItem ingredient);
    void clean(OvenStove stove, OvenStove::FoodItem food);
};

Kitchen::Kitchen()
{
    std::cout << "----------constructing Kitchen----------" << "\n";
}

Kitchen::~Kitchen()
{
    std::cout << "----------destructing Laptop----------" << "\n";
}

void Kitchen::makeDinner(OvenStove stove, OvenStove::FoodItem ingredient)
{
    std::cout << "Cooking dinner with " << ingredient.name << "...\n";
    stove.bakeFood(ingredient, 300, 60, 1, true);
}

void Kitchen::clean(OvenStove stove, OvenStove::FoodItem food)
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
    chicken.storeInFridge(1, 5);
    std::cout << "Expiration day remain: " << chicken.expirationDayRemain << std::endl;
    chicken.clean("Water");
    chicken.season("Salt");
    chicken.cut(4, "knife");
    std::cout << "\n";

    OvenStove oldOvenStove;
    std::cout << "Oven stove brand name: " << oldOvenStove.brandName << "\n";
    oldOvenStove.cookFoodOnBurner(0, 4);
    std::cout << "Number of burner available to use: " << oldOvenStove.numberOfBurner << std::endl;
    oldOvenStove.broilFood(chicken, 375, 5);
    oldOvenStove.bakeFood(chicken, 275, 60, 0, true);
    oldOvenStove.lightUp(false);
    std::cout << "\n";

    Camera::Lens myLens;
    std::cout << "Lens model: " << myLens.model << "\n";
    myLens.adjustFocalLength(180);
    myLens.cover();
    myLens.zoom(0.5f);
    myLens.getFocus(50);
    std::cout << "\n";

    Camera camera;
    std::cout << "Camera brand name: " << camera.brandName << "\n";
    camera.adjustWhiteBalanceMode(3);
    camera.shootPhoto(myLens, 'A', false);
    camera.recordVideo(myLens, 40);
    camera.playFlash(true);
    std::cout << "\n";

    Laptop laptop;
    std::cout << "Brand model name: " << laptop.modelName << "\n";
    std::cout << laptop.numberOfFileOnDisk(10, 200, 11, 15) << " files stored\n";
    std::cout << "Available storage left: " << laptop.storageSize << std::endl;
    laptop.connectToWifi(false);
    std::cout << laptop.checkAvailableOSUpdate(3);
    laptop.playAudio(2, 30, "Stereo speaker");
    std::cout << "\n";

    System system;
    system.turnOnSystem(laptop);
    system.recordVideo(camera, myLens);
    std::cout << "\n";

    Kitchen kitchen;
    kitchen.makeDinner(oldOvenStove, chicken);
    kitchen.clean(oldOvenStove, chicken);
    std::cout << "\n";

    std::cout << "good to go!" << std::endl;
}
