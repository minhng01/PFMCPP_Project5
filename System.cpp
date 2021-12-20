#include "System.h"

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
