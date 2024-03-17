//
// Created by zebra on 3/12/2024.
//

#include "Plasma_Obs.h"


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

