//
// Created by zebra on 3/15/2024.
//

#ifndef AURORA9_PLASMA_OBS_H
#define AURORA9_PLASMA_OBS_H

#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
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
    void readObs(std::string tt_in, std::string d_in, std::string s_in, std::string temp_in) {
        time_tag=tt_in;
        density=std::stof(d_in);
        speed=std::stof(s_in);
        temperature=std::stof(temp_in);
        singleObs.push_back(density);
        singleObs.push_back(speed);
        singleObs.push_back(temperature);
        //vectorOfObs.push_back(singleObs); To be used in Satellite storage
    }
    std::vector<float> getObs();
};

#endif //AURORA9_PLASMA_OBS_H
