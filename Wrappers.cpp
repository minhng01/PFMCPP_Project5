#include "Wrappers.h"
#include "OvenStove.h"
#include "Camera.h"
#include "Laptop.h"
#include "System.h"
#include "Kitchen.h"

OvenStoveWrapper::OvenStoveWrapper(OvenStove* ptr) : pointerToOvenStove(ptr) {}
OvenStoveWrapper::~OvenStoveWrapper()
{
    delete pointerToOvenStove;
}

CameraWrapper::CameraWrapper(Camera* ptr) : pointerToCamera(ptr) {}
CameraWrapper::~CameraWrapper()
{
    delete pointerToCamera;
}

LaptopWrapper::LaptopWrapper(Laptop* ptr) : pointerToLaptop(ptr) {}
LaptopWrapper::~LaptopWrapper()
{
    delete pointerToLaptop;
}

SystemWrapper::SystemWrapper(System* ptr) : pointerToSystem(ptr) {}
SystemWrapper::~SystemWrapper()
{
    delete pointerToSystem;
}

KitchenWrapper::KitchenWrapper(Kitchen* ptr) : pointerToKitchen(ptr) {}
KitchenWrapper::~KitchenWrapper()
{
    delete pointerToKitchen;
}
