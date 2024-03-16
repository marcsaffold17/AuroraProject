//
// Created by zebra on 3/12/2024.
//

#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <alertReaderFactory.h>
#include "IAlertReader.h"
#include "AlertReader_JSON.h"
#include <string>
#include <memory>

class Plasma_data {
private:
    std::string time_tag;
    float density;
    float speed;
    float temperature;
    std::vector<float> singleObs; //1st position is time_tag, 2nd is density, 3rd is speed, 4th is temperature
    //std::vector<std::vector<float>> vectorOfObs; //Vector holding vectors of Observations, use in Satellite storage
public:
    std::string getTime_Tag();
    float getDensity();
    float getSpeed();
    float getTemperature();
    void readObs(std::string, std::string,std::string,std::string);
    std::vector<float> getObs();
};

std::string Plasma_data::getTime_Tag() {
    return time_tag;
}
float Plasma_data::getDensity() {
    return density;
}
float Plasma_data::getSpeed() {
    return speed;
}
float Plasma_data::getTemperature() {
    return temperature;
}
std::vector<float> Plasma_data::getObs(){
    return singleObs;
}

void Plasma_data::readObs(std::string tt_in, std::string d_in, std::string s_in, std::string temp_in) {
    time_tag=tt_in;
    density=std::stof(d_in);
    speed=std::stof(s_in);
    temperature=std::stof(temp_in);
    singleObs.push_back(density);
    singleObs.push_back(speed);
    singleObs.push_back(temperature);
    //vectorOfObs.push_back(singleObs); To be used in Satellite storage
}