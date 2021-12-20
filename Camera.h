#pragma once
#include "LeakedObjectDetector.h"

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
