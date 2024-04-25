//
// Created by ADMIN on 23/04/2024.
//

#include "scheduler.h"
#include "../DesignByContract.h"

scheduler::scheduler(std::vector<Device *> &devices, std::queue<Job *> &jobs) {
    _initCheck = this;
    this->devices = devices;
    this->jobs = jobs;
}

bool scheduler::properlyInitialized() const {
    return _initCheck == this;
}

void scheduler::schedule() {
    REQUIRE(properlyInitialized(), "scheduler wasn't initialized when calling schedule");

}
