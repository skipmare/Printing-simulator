//
// Created by abdir on 13/03/2024.
//

#include "System.h"

#include "iostream"
#include "queue"
#include "stack"
#include "vector"
#include "fstream"
#include "../DesignByContract.h"

using namespace std;


#include "jobs.h"
#include "devices.h"
#include "./scheduler.h"

bool System::properlyInitialized() const {
    return _initCheck == this;
}

System::~System() {
    this->clear();
}

void System::addJob(Job* job){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling addJob");
    REQUIRE(job != nullptr, "Job is nullptr");


    jobs.push(job);
    ENSURE(!jobs.empty(), "addJob postcondition failed");
}


void System::addDevice(Device* device){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling addDevice");
    REQUIRE(device != nullptr, "Device is nullptr");

    devices.push_back(device);

    ENSURE(!devices.empty(), "addDevice postcondition failed");
}



void System::assigning_jobs(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling assigning_jobs");
    REQUIRE(!jobs.empty(), "No jobs to assign");

    scheduler scheduler(devices, jobs, errstring);
    scheduler.schedule();

    ENSURE(!jobs.empty(), "assigning_jobs postcondition failed");
}

void System::Calculate_exejob_CO2(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling Calculate_exejob_CO2");

    int total = 0;
    for (Device* device : devices){
        for (Job* job : device->getDoneJobs()){
            total += job->getTotalCO2();
        }
    }
    exejob_CO2 = total;

    ENSURE(getExejob_CO2() >= 0, "Calculate_exejob_CO2 postcondition failed");
}

void System::Do_job_minutes(int minutes){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling Do_job_minutes");
    REQUIRE(minutes >= 0, "Minutes can't be negative");
    for (int i = 0; i < minutes; i++){
        for(Device* device : devices){
        device->DoJob_Min();
        }
    }
    this->Calculate_exejob_CO2();

}


void System::clear_jobs(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear_jobs");
    while (!jobs.empty()){
        delete jobs.front();
        jobs.pop();
    }
    ENSURE(jobs.empty(), "clear_jobs postcondition failed");
}


void System::clear_devices(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear_devices");
    for (Device* device : devices){
        delete device;
    }
    devices.clear();
    ENSURE(devices.empty(), "clear_jobs postcondition failed");
}

void System::clear(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear");
    clear_jobs();
    clear_devices();
    ENSURE(jobs.empty() && devices.empty(), "clear postcondition failed");
}

int System::getExejob_CO2() {
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling getExejob_CO2");
    return exejob_CO2;
}







