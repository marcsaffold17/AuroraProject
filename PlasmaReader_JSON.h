//
// Created by zebra on 3/15/2024.
//

#ifndef AURORA9_PLASMAREADER_JSON_H
#define AURORA9_PLASMAREADER_JSON_H

#include "Plasma_Obs.h"
#include <vector>
#include <iostream>

class PlasmaReader_JSON : public Plasma_data {
private:
    //Holds alert data internally for decoupling as of now
    std::string time_tag;
    std::string density;
    std::string speed;
    std::string temperature;
public:
    //Holds an internal vector, for each alert to be added to and later returned OUTSIDE of the class
    std::vector< std::shared_ptr<Plasma_data>> PlasmaVector;
    //Holds the file that is intended to be parsed
    std::string_view JSONFile;
    //Constructor for just the JSON file input
    PlasmaReader_JSON(){};
    PlasmaReader_JSON( std::string_view &JsonFile){ JSONFile = JsonFile;};
    //Parsing Completion Checker
    virtual ~PlasmaReader_JSON(){};
    //Returns a vector of IAlertReaders, but in reality it returns AlertReader_JSON instances that hold Alert Data
    std::vector< std::shared_ptr<Plasma_data>> parseData();
    std::string getTime_Tag();
    float getDensity();
    float getSpeed();
    float getTemperature();
    void readObs(std::string tt_in, std::string d_in, std::string s_in, std::string temp_in);

};

class PlasmaDataHolder : public PlasmaReader_JSON {
private:
    std::string time_tag;
    std::string density;
    std::string speed;
    std::string temperature;
public:
    PlasmaDataHolder(std::string Time_tag, std::string Density, std::string Speed, std::string Temperature){Time_tag = time_tag;Density = density; Speed = speed, Temperature = temperature;};
    virtual ~PlasmaDataHolder(){};
    std::string getTime_Tag();
    float getDensity();
    float getSpeed();
    float getTemperature();
    void readObs(std::string tt_in, std::string d_in, std::string s_in, std::string temp_in);
    void setTime_tag(std::string Time_tag) { time_tag = Time_tag; };
    void setDensity(std::string Density) { density = Density; };
    void setSpeed(std::string Speed) { speed = Speed;}
    void setTemperature(std::string Temperature) { temperature = Temperature;}
    void printPlasma(){std::cout << this->time_tag << std::endl; std::cout << this->density << std::endl; std::cout << this->speed << std::endl; std::cout << this->temperature << std::endl;};
};

#endif //AURORA9_PLASMAREADER_JSON_H
