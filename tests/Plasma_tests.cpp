//
// Created by zebra on 3/15/2024.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "Plasma_Obs.h"
#include <plasmaReaderFactory.h>
#include "Plasma_Obs.h"
#include "PlasmaReader_JSON.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using json = nlohmann::json;

float tolerance=0.001;
Plasma_data pd;
TEST_CASE("readObs Test and vector Test") {
    pd.readObs("2024-03-15 00:06:00.000", "1.39", "408.7", "124177");
    REQUIRE(pd.getTime_Tag() == "2024-03-15 00:06:00.000");
    REQUIRE_THAT(pd.getDensity(), Catch::Matchers::WithinAbs(1.39, tolerance));
    std::cout << "Density is 1.39" << std::endl;
    REQUIRE_THAT(pd.getSpeed(), Catch::Matchers::WithinAbs(408.7, tolerance));
    REQUIRE_THAT(pd.getTemperature(), Catch::Matchers::WithinAbs(124177, tolerance));
    REQUIRE_THAT(pd.getObs().at(0), Catch::Matchers::WithinAbs(1.39, tolerance));
    std::cout << "Density is still 1.39" << std::endl;
    REQUIRE_THAT(pd.getObs().at(1), Catch::Matchers::WithinAbs(408.7, tolerance));
    REQUIRE_THAT(pd.getObs().at(2), Catch::Matchers::WithinAbs(124177, tolerance));
}

   TEST_CASE("JSON parse test"){
    std::string_view stringData = "[\n [\n \"time_tag\",\n \"density\",\n \"speed\",\n \"temperature\"\n ],\n"
                                  " [ \"2024-03-16 17:32:00.000\",\n \"0.77\",\n \"362.2\",\n \"92018\"\n ]\n ]\n";
    plasmaReaderFactory factory;

    std::shared_ptr<PlasmaReader_JSON> newReader = factory.createPlasmaReader(stringData);
    std::vector<std::shared_ptr<Plasma_data>> parsedData = newReader->parseData();
    std::string time_tag = parsedData[1]->getTime_Tag();
    std::cout << time_tag << std::endl;
    float density = parsedData[1]->getDensity();
    std::cout << density << std::endl;
    float speed = parsedData[1]->getSpeed();
    std::cout << speed << std::endl;
    float temperature = parsedData[1]->getTemperature();
    std::cout << temperature << std::endl;
    REQUIRE(time_tag == "2024-03-16 17:32:00.000");
    REQUIRE_THAT(density,Catch::Matchers::WithinAbs(0.77, tolerance));
    REQUIRE_THAT(speed,Catch::Matchers::WithinAbs(362.2, tolerance));
    REQUIRE_THAT(temperature,Catch::Matchers::WithinAbs(92018, tolerance));
    std::cout << "JSON parsing completed"<<std::endl;
}