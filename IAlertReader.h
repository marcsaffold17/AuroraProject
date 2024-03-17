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
            ///
            /// \return
            virtual std::vector< std::shared_ptr< IAlertReader >> parseData() = 0;
            ///
            /// \return
            virtual std::string getProduct() = 0;
            ///
            /// \return
            virtual std::string getMessage() = 0;
            ///
            /// \return
            virtual std::string getTimeDate() = 0;
        };


#endif //AURORA9_IALERTREADER_H
