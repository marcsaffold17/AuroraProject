//
// Created by msaff on 2/22/2024.
//

#ifndef AURORA9_ALERTREADER_JSON_H
#define AURORA9_ALERTREADER_JSON_H

#include "IAlertReader.h"
#include <vector>
#include <iostream>

class AlertReader_JSON : public IAlertReader {
private:
    //Holds alert data internally for decoupling as of now
    std::string product;
    std::string message;
    std::string timeDate;
public:
    //Holds an internal vector, for each alert to be added to and later returned OUTSIDE of the class
    std::vector< std::shared_ptr<IAlertReader>> alertVector;
    //Holds the file that is intended to be parsed
    std::string_view JSONFile;
    //Constructor for just the JSON file input
    AlertReader_JSON(){};
    AlertReader_JSON( std::string_view &JsonFile){ JSONFile = JsonFile;};
    //Parsing Completion Checker
    virtual ~AlertReader_JSON(){};
    //Returns a vector of IAlertReaders, but in reality it returns AlertReader_JSON instances that hold Alert Data
    std::vector< std::shared_ptr<IAlertReader>> parseData() override;
    std::string getProduct() override;
    std::string getMessage() override;
    std::string getTimeDate() override;

};
class AlertDataHolder : public AlertReader_JSON {
private:
    std::string product;
    std::string message;
    std::string timeDate;
public:
    AlertDataHolder(std::string Product, std::string TimeDate, std::string Message){Product = product;TimeDate = timeDate; Message = message;};
    virtual ~AlertDataHolder(){};
    std::string getProduct() override;
    void setProduct(std::string prodID) { product = prodID; };
    std::string getMessage() override;
    void setMessage(std::string MessageData) { message = MessageData; };
    std::string getTimeDate() override;
    void setTimeDate(std::string issue_datetime) { timeDate = issue_datetime; };
    void printAlert(){std::cout << this->product << std::endl; std::cout << this->timeDate << std::endl; std::cout << this->message << std::endl;};
};


#endif //AURORA9_ALERTREADER_JSON_H
