// Tests for AlertReader and Factory
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <nlohmann/json.hpp>
#include <iostream>
#include <alertReaderFactory.h>
#include "IAlertReader.h"
#include "AlertReader_JSON.h"
#include <vector>
#include <string>
using json = nlohmann::json;
//Test One - isParsingCompleted
//Test Two - extract by giving it json and making sure it says the same thing
class TestSatellite {
private:
    std::string product;
    std::string timeDate;
    std::string message;
public:
    std::string getProductSat(){return product;};
    std::string getTimeDateSat(){return timeDate;};
    std::string getMessageSat(){return message;};
    TestSatellite(std::string Product, std::string TimeDate, std::string Message)
    {
        product = Product;
        timeDate = TimeDate;
        message = Message;
    };
    ~TestSatellite();
};
TEST_CASE("isParsingCompleted Test and extractNextDataElement Test") {
    std::string stringData = "[\n"
                                  "  {\n"
                                  "    \"product_id\": \"TIIA\",\n"
                                  "    \"issue_datetime\": \"2024-02-02 12:06:50.743\",\n"
                                  "    \"message\": \"Space Weather Message Code: ALTTP2\\r\\nSerial Number: 1264\\r\\nIssue Time: 2024 Feb 02 1206 UTC\\r\\n\\r\\n"
                                  "ALERT: Type II Radio Emission\\r\\nBegin Time: 2024 Feb 02 1107 UTC\\r\\nEstimated Velocity: 874 km/s\\r\\n\\r\\n\\r\\n\\r\\n"
                                  "Description: Type II emissions occur in association with eruptions on the sun and typically indicate a coronal mass ejection is "
                                  "associated with a flare event.\"\n"
                                  "  },\n"
                                  "  {\n"
                                  "    \"product_id\": \"TIIA\",\n"
                                  "    \"issue_datetime\": \"2024-02-02 03:48:55.587\",\n"
                                  "    \"message\": \"Space Weather Message Code: ALTTP2\\r\\nSerial Number: 1263\\r\\nIssue Time: 2024 Feb 02 0348 UTC\\r\\n\\r\\n"
                                  "ALERT: Type II Radio Emission\\r\\nBegin Time: 2024 Feb 02 0306 UTC\\r\\nEstimated Velocity: 1444 km/s\\r\\n\\r\\n\\r\\n\\r\\n"
                                  "Description: Type II emissions occur in association with eruptions on the sun and typically indicate a coronal mass ejection is "
                                  "associated with a flare event.\"\n"
                                  "  },\n"
                                  "  {\n"
                                  "    \"product_id\": \"P11S\",\n"
                                  "    \"issue_datetime\": \"2024-01-30 11:53:04.203\",\n"
                                  "    \"message\": \"Space Weather Message Code: SUMPX1\\r\\nSerial Number: 107\\r\\nIssue Time: 2024 Jan 30 1153 UTC\\r\\n\\r\\n"
                                  "SUMMARY: Proton Event 10MeV Integral Flux exceeded 10pfu\\r\\nBegin Time: 2024 Jan 29 0615 UTC\\r\\nMaximum "
                                  "Time: 2024 Jan 29 1805 UTC\\r\\nEnd Time: 2024 Jan 30 0425 UTC\\r\\nMaximum 10MeV Flux: 137 pfu\\r\\nNOAA "
                                  "Scale: S2 - Moderate\\r\\n\\r\\nNOAA Space Weather Scale descriptions can be found at\\r\\n"
                                  "www.swpc.noaa.gov/noaa-scales-explanation\"\n"
                                  "  }\n"
                                  "]";
    alertReaderFactory factory;

// Stores pointers
    //std::vector<std::shared_ptr<IAlertReader>> createAlertReaderVec;
// Stores files created by factory
    //std::vector<std::string_view> fileType;
    //fileType.push_back(stringData);
    //for (const auto &fileType: fileType) {
    //    auto file = factory.createAlertReader(fileType);
    //    if (file != nullptr) {
    //        createAlertReaderVec.push_back(file);
    //    }
    //}
    std::shared_ptr<AlertReader_JSON> newReader = factory.createAlertReader( stringData);
    //createAlertReaderVec.push_back(newReader);
    //REQUIRE(!createAlertReaderVec.empty());
    //for (const auto &file: createAlertReaderVec) {
        //std::cout << newReader->isParsingCompleted() << std::endl;
        std::vector<std::shared_ptr<IAlertReader>> parsedData = newReader->parseData();
        std::string product = parsedData[1]->getProduct();
        std::string message = parsedData[1]->getMessage();
        std::string timeDate = parsedData[1]->getTimeDate();
        REQUIRE(product == "TIIA");
        REQUIRE(message == "2024-02-02 12:06:50.743");
        REQUIRE(timeDate == "Space Weather Message Code: ALTTP2\r\nSerial Number: 1263\r\nIssue Time: 2024 Feb 02 0348 UTC\r\n\r\nALERT: Type II Radio Emission\r\nBegin Time: 2024 Feb 02 0306 UTC\r\nEstimated Velocity: 1444 km/s\r\n\r\n\r\n\r\nDescription: Type II emissions occur in association with eruptions on the sun and typically indicate a coronal mass ejection is associated with a flare event.");
        //Test Three - creating satellite observation, matching parameters
        TestSatellite *newObs = new TestSatellite(product, message, timeDate);
        REQUIRE(newObs->getProductSat() == "TIIA");
        REQUIRE(newObs->getMessageSat() == "2024-02-02 12:06:50.743");
        REQUIRE(newObs->getTimeDateSat() == "Space Weather Message Code: ALTTP2\r\nSerial Number: 1263\r\nIssue Time: 2024 Feb 02 0348 UTC\r\n\r\nALERT: Type II Radio Emission\r\nBegin Time: 2024 Feb 02 0306 UTC\r\nEstimated Velocity: 1444 km/s\r\n\r\n\r\n\r\nDescription: Type II emissions occur in association with eruptions on the sun and typically indicate a coronal mass ejection is associated with a flare event.");
    //}

}

//Test Four - adding observation to the vector to be stored
//Test createAlertReader