//
// Created by msaff on 2/27/2024.
//

#include "alertReaderFactory.h"
#include <AlertReader_JSON.h>

std::shared_ptr<IAlertReader> alertReaderFactory::createAlertReader(const std::string &fileType)
{
if (fileType == "json") {
    return std::make_shared< AlertReader_JSON > ();
}

else
    return nullptr;
}