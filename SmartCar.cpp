#include "SmartCar.h"

// Chassis Constructor
Chassis::Chassis() :
        id("dpXXXXXX"), model("SCOUT MINI"), wheelbase(451), track(490),
        minClearance(115), minTurningRadius(0), driveType("四轮四驱"),
        maxRange(10), tireModel("公路轮"), tireSize(175) {}

// AGXKit Constructor
AGXKit::AGXKit() :
        model("AGX Xavier"), ai(32), cudaCores(512), tensorCores(64),
        memory(32), storage(32) {}

// StereoCamera Constructor
StereoCamera::StereoCamera() :
        model("RealSense D435i"), camera("D430"),
        rgbResolutionX(1920), rgbResolutionY(1080), rgbFrameRate(30),
        fovX(87), fovY(58), depthFrameRate(90) {}

// Lidar Constructor
Lidar::Lidar() : model("RS-Helios-16p"), channels(16), range(100), power(8) {}

// Gyroscope Constructor
Gyroscope::Gyroscope() : model("CH110"), manufacturer("NXP") {}

// Display Constructor
Display::Display() : size(11.6), model("super") {}

// Battery Constructor
Battery::Battery() : param("24V/15Ah"), externalPower(24), chargeTime(2) {}

// Student Constructor
Student::Student() : id(""), name("") {}

// SmartCar Constructor
SmartCar::SmartCar(std::string id) : id(id) {}

// Assign Student
void SmartCar::assignStudent(const Student& student) {
    assignedStudent = student;
}

// Display Car Information
void SmartCar::displayInfo() const {
    std::cout << "Car ID: " << id << std::endl;
    std::cout << "Chassis Model: " << chassis.model << std::endl;
    std::cout << "Student: " << assignedStudent.id << " - " << assignedStudent.name << std::endl;
    // Add other component information here
}
