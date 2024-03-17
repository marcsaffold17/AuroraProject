//
// Created by vikin on 3/15/2024.
//

#include "Satellites.h"
#include <math.h>
Satellite Satellite::getSingleSatObs(const std::string given_issue_dateTime)
{
    int numSats = AllSatellites.size();
    bool satInArray = false;
    for (int i = 0; i < numSats; i++){
        if (AllSatellites[i].getIssueDateTime() == given_issue_dateTime){
            satInArray = true;
            return AllSatellites[i];
        }
    }
    if (satInArray == false){
        Satellite newSat;
        newSat.setIssueDateTime(given_issue_dateTime);
        AllSatellites.push_back(newSat);
    }
    return AllSatellites[numSats - 1];
}

void Satellite::addSatellite(Satellite newSat)
{
    AllSatellites.push_back(newSat);
}

float Satellite::getDistance()
{
    float x_component = (bx_gsm - bx_gse)*(bx_gsm - bx_gse);
    float y_component = (by_gsm - by_gse)*(by_gsm - by_gse);
    float z_component = (bz_gsm - bz_gse)*(bz_gsm - bz_gse);
    return sqrt((x_component + y_component + z_component));
}
