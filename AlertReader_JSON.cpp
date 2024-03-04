//
// Created by msaff on 2/22/2024.
//

#include "AlertReader_JSON.h"
#include <iostream>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


std::vector< std::shared_ptr<IAlertReader>> AlertReader_JSON::parseData()
{
    //Access the file stored by the current instance of the reader
    std::string_view file = this->JSONFile;
    //Parse the file
    json jsonData = json::parse( file );
    //Check if it's an array
    if (jsonData.is_array()) {
        //Establish storage for data points in each JSON alert
        std::vector <std::string> products;
        std::vector <std::string> timeDates;
        std::vector <std::string> messages;
        //Add each member to their respective vectors to be held
        for (const auto &jsonData : jsonData){
            products.push_back(jsonData["product_id"]);
            timeDates.push_back(jsonData["timeDates"]);
            messages.push_back(jsonData["messages"]);
        }
        //Get the number of alerts by the number of product ID's
        int numAlerts = products.size();
        //For each alert...
        for (int i = 0; i < numAlerts; i++)
        {
            //Empty string_view, used for construction purposes (It broke every time I tried to do it without this)
            std::string_view emptyStringView = " ";
            //Creates new instances of AlertReaders, but to hold AlertData, not to parse data
            std::shared_ptr<AlertReader_JSON> newAlert = std::make_shared<AlertReader_JSON>(emptyStringView, products[i], timeDates[i], messages[i]);

            //Now a vector of Alerts, to be returned and iterated through
            alertVector.push_back(newAlert);
        }
    }
    //Return the vector
    return alertVector;
}
