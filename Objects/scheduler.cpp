//
// Created by ADMIN on 23/04/2024.
//

#include "scheduler.h"
#include "../DesignByContract.h"

scheduler::scheduler(std::vector<Device *> &devices, std::queue<Job *> &jobs) {
    _initCheck = this;
    this->devices = devices;
    this->jobs = jobs;

    for (Device* device : devices) {
        if (device->getType() == "scan") {
            this->Scanners.push_back(device);
        } else if (device->getType() == "bw") {
            this->Printers.push_back(device);
        } else if (device->getType() == "color") { // Corrected here
            this->ColorPrinters.push_back(device);
        }
    }
}

bool scheduler::properlyInitialized() const {
    return _initCheck == this;
}

void scheduler::schedule() {
    REQUIRE(properlyInitialized(), "scheduler wasn't initialized when calling schedule");
    while (!jobs.empty()) {
        Job* job = jobs.front();
        jobs.pop();
        if (job->getType() == "scan") {
            Device* leastLoadedScanner = this->getLeastWorkloadScanner();
            if (leastLoadedScanner != nullptr) {
                leastLoadedScanner->give_job(job);
            }
        } else if (job->getType() == "bw") {
            Device* leastLoadedBWPrinter = this->getLeastWorkloadBWPrinter();
            if (leastLoadedBWPrinter != nullptr) {
                leastLoadedBWPrinter->give_job(job);
            }
        } else if (job->getType() == "color") {
            Device* leastLoadedColorPrinter = this->getLeastWorkloadColorPrinter();
            if (leastLoadedColorPrinter != nullptr) {
                leastLoadedColorPrinter->give_job(job);
            }
        }
    }
    ENSURE(jobs.empty(), "schedule postcondition failed");
}


Device *scheduler::getLeastWorkloadScanner() {
    REQUIRE(properlyInitialized(), "scheduler wasn't initialized when calling getLeastWorkloadScanner");
    Device* leastLoadedScanner = nullptr;
    for (Device* scanner : Scanners) {
        if (leastLoadedScanner == nullptr || scanner->getWorkload() < leastLoadedScanner->getWorkload()) {
            leastLoadedScanner = scanner;
        }
    }
    return leastLoadedScanner;
}


Device *scheduler::getLeastWorkloadBWPrinter() {
    REQUIRE(properlyInitialized(), "scheduler wasn't initialized when calling getLeastWorkloadBWPrinter");
    Device* leastLoadedBWPrinter = nullptr;
    for (Device* bwPrinter : Printers) {
        if (leastLoadedBWPrinter == nullptr || bwPrinter->getWorkload() < leastLoadedBWPrinter->getWorkload()) {
            leastLoadedBWPrinter = bwPrinter;
        }
    }
    return leastLoadedBWPrinter;
}

Device *scheduler::getLeastWorkloadColorPrinter() {
    REQUIRE(properlyInitialized(), "scheduler wasn't initialized when calling getLeastWorkloadColorPrinter");
    Device* leastLoadedColorPrinter = nullptr;
    for (Device* colorPrinter : ColorPrinters) {
        if (leastLoadedColorPrinter == nullptr || colorPrinter->getWorkload() < leastLoadedColorPrinter->getWorkload()) {
            leastLoadedColorPrinter = colorPrinter;
        }
    }
    return leastLoadedColorPrinter;
}