#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "Satellites.h"
#include <memory>

TEST_CASE("Basic constructor test and getter/setter data tests"){
    //Constructor
    Satellite newSat;
    //Product ID
    newSat.setProdID("TIIA");
    REQUIRE(newSat.getProdID() == "TIIA");
    //Time Stamp
    newSat.setIssueDateTime("2024-10:00");
    REQUIRE(newSat.getIssueDateTime() == "2024-10:00");
    //Message
    newSat.setMessage("Hello this is a satellite");
    REQUIRE(newSat.getMessage() == "Hello this is a satellite");
    //Density
    newSat.setDensity(5.05f);
    REQUIRE_THAT(newSat.getDensity(), Catch::Matchers::WithinAbs(5.05, .001));
    //Speed
    newSat.setSpeed(222.5f);
    REQUIRE_THAT(newSat.getSpeed(), Catch::Matchers::WithinAbs(222.5, .001));
    //Temp
    newSat.setTemp(33333.3f);
    REQUIRE_THAT(newSat.getTemp(), Catch::Matchers::WithinAbs(33333.3, .001));
    //B(X,Y,Z)_GSE
    newSat.setBXGSE(1.5f);
    REQUIRE_THAT(newSat.getBXGSE(), Catch::Matchers::WithinAbs(1.5, .001));
    newSat.setBYGSE(1.6f);
    REQUIRE_THAT(newSat.getBYGSE(), Catch::Matchers::WithinAbs(1.6, .001));
    newSat.setBZGSE(1.7f);
    REQUIRE_THAT(newSat.getBZGSE(), Catch::Matchers::WithinAbs(1.7, .001));
    //B(X,Y,Z)_GSM
    newSat.setBXGSM(1.8f);
    REQUIRE_THAT(newSat.getBXGSM(), Catch::Matchers::WithinAbs(1.8, .001));
    newSat.setBYGSM(1.9f);
    REQUIRE_THAT(newSat.getBYGSM(), Catch::Matchers::WithinAbs(1.9, .001));
    newSat.setBZGSM(2.0f);
    REQUIRE_THAT(newSat.getBZGSM(), Catch::Matchers::WithinAbs(2.0, .001));
    //Theta and Phi GSE
    newSat.setThetaGSE(2.1f);
    REQUIRE_THAT(newSat.getThetaGSE(), Catch::Matchers::WithinAbs(2.1, .001));
    newSat.setPhiGSE(2.2f);
    REQUIRE_THAT(newSat.getPhiGSE(), Catch::Matchers::WithinAbs(2.2, .001));
    //Theta and Phi GSM
    newSat.setThetaGSM(2.3f);
    REQUIRE_THAT(newSat.getThetaGSM(), Catch::Matchers::WithinAbs(2.3, .001));
    newSat.setPhiGSM(2.4f);
    REQUIRE_THAT(newSat.getPhiGSM(), Catch::Matchers::WithinAbs(2.4, .001));
}

TEST_CASE("Satellite Searching and adding to the overall vector")
{
    Satellite AllSats;
    Satellite newSat1;
    Satellite newSat2;
    Satellite newSat3;
    newSat1.setIssueDateTime("2024");
    newSat2.setIssueDateTime("2025");
    newSat3.setIssueDateTime("2026");
    AllSats.addSatellite(newSat1);
    AllSats.addSatellite(newSat2);
    AllSats.addSatellite(newSat3);
    //Grab the first and last observations to prove they are at both ends and filling the entire vector
    Satellite FirstObs = AllSats.getSingleSatObs("2024");
    REQUIRE(FirstObs.getIssueDateTime() == "2024");
    Satellite ThirdObs = AllSats.getSingleSatObs("2026");
    REQUIRE(ThirdObs.getIssueDateTime() == "2026");
}

TEST_CASE("Distance Calculation testing")
{
    Satellite practiceSat;
    practiceSat.setBXGSE(1.0f);
    practiceSat.setBYGSE(1.0f);
    practiceSat.setBZGSE(1.0f);
    practiceSat.setBXGSM(5.0f);
    practiceSat.setBYGSM(5.0f);
    practiceSat.setBZGSM(5.0f);
    REQUIRE_THAT(practiceSat.getDistance(), Catch::Matchers::WithinAbs(6.92820323028, .001));
}