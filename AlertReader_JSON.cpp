//
// Created by msaff on 2/22/2024.
//

#include "AlertReader_JSON.h"
#include <iostream>

// Change definition
void AlertReader_JSON::extractNextDataElement() {
    std::cout << "Product ID: " << &product << "\n";
    std::cout << "Date and Time: " << &timeDate << "\n";
    std::cout << "Message: " << &message << "\n";
}