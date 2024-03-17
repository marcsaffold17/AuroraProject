//
// Created by zebra on 3/15/2024.
//

#ifndef AURORA9_PLASMAREADERFACTORY_H
#define AURORA9_PLASMAREADERFACTORY_H

#include <memory>
#include "Plasma_Obs.h"
#include <PlasmaReader_JSON.h>
#include <string>

class plasmaReaderFactory {
public:
    plasmaReaderFactory() = default;
    //Returns plasmaReaders to be expansible to other file types
    std::shared_ptr<PlasmaReader_JSON> createPlasmaReader( std::string_view &file )
    {
        return std::make_shared< PlasmaReader_JSON > (file);
    };
};

#endif //AURORA9_PLASMAREADERFACTORY_H
