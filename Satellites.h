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
    ///
    /// \param newSat
    void addSatellite(Satellite newSat);
    ///
    /// \param given_issue_dateTime
    /// \return
    Satellite getSingleSatObs(std::string given_issue_dateTime);
    ///
    /// \return
    float getDistance();
    ///
    /// \return
    std::string getProdID(){return productID;}
    ///
    /// \param newProdID
    void setProdID(std::string newProdID){productID = std::move(newProdID);}
    ///
    /// \return
    std::string getIssueDateTime() {return issue_dateTime;}
    ///
    /// \param new_issue_dateTime
    void setIssueDateTime(std::string new_issue_dateTime) {issue_dateTime = new_issue_dateTime;}
    ///
    /// \return
    std::string getMessage(){return message;}
    ///
    /// \param newMessage
    void setMessage(std::string newMessage){message = std::move(newMessage);}
    ///
    /// \return
    float getBXGSE() const {return bx_gse; };
    ///
    /// \param newBXGSE
    /// \return
    float setBXGSE(float newBXGSE) {bx_gse = newBXGSE; return bx_gse; };
    ///
    /// \return
    float getBYGSE() const {return by_gse; };
    ///
    /// \param newBYGSE
    /// \return
    float setBYGSE(float newBYGSE) {by_gse = newBYGSE; return by_gse; };
    ///
    /// \return
    float getBZGSE() const {return bz_gse; };
    ///
    /// \param newBZGSE
    /// \return
    float setBZGSE(float newBZGSE) {bz_gse = newBZGSE; return bz_gse; };
    ///
    /// \return
    float getPhiGSE() const {return phi_gse; };
    ///
    /// \param newPhiGSE
    /// \return
    float setPhiGSE(float newPhiGSE) {phi_gse = newPhiGSE; return phi_gse; };
    ///
    /// \return
    float getThetaGSE() const {return theta_gse; };
    ///
    /// \param newThetaGSE
    /// \return
    float setThetaGSE(float newThetaGSE) {theta_gse = newThetaGSE; return theta_gse; };
    ///
    /// \return
    float getBXGSM() const {return bx_gsm; };
    ///
    /// \param newBXGSM
    /// \return
    float setBXGSM(float newBXGSM) {bx_gsm = newBXGSM; return bx_gsm; };
    ///
    /// \return
    float getBYGSM() const {return by_gsm; };
    ///
    /// \param newBYGSM
    /// \return
    float setBYGSM(float newBYGSM) {by_gsm = newBYGSM; return by_gsm; };
    ///
    /// \return
    float getBZGSM() const {return bz_gsm; };
    ///
    /// \param newBZGSM
    /// \return
    float setBZGSM(float newBZGSM) {bz_gsm = newBZGSM; return bz_gsm; };
    ///
    /// \return
    float getPhiGSM() const {return phi_gsm; };
    ///
    /// \param newPhiGSM
    /// \return
    float setPhiGSM(float newPhiGSM) {phi_gsm = newPhiGSM; return phi_gsm; };
    ///
    /// \return
    float getThetaGSM() const {return theta_gsm; };
    ///
    /// \param newThetaGSM
    /// \return
    float setThetaGSM(float newThetaGSM) {theta_gsm = newThetaGSM; return theta_gsm; };
    ///
    /// \return
    float getDensity() const {return density; };
    ///
    /// \param newDensity
    /// \return
    float setDensity(float newDensity) {density = newDensity; return density; };
    ///
    /// \return
    float getSpeed() const {return speed; };
    ///
    /// \param newSpeed
    /// \return
    float setSpeed(float newSpeed) {speed = newSpeed; return speed; };
    ///
    /// \return
    float getTemp() const {return temp; };
    ///
    /// \param newTemp
    /// \return
    float setTemp(float newTemp) {temp = newTemp; return temp; };

};


#endif //AURORA9_SATELLITES_H
