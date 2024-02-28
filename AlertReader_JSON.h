//
// Created by msaff on 2/22/2024.
//

#ifndef AURORA9_ALERTREADER_JSON_H
#define AURORA9_ALERTREADER_JSON_H

#include "IAlertReader.h"

class AlertReader_JSON : public IAlertReader {
public:
const std::string &product = "TIIA";
const std::string &message = "*insert space stuff*";
const std::string &timeDate = "2024-02-02 12:06:50.743";

    AlertReader_JSON() = default;
    bool isParsingCompleted() const override;
    void extractNextDataElement() override;
};


#endif //AURORA9_ALERTREADER_JSON_H
