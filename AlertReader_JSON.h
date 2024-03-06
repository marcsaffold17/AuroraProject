//
// Created by msaff on 2/22/2024.
//

#ifndef AURORA9_ALERTREADER_JSON_H
#define AURORA9_ALERTREADER_JSON_H

#include "IAlertReader.h"
#include <vector>

class AlertReader_JSON : public IAlertReader {
private:
    //Holds alert data internally for decoupling as of now
    const std::string product;
    const std::string message;
    const std::string timeDate;
public:
    //Holds an internal vector, for each alert to be added to and later returned OUTSIDE of the class
    std::vector< std::shared_ptr<IAlertReader>> alertVector;
    //Holds the file that is intended to be parsed
    std::string_view JSONFile;
    //Constructor for just the JSON file input
    AlertReader_JSON( std::string_view &JsonFile){ JSONFile = JsonFile;};
    //Constructor to be used for creating Alerts
    AlertReader_JSON(std::string_view &JsonFile, std::string Product, std::string TimeDate, std::string Message){Product = product; TimeDate = timeDate; Message = message; JsonFile = JSONFile;};
    //Parsing Completion Checker
    virtual ~AlertReader_JSON(){};
    //Returns a vector of IAlertReaders, but in reality it returns AlertReader_JSON instances that hold Alert Data
    std::vector< std::shared_ptr<IAlertReader>> parseData() override;
    std::string getProduct() override;
    std::string getMessage() override;
    std::string getTimeDate() override;
};


#endif //AURORA9_ALERTREADER_JSON_H
