//
// Created by zebra on 3/15/2024.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "Plasma_Obs.cpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using json = nlohmann::json;

float tolerance=0.001;
Plasma_data pd;
TEST_CASE("readObs Test and vector Test"){
    pd.readObs("2024-03-15 00:06:00.000","1.39","408.7","124177");
    REQUIRE(pd.getTime_Tag()=="2024-03-15 00:06:00.000");
    REQUIRE_THAT(pd.getDensity(),Catch::Matchers::WithinAbs(1.39, tolerance));
    REQUIRE_THAT(pd.getSpeed(),Catch::Matchers::WithinAbs(408.7, tolerance));
    REQUIRE_THAT(pd.getTemperature(),Catch::Matchers::WithinAbs(124177, tolerance));
    REQUIRE_THAT(pd.getObs().at(0), Catch::Matchers::WithinAbs(1.39, tolerance));
    REQUIRE_THAT(pd.getObs().at(1), Catch::Matchers::WithinAbs(408.7, tolerance));
    REQUIRE_THAT(pd.getObs().at(2), Catch::Matchers::WithinAbs(124177, tolerance));
}