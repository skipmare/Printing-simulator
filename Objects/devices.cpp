// devices.cpp

#include "devices.h"
#include <iostream>
#include <gtest/gtest.h>
#include "../DesignByContract.h"

Device::Device() : _initCheck(this), currentJob(nullptr) {}

bool Device::properlyInitialized() const {
    return _initCheck == this;
}

std::queue<Job*>& Device::getJobs() {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getJobs");
    return jobs;
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
    } else {
        jobs.push(job);
    }
    workload = job->getPageCount();
}

int Device::getWorkload() const {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getWorkload");
    return workload;
}


void Device::finishJob() {
    REQUIRE(properlyInitialized(), "Device wasn't initialized when calling finishJob");
    if (currentJob != nullptr) {
        int workload_current_job = currentJob->getPageCount();
        workload -= workload_current_job;
        currentJob = nullptr;
        if (!jobs.empty()) {
            currentJob = jobs.front();
            jobs.pop();
        }
    }
}
