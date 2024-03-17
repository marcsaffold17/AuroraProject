//
// Created by vikin on 3/15/2024.
//

#ifndef AURORA9_SATELLITES_H
#define AURORA9_SATELLITES_H
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <memory>


class Satellite{
private:
    std::vector<Satellite> AllSatellites;
    std::string productID;
    std::string issue_dateTime;
    std::string message;
    float density{};
    float speed{};
    float temp{};
    float bx_gse{};
    float by_gse{};
    float bz_gse{};
    float bx_gsm{};
    float by_gsm{};
    float bz_gsm{};
    float theta_gsm{};
    float phi_gsm{};
    float theta_gse{};
    float phi_gse{};
public:
    Satellite() = default;
    ~Satellite()  = default;
    void addSatellite(Satellite newSat);
    Satellite getSingleSatObs(std::string given_issue_dateTime);
    std::string getProdID(){return productID;}
    void setProdID(std::string newProdID){productID = std::move(newProdID);}
    std::string getIssueDateTime() {return issue_dateTime;}
    void setIssueDateTime(std::string new_issue_dateTime) {issue_dateTime = new_issue_dateTime;}
    std::string getMessage(){return message;}
    void setMessage(std::string newMessage){message = std::move(newMessage);}
    float getBXGSE() const {return bx_gse; };
    float setBXGSE(float newBXGSE) {bx_gse = newBXGSE; return bx_gse; };
    float getBYGSE() const {return by_gse; };
    float setBYGSE(float newBYGSE) {by_gse = newBYGSE; return by_gse; };
    float getBZGSE() const {return bz_gse; };
    float setBZGSE(float newBZGSE) {bz_gse = newBZGSE; return bz_gse; };
    float getPhiGSE() const {return phi_gse; };
    float setPhiGSE(float newPhiGSE) {phi_gse = newPhiGSE; return phi_gse; };
    float getThetaGSE() const {return theta_gse; };
    float setThetaGSE(float newThetaGSE) {theta_gse = newThetaGSE; return theta_gse; };
    float getBXGSM() const {return bx_gsm; };
    float setBXGSM(float newBXGSM) {bx_gsm = newBXGSM; return bx_gsm; };
    float getBYGSM() const {return by_gsm; };
    float setBYGSM(float newBYGSM) {by_gsm = newBYGSM; return by_gsm; };
    float getBZGSM() const {return bz_gsm; };
    float setBZGSM(float newBZGSM) {bz_gsm = newBZGSM; return bz_gsm; };
    float getPhiGSM() const {return phi_gsm; };
    float setPhiGSM(float newPhiGSM) {phi_gsm = newPhiGSM; return phi_gsm; };
    float getThetaGSM() const {return theta_gsm; };
    float setThetaGSM(float newThetaGSM) {theta_gsm = newThetaGSM; return theta_gsm; };
    float getDensity() const {return density; };
    float setDensity(float newDensity) {density = newDensity; return density; };
    float getSpeed() const {return speed; };
    float setSpeed(float newSpeed) {speed = newSpeed; return speed; };
    float getTemp() const {return temp; };
    float setTemp(float newTemp) {temp = newTemp; return temp; };

};


#endif //AURORA9_SATELLITES_H
