//
// Created by zebra on 3/15/2024.
//

#include "PlasmaReader_JSON.h"
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


std::vector< std::shared_ptr<Plasma_data>> PlasmaReader_JSON::parseData()
{
    //Access the file stored by the current instance of the reader
    std::string_view file = this->JSONFile;
    //Parse the file
    json jsonData = json::parse( file );
    //Check if it's an array
    if (jsonData.is_array()) {
        //Establish storage for data points in each JSON alert
        std::vector <std::string> time_tags;
        std::vector <std::string> densities;
        std::vector <std::string> speeds;
        std::vector <std::string> temperatures;
        //Add each member to their respective vectors to be held
        for (const auto &jsonData : jsonData){
            std::string time_tag = jsonData["time_tag"];
            time_tags.push_back(time_tag);
            std::string density = jsonData["density"];
            densities.push_back(density);
            std::string speed = jsonData["speed"];
            speeds.push_back(speed);
            std:: string temperature = jsonData["temperature"];
            temperatures.push_back(temperature);
        }
        //Get the number of alerts by the number of product ID's
        int numAlerts = time_tags.size();
        //For each alert...
        for (int i = 0; i < numAlerts; i++)
        {
            //Empty string_view, used for construction purposes (It broke every time I tried to do it without this)
            //Creates new instances of AlertReaders, but to hold AlertData, not to parse data
            std::shared_ptr<PlasmaDataHolder> newPlasma = std::make_shared<PlasmaDataHolder>(" ", " ", " "," ");
            std::string currTime_tag = time_tags[i];
            std::string currDensity = densities[i];
            std::string currSpeed = speeds[i];
            std::string currTemperature = temperatures[i];
            newPlasma->setTime_tag(currTime_tag);
            newPlasma->setDensity(currDensity);
            newPlasma->setSpeed(currSpeed);
            newPlasma->setTemperature(currTemperature);

            newPlasma->printPlasma();
            //Now a vector of Alerts, to be returned and iterated through
            PlasmaVector.push_back(newPlasma);
        }
    }
    else
    {
        std::shared_ptr<PlasmaDataHolder> newPlasma = std::make_shared<PlasmaDataHolder>(jsonData["time_tag"], jsonData["density"], jsonData["speed"], jsonData["temperature"]);
        PlasmaVector.push_back(newPlasma);
    }
    //Return the vector
    return PlasmaVector;
}
std::string PlasmaReader_JSON::getTime_Tag()
{
    return time_tag;
}
float PlasmaReader_JSON::getDensity()
{
    return std::stof(density);
}
float PlasmaReader_JSON::getSpeed()
{
    return std::stof(speed);
}

float PlasmaReader_JSON::getTemperature() {
    return std::stof(temperature);
}


std::string PlasmaDataHolder::getTime_Tag()
{
    return time_tag;
}
float PlasmaDataHolder::getDensity()
{
    return std::stof(density);
}
float PlasmaDataHolder::getSpeed()
{
    return std::stof(speed);
}

float PlasmaDataHolder::getTemperature(){
    return std::stof(temperature);
}
