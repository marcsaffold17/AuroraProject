//
// Created by zebra on 3/12/2024.
//

#include "Plasma_Obs.h"

///
/// \return time_tag
std::string Plasma_data::getTime_Tag() {
    return time_tag;
}
///
/// \return density
float Plasma_data::getDensity() {
    return density;
}
///
/// \return speed
float Plasma_data::getSpeed() {
    return speed;
}

///
/// \return temperature
float Plasma_data::getTemperature() {
    return temperature;
}

///
/// \return singleObs
std::vector<float> Plasma_data::getObs(){
    return singleObs;
}

