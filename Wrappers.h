#pragma once

struct OvenStove;
struct Camera;
struct Laptop;
struct System;
struct Kitchen;

struct OvenStoveWrapper
{
    OvenStoveWrapper(OvenStove* ptr);
    ~OvenStoveWrapper();
    OvenStove* pointerToOvenStove = nullptr;
};

struct CameraWrapper
{
    CameraWrapper(Camera* ptr);
    ~CameraWrapper();
    Camera* pointerToCamera = nullptr;
};

struct LaptopWrapper
{
    LaptopWrapper(Laptop* ptr);
    ~LaptopWrapper();
    Laptop* pointerToLaptop = nullptr;
};

struct SystemWrapper
{
    SystemWrapper(System* ptr);
    ~SystemWrapper();
    System* pointerToSystem = nullptr;
};

struct KitchenWrapper
{
    KitchenWrapper(Kitchen* ptr);
    ~KitchenWrapper();
    Kitchen* pointerToKitchen = nullptr;
};
