//
// Created by msaff on 2/15/2024.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("Mock Test 3")
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

json jsonData = json::parse( stringData );
if (jsonData.is_array()) {
int arraySize = jsonData.size();
REQUIRE( arraySize == 3 );
for ( json& element : jsonData) {
auto iter = element.find("product_id");
REQUIRE(iter != element.end());
iter = element.find("issue_datetime");
REQUIRE(iter != element.end());
iter = element.find("message");
REQUIRE(iter != element.end());
}

json element1 = jsonData[0];
json element2 = jsonData[1];
json element3 = jsonData[2];

REQUIRE(element1["product_id"] == "TIIA");
REQUIRE(element1["issue_datetime"] == "2024-02-02 12:06:50.743");
REQUIRE(element1["message"] == "Space Weather Message Code: ALTTP2\r\nSerial Number: 1264\r\nIssue Time: 2024 Feb 02 1206 UTC\r\n\r\n"
"ALERT: Type II Radio Emission\r\nBegin Time: 2024 Feb 02 1107 UTC\r\nEstimated Velocity: 874 km/s\r\n\r\n\r\n\r\n"
"Description: Type II emissions occur in association with eruptions on the sun and typically indicate a coronal "
"mass ejection is associated with a flare event.");

REQUIRE(element2["product_id"] == "TIIA");
REQUIRE(element2["issue_datetime"] == "2024-02-02 03:48:55.587");
REQUIRE(element2["message"] == "Space Weather Message Code: ALTTP2\r\nSerial Number: 1263\r\nIssue Time: 2024 Feb 02 0348 UTC\r\n\r\n"
"ALERT: Type II Radio Emission\r\nBegin Time: 2024 Feb 02 0306 UTC\r\nEstimated Velocity: 1444 km/s\r\n\r\n\r\n\r\n"
"Description: Type II emissions occur in association with eruptions on the sun and typically indicate a coronal mass ejection "
"is associated with a flare event.");

REQUIRE(element3["product_id"] == "P11S");
REQUIRE(element3["issue_datetime"] == "2024-01-30 11:53:04.203");
REQUIRE(element3["message"] == "Space Weather Message Code: SUMPX1\r\nSerial Number: 107\r\nIssue Time: 2024 Jan 30 1153 UTC\r\n\r\n"
"SUMMARY: Proton Event 10MeV Integral Flux exceeded 10pfu\r\nBegin Time: 2024 Jan 29 0615 UTC\r\n"
"Maximum Time: 2024 Jan 29 1805 UTC\r\nEnd Time: 2024 Jan 30 0425 UTC\r\nMaximum 10MeV Flux: 137 pfu\r\n"
"NOAA Scale: S2 - Moderate\r\n\r\nNOAA Space Weather Scale descriptions can be found at\r\n"
"www.swpc.noaa.gov/noaa-scales-explanation");
}
}