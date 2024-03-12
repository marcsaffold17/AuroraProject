//
// Created by zebra on 3/12/2024.
//
#include <iostream>
#include <vector>

class Plasma_data {
private:
    std::string time_tag;
    std::string density;
    std::string speed;
    std::string temperature;
public:
    std::string getTime_Tag();
    std::string getDensity();
    std::string getSpeed();
    std::string getTemperature();
};

std::string Plasma_data::getTime_Tag() {
    return time_tag;
}
std::string Plasma_data::getDensity() {
    return density;
}
std::string Plasma_data::getSpeed() {
    return speed;
}
std::string Plasma_data::getTemperature() {
    return temperature;
}