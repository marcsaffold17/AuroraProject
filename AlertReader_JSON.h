//
// Created by msaff on 2/22/2024.
//

#ifndef AURORA9_ALERTREADER_JSON_H
#define AURORA9_ALERTREADER_JSON_H

#include "IAlertReader.h"

class AlertReader_JSON : public IAlertReader {
private:
    const std::string product;
    const std::string message;
    const std::string timeDate;
public:
    AlertReader_JSON();
    bool isParsingCompleted() const override;
    void extractNextDataElement() override;
};


#endif //AURORA9_ALERTREADER_JSON_H
