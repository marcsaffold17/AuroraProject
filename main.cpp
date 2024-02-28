#include <iostream>
#include "alertReaderFactory.h"
#include <vector>

/**
 * File basically serves as a demo of how the factory works. I (Marcus) will probably move this code to the unit test folder.
 * The code creates three JSON objects and outputs the isParsingCompleted and extractNextDataElement once for each object.
 * The '1' is output because the Boolean is true
 *
 * TODO: Find a way to create json objects with different product, timedate, and message data
 * */


int main()
{

alertReaderFactory factory;

// Stores pointers
std::vector <std::shared_ptr<IAlertReader>> createAlertReader;
// Stores files created by factory
std::vector <std::string> fileType {"json", "json", "json"};

for (const auto& fileType : fileType) {
    auto file = factory.createAlertReader(fileType);
    if (file != nullptr) {
        createAlertReader.push_back(file);
    }
}

for (const auto& file : createAlertReader) {
    std::cout << file->isParsingCompleted() << std::endl;
    file->extractNextDataElement();
}

    return 0;
}
