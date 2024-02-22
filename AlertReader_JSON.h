//
// Created by msaff on 2/22/2024.
//

#ifndef AURORA9_ALERTREADER_JSON_H
#define AURORA9_ALERTREADER_JSON_H

#include <iostream>
#include "IAlertReader.h"

class AlertReader_JSON : public IAlertReader {
public:
    AlertReader_JSON() = default;
    bool isParsingCompleted() const;
    void extractNextDataElement( std::string &message, std::string &product, std::string &timeDate );
};


#endif //AURORA9_ALERTREADER_JSON_H
