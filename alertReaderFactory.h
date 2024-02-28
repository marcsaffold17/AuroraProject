//
// Created by msaff on 2/27/2024.
//

#ifndef AURORA9_ALERTREADERFACTORY_H
#define AURORA9_ALERTREADERFACTORY_H

#include <memory>
#include "IAlertReader.h"
#include <string>

class alertReaderFactory {
public:
    alertReaderFactory() = default;
    virtual ~alertReaderFactory() = default;

    virtual std::shared_ptr<IAlertReader> createAlertReader(const std::string &fileType);
};


#endif //AURORA9_ALERTREADERFACTORY_H
