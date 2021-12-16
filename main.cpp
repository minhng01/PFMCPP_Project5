/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by const reference.
*/
#if false
void someMemberFunction(const Axe& axe);
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




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
        void clean(std::string cleaningType = "Salted water");
        void season(std::string mainCondiment = "Pepper");
        void cut(int numberOfPortion = 3, std::string tool = "Long knife");
    };

    OvenStove();
    ~OvenStove();

    void getOvenBrand();
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
        
        void getLensModel();
        void adjustFocalLength(int target);
        void cover();
        void zoom(float zoomMode = 1.0f);
        void getFocus(double distanceToObject);
    };

    Camera();
    ~Camera();

    void getCameraBrand();
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

    void getWebcamResolution();
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

void System::getWebcamResolution()
{
    std::cout << "System camera resolution (Part 2): " << this->webcam.resolution << "\n";
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

    void getIngredientWeight();
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

void Kitchen::getIngredientWeight()
{
    std::cout << "Main ingredient weight (Part 2): " << this->mainIngredient.weight << "\n";
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
    chicken.getFoodName();
    chicken.storeInFridge(1, 5);
    std::cout << "Expiration day remain: " << chicken.expirationDayRemain << std::endl;
    chicken.clean("Water");
    chicken.season("Salt");
    chicken.cut(4, "knife");
    std::cout << "\n";

    OvenStove oldOvenStove;
    std::cout << "Oven stove brand name: " << oldOvenStove.brandName << "\n";
    oldOvenStove.getOvenBrand();
    oldOvenStove.cookFoodOnBurner(0, 4);
    std::cout << "Number of burner available to use: " << oldOvenStove.numberOfBurner << std::endl;
    oldOvenStove.broilFood(chicken, 375, 5);
    oldOvenStove.bakeFood(chicken, 275, 60, 0, true);
    oldOvenStove.lightUp(false);
    std::cout << "\n";

    Camera::Lens myLens;
    std::cout << "Lens model: " << myLens.model << "\n";
    myLens.getLensModel();
    myLens.adjustFocalLength(180);
    myLens.cover();
    myLens.zoom(0.5f);
    myLens.getFocus(50);
    std::cout << "\n";

    Camera camera;
    std::cout << "Camera brand name: " << camera.brandName << "\n";
    camera.getCameraBrand();
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
    std::cout << "System camera resolution: " << system.webcam.resolution << "\n";
    system.getWebcamResolution();
    system.turnOnSystem(laptop);
    system.recordVideo(camera, myLens);
    std::cout << "\n";

    Kitchen kitchen;
    std::cout << "Main ingredient weight: " << kitchen.mainIngredient.weight << "\n";
    kitchen.getIngredientWeight();
    kitchen.makeDinner(oldOvenStove, chicken);
    kitchen.clean(oldOvenStove, chicken);
    std::cout << "\n";

    std::cout << "good to go!" << std::endl;
}
