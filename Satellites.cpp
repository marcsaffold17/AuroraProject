//
// Created by vikin on 3/15/2024.
//

#include "Satellites.h"
std::shared_ptr<Satellites> Satellites::getSingleSatObs(const std::string given_issue_dateTime)
{
    int numSats = AllSatellites.size();
    bool satInArray = false;
    for (int i = 0; i < numSats; i++){
        if (AllSatellites[i]->getIssueDateTime() == given_issue_dateTime){
            satInArray = true;
            return AllSatellites[i];
        }
    }
    if (satInArray == false){
        std::shared_ptr<SingleSatellite> newSat;
        newSat->setIssueDateTime(given_issue_dateTime);
        AllSatellites.push_back(newSat);
    }
    return AllSatellites[numSats - 1];
}
void Satellites::addSatellite(std::shared_ptr<Satellites> newSat)
{
    AllSatellites.push_back(newSat);
}