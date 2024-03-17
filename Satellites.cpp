//
// Created by vikin on 3/15/2024.
//

#include "Satellites.h"
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
