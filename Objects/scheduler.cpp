//
// Created by ADMIN on 23/04/2024.
//

#include "scheduler.h"
#include "../DesignByContract.h"

scheduler::scheduler(std::vector<Device *> &devices, std::queue<Job *> &jobs, std::string & errorStream)
        : _initCheck(this), jobs(jobs), devices(devices), errorStream(errorStream) {
    _initCheck = this;


    for (Device* device : devices) {
        if (device->getType() == "scan") {
            this->Scanners.push_back(device);
        } else if (device->getType() == "bw") {
            this->Printers.push_back(device);
        } else if (device->getType() == "color") {
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
        Device* device;
        std::string type = job->getType();
        std::vector<Device*> devices_to_use;
        int cap = 0;
        if (type == "scan") {
            devices_to_use = this->Scanners;
            cap = this->scanEmmisionCap;
        } else if (type == "bw") {
            devices_to_use = this->Printers;
            cap = this->bwEmmisionCap;
        } else if (type == "color") {
            devices_to_use = this->ColorPrinters;
            cap = this->colorEmmisionCap;
        }
        if (devices_to_use.empty()) {
            errorStream += "No device available for job: " + std::to_string(job->getJobNumber())  + '\n';
            continue;
        }
        if (devices_to_use.size() > 1) {
            device = LeastWorkloadDevice(devices_to_use, cap);
        } else {
            device = devices_to_use[0];
        }
        if (device == nullptr || device->getEmission() > cap){
            errorStream += "Devices exceed the emmision cap for job: " + std::to_string(job->getJobNumber())  + '\n';
            continue;
        }
        device->give_job(job);
    }
}


Device *scheduler::LeastWorkloadDevice(const std::vector<Device *>& devices_to_use, int cap) {
    REQUIRE(properlyInitialized(), "scheduler wasn't initialized when calling getLeastWorkloadScanner");
    Device* leastLoadedDevice = nullptr;
    for (Device* device : devices_to_use) {
        if (device->getEmission() > cap) {
            continue;
        }
        if (leastLoadedDevice == nullptr || device->getWorkload() * device->getEmission() < leastLoadedDevice->getWorkload() * leastLoadedDevice->getEmission()) {
            leastLoadedDevice = device;
        }
    }

    return leastLoadedDevice;
}

