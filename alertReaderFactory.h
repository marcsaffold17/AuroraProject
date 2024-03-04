//
// Created by msaff on 2/27/2024.
//

#ifndef AURORA9_ALERTREADERFACTORY_H
#define AURORA9_ALERTREADERFACTORY_H

#include <memory>
#include "IAlertReader.h"
#include <AlertReader_JSON.h>
#include <string>

class alertReaderFactory {
public:
    alertReaderFactory() = default;
    //Returns IAlertReaders to be expansible to other file types
    std::shared_ptr<AlertReader_JSON> createAlertReader( std::string_view &file )
    {
        return std::make_shared< AlertReader_JSON > (file);
    };
};


#endif //AURORA9_ALERTREADERFACTORY_H
