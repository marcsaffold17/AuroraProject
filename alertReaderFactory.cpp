//
// Created by msaff on 2/27/2024.
//

#include "alertReaderFactory.h"
#include <AlertReader_JSON.h>
// Remove when done
#include <iostream>

std::shared_ptr<IAlertReader> alertReaderFactory::createAlertReader(const std::string &fileType)
{
if (fileType == "json")
    // Test to see if the "if" statement works correctly. Remove when done
    std::cout << "The factory works";
// Code breaks on the line below
    // return std::make_shared< AlertReader_JSON > ();
    //
else
    return nullptr;
}