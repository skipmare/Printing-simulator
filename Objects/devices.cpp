// devices.cpp

#include "devices.h"
#include <iostream>
#include <gtest/gtest.h>

Device::Device() : _initCheck(this), currentJob(nullptr) {}

bool Device::properlyInitialized() const {
    return _initCheck == this;
}

std::queue<Job>& Device::getJobs() {
    return jobs;
}

Job* Device::getCurrentJob() {
    return currentJob;
}

void Device::set_current_job(Job* job) {
    currentJob = job;
}

const std::string &Device::getName() const {
    return name;
}

int Device::getEmission() const {
    return emission;
}

int Device::getSpeed() const {
    return speed;
}

void Device::setName(const std::string &xname) {
    name = xname;
}

void Device::setEmission(int xemission) {
    emission = xemission;
}

void Device::setSpeed(int xspeed) {
    speed = xspeed;
}

void Device::print() {
    std::cout << "Name: " << name << '\n';
    std::cout << "Emission: " << emission << '\n';
    std::cout << "Speed: " << speed << '\n';
}