//
// Created by vikin on 2/22/2024.
//

#ifndef AURORA9_IALERTREADER_H
#define AURORA9_IALERTREADER_H
#include <string>

class IAlertReader{
        public:
            virtual bool isParsingCompleted() const = 0;
            virtual void extractNextDataElement( std::string &message, std::string &product, std::string &timeDate) = 0;
        };
#endif //AURORA9_IALERTREADER_H
