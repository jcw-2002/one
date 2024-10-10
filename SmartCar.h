#ifndef SMARTCAR_H
#define SMARTCAR_H

#include <iostream>
#include <string>
#include <vector>

class Chassis {
public:
    std::string id;
    std::string model;
    int wheelbase;
    int track;
    int minClearance;
    int minTurningRadius;
    std::string driveType;
    int maxRange;
    std::string tireModel;
    int tireSize;

    Chassis();
};

class AGXKit {
public:
    std::string model;
    int ai;
    int cudaCores;
    int tensorCores;
    int memory;
    int storage;

    AGXKit();
};

class StereoCamera {
public:
    std::string model;
    std::string camera;
    int rgbResolutionX;
    int rgbResolutionY;
    int rgbFrameRate;
    int fovX;
    int fovY;
    int depthFrameRate;

    StereoCamera();
};

class Lidar {
public:
    std::string model;
    int channels;
    int range;
    int power;

    Lidar();
};

class Gyroscope {
public:
    std::string model;
    std::string manufacturer;

    Gyroscope();
};

class Display {
public:
    double size;
    std::string model;

    Display();
};

class Battery {
public:
    std::string param;
    int externalPower;
    int chargeTime;

    Battery();
};

class Student {
public:
    std::string id;
    std::string name;

    Student();
};

class SmartCar {
public:
    std::string id;
    Chassis chassis;
    AGXKit agxKit;
    StereoCamera stereoCamera;
    Lidar lidar;
    Gyroscope gyroscope;
    Display display;
    Battery battery;
    Student assignedStudent;

    SmartCar(std::string id);

    void assignStudent(const Student& student);
    void displayInfo() const;
};

#endif
