//
// Created by ADMIN on 15/03/2024.
//

#include "jobs.h"
#include "../DesignByContract.h"


Job::Job() {
    _initCheck = this;
}

bool Job::properlyInitialized() const {
    return _initCheck == this;
}

int Job::getJobNumber() const {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getJobNumber");
    return jobNumber;
}

void Job::setJobNumber(int xjobNumber) {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setJobNumber");
    this->jobNumber = xjobNumber;}

int Job::getPageCount() const {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getPageCount");
    return pageCount;
}

void Job::setPageCount(int xpageCount) {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setPageCount");
    this->pageCount = xpageCount;
}

const std::string &Job::getUserName() const {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getUserName");
    return userName;
}

void Job::setUserName(const std::string &xuserName) {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setUserName");
    this->userName = xuserName;
}

void Job::print() {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling print");
    std::cout << "Job number: " << jobNumber << '\n';
    std::cout << "Page count: " << pageCount << '\n';
    std::cout << "User name: " << userName << '\n';
}

void Job::setType(const std::string &xType) {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setType");
    this->type = xType;
}

const std::string &Job::getType() const {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getType");
    return type;
}

void Job::setStatus(int currentjobornot, int number) {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setStatus");
    if(currentjobornot == 0){
        this->Status ="WAITING #" + std::to_string(number);
    }
    else if(currentjobornot == 1) {
        if (this->pageCount <= number) {
            this->Status = std::to_string(this->pageCount) + " pages done";
        } else {
            this->Status = std::to_string(number) + " pages done";
        }
    }
}

void Job::setTotalCO2(int Emission) {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setTotalCO2");
    this->TotalCO2 = Emission * this->pageCount;
}

void Job::setDevice(const std::string devicename){
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setDevice");
    this->Device = devicename;
}

std::string Job::getStatus() {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getStatus");
    return Status;
}

int Job::getTotalCO2() {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getTotalCO2");
    return TotalCO2;
}

std::string Job::getDevice() {
    REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getDevice");
    return Device;
}