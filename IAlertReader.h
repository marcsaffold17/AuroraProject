//
// Created by vikin on 2/22/2024.
//

#ifndef AURORA9_IALERTREADER_H
#define AURORA9_IALERTREADER_H
#include <string>
#include <vector>
#include <memory>

class IAlertReader{
        public:


            // Removed "std::string &message, std::string &product, std::string &timeDate" Parameter
            virtual std::vector< std::shared_ptr< IAlertReader >> parseData() = 0;
            virtual std::string getProduct() = 0;
            virtual std::string getMessage() = 0;
            virtual std::string getTimeDate() = 0;
        };


#endif //AURORA9_IALERTREADER_H
