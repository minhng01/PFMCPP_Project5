#include "Camera.h"

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
