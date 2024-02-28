//
// Created by msaff on 2/22/2024.
//

#include "AlertReader_JSON.h"
#include <iostream>

bool AlertReader_JSON::isParsingCompleted() const {
    return true;
}

AlertReader_JSON::AlertReader_JSON()
: product ("TIIA"), message ("*insert space stuff*"), timeDate("2024-02-02 12:06:50.743")
{

}

void AlertReader_JSON::extractNextDataElement()
{
    std::cout << "Product ID: " << product << "\n";
    std::cout << "Date and Time: " << timeDate << "\n";
    std::cout << "Message: " << message << "\n\n";
}