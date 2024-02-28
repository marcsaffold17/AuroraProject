// Tests for AlertReader and Factory
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <nlohmann/json.hpp>
#include <iostream>
#include "alertReaderFactory.h"
#include <vector>
using json = nlohmann::json;
//Test One - isParsingCompleted
//Test Two - extract by giving it json and making sure it says the same thing
TEST_CASE("isParsingCompleted Test and extractNextDataElement Test") {
    alertReaderFactory factory;

// Stores pointers
    std::vector<std::shared_ptr<IAlertReader>> createAlertReader;
// Stores files created by factory
    std::vector<std::string> fileType{"json", "json", "json"};

    for (const auto &fileType: fileType) {
        auto file = factory.createAlertReader(fileType);
        if (file != nullptr) {
            createAlertReader.push_back(file);
        }
    }
    REQUIRE(!createAlertReader.empty());
    for (const auto &file: createAlertReader) {
        std::cout << file->isParsingCompleted() << std::endl;
        file->extractNextDataElement();
        REQUIRE(product == "");
        REQUIRE(message == "");
        REQUIRE(timeDate == "");
    }
}
//Test Two - extract by giving it json and making sure it says the same thing
//Test Three - creating satellite observation, matching parameters
//Test Four - adding observation to the vector to be stored
//Test createAlertReader