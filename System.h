#pragma once
#include "Laptop.h"
#include "Camera.h"

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
