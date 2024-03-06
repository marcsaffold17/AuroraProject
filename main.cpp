#include <nlohmann/json.hpp>
#include <iostream>
#include <alertReaderFactory.h>
#include "IAlertReader.h"
#include "AlertReader_JSON.h"
#include <vector>
#include <string>
#include <memory>
using json = nlohmann::json;
int main()
{
    std::string_view stringData = "[\n"
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
    std::shared_ptr<AlertReader_JSON> newReader = factory.createAlertReader( stringData);
    std::vector<std::shared_ptr<IAlertReader>> parsedData = newReader->parseData();
    std::string product = parsedData[0]->getProduct();
    std::cout << product << std::endl;
    std::string message = parsedData[0]->getMessage();
    std::cout << message << std::endl;
    std::string timeDate = parsedData[0]->getTimeDate();
    std::cout << timeDate << std::endl;
}