//
// Created by vikin on 3/15/2024.
//

#ifndef AURORA9_SATELLITES_H
#define AURORA9_SATELLITES_H
#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Satellites {
private:
     std::vector<std::shared_ptr<Satellites>> AllSatellites;
public:
    Satellites() = default;
    virtual ~Satellites(){};
    std::shared_ptr<Satellites> getSingleSatObs(std::string given_issue_dateTime);
    void addSatellite(std::shared_ptr<Satellites> newSat);
    virtual std::string getIssueDateTime() = 0;
    std::vector<std::shared_ptr<Satellites>> getSatVector(){std::cout<< AllSatellites.size()<<std::endl; return AllSatellites;};
    void setSatVector(std::vector<std::shared_ptr<Satellites>> newSatVector){ AllSatellites = newSatVector;};
};
class SingleSatellite : public Satellites{
private:
    std::string productID;
    std::string issue_dateTime;
    std::string message;
    float density;
    float speed;
    float temp;
    float bx_gse;
    float by_gse;
    float bz_gse;
    float bx_gsm;
    float by_gsm;
    float bz_gsm;
    float theta_gsm;
    float phi_gsm;
    float theta_gse;
    float phi_gse;
public:
    SingleSatellite(){};
    virtual ~SingleSatellite(){};
    std::string getProdID(){return productID;}
    void setProdID(std::string newProdID){productID = newProdID;}
    std::string getIssueDateTime(){return issue_dateTime;}
    void setIssueDateTime(std::string new_issue_dateTime){issue_dateTime = new_issue_dateTime;}
    std::string getMessage(){return message;}
    void setMessage(std::string newMessage){message = newMessage;}
    float getBXGSE() {return bx_gse; };
    float setBXGSE(float newBXGSE) {bx_gse = newBXGSE; return bx_gse; };
    float getBYGSE() {return by_gse; };
    float setBYGSE(float newBYGSE) {by_gse = newBYGSE; return by_gse; };
    float getBZGSE() {return bz_gse; };
    float setBZGSE(float newBZGSE) {bz_gse = newBZGSE; return bz_gse; };
    float getPhiGSE() {return phi_gse; };
    float setPhiGSE(float newPhiGSE) {phi_gse = newPhiGSE; return phi_gse; };
    float getThetaGSE() {return theta_gse; };
    float setThetaGSE(float newThetaGSE) {theta_gse = newThetaGSE; return theta_gse; };
    float getBXGSM() {return bx_gsm; };
    float setBXGSM(float newBXGSM) {bx_gsm = newBXGSM; return bx_gsm; };
    float getBYGSM() {return by_gsm; };
    float setBYGSM(float newBYGSM) {by_gsm = newBYGSM; return by_gsm; };
    float getBZGSM() {return bz_gsm; };
    float setBZGSM(float newBZGSM) {bz_gsm = newBZGSM; return bz_gsm; };
    float getPhiGSM() {return phi_gsm; };
    float setPhiGSM(float newPhiGSM) {phi_gsm = newPhiGSM; return phi_gsm; };
    float getThetaGSM() {return theta_gsm; };
    float setThetaGSM(float newThetaGSM) {theta_gsm = newThetaGSM; return theta_gsm; };
    float getDensity() {return density; };
    float setDensity(float newDensity) {density = newDensity; return density; };
    float getSpeed() {return speed; };
    float setSpeed(float newSpeed) {speed = newSpeed; return speed; };
    float getTemp() {return temp; };
    float setTemp(float newTemp) {temp = newTemp; return temp; };

};


#endif //AURORA9_SATELLITES_H
