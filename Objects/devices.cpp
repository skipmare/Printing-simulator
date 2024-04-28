// devices.cpp

#include "devices.h"
#include <iostream>
#include <gtest/gtest.h>
#include "../DesignByContract.h"

Device::Device() : _initCheck(this), currentJob(nullptr) {}

bool Device::properlyInitialized() const {
    return _initCheck == this;
}


Job* Device::getCurrentJob() {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getCurrentJob");
    return currentJob;
}
void Device::setType(const std::string xtype) {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling setType");
    this->type = xtype;
}
std::string Device::getType() {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getType");
    return type;
}

void Device::set_current_job(Job* job) {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling set_current_job");
    currentJob = job;
}

const std::string &Device::getName() const {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getName");
    return name;
}

int Device::getEmission() const {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getEmission");
    return emission;
}

int Device::getSpeed() const {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getSpeed");
    return speed;
}

void Device::setName(const std::string &xname) {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling setName");
    name = xname;
}

void Device::setEmission(int xemission) {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling setEmission");
    emission = xemission;
}

void Device::setSpeed(int xspeed) {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling setSpeed");
    speed = xspeed;
}

void Device::print() {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling print");
    std::cout << "Name: " << name << '\n';
    std::cout << "Emission: " << emission << '\n';
    std::cout << "Speed: " << speed << '\n';
}

void Device::give_job(Job* job) {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling addJob");
    if (currentJob == nullptr) {
        currentJob = job;
        currentjob_workload = job->getPageCount();
        currentJob->setTotalCO2(this->emission);
        currentJob->setDevice(this->name);
    } else {
        jobs.push(job);
    }
    workload += job->getPageCount();
}

int Device::getWorkload() const {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getWorkload");
    return workload;
}


void Device::DoJob_Min() {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling finishJob");
    if (currentJob != nullptr) {
        currentjob_workload -= speed;
        currentJob->setStatus(1,currentJob->getPageCount() - currentjob_workload);
        if (currentjob_workload <= 0) {
            done_jobs.push_back(currentJob);
            if (!jobs.empty()) {
                currentJob= jobs.front();
                jobs.pop();
                currentjob_workload += currentJob->getPageCount();
                currentJob->setStatus(1,currentJob->getPageCount() - currentjob_workload);
            }else{
                currentJob = nullptr;
                currentjob_workload = 0;
            }
        }
        this->status_jobsqueue();
    }
}

void Device::status_jobsqueue(){
/* to set like WAITING #1, WAITING #2, WAITING #3, WAITING #4, WAITING #5, WAITING #6, WAITING #7, WAITING #8, WAITING #9, WAITING #10
 */
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling status_jobsqueue");
    int pos = 1;
    std::queue<Job*> temp = this->jobs;
    while (!jobs.empty()) {
        Job* job = jobs.front();
        jobs.pop();
        job->setStatus(0,pos);
        job->setTotalCO2(this->emission);
        job->setDevice(this->name);
        temp.push(job);
        pos++;
    }
}

std::vector<Job*> Device::getDoneJobs() {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getDoneJobs");
    return done_jobs;
}
