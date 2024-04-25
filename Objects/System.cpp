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
    for (Device* device : devices) {
        delete device;
    }
    while (jobs.size() > 0) {
        delete jobs.front();
        jobs.pop();
    }
}

void System::addJob(Job* job){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling addJob");

    jobs.push(job);

}


void System::addDevice(Device* device){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling addDevice");
    unsigned int old = devices.size();
    devices.push_back(device);
    ENSURE(devices.size() == old+1, "addDevice postcondition failed");
}



void System::assigning_jobs(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling assigning_jobs");
    scheduler scheduler(devices, jobs);
    scheduler.schedule();
}

void System::execute_all_jobs(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling execute_all_jobs");
    for (Device* device : devices){
        while (device->getCurrentJob() != nullptr){
            execute_job();
        }
    }
}

void System::execute_job(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling execute_job");
    for (Device* device : devices){

        std::cout << "Printer " <<"\""<< device->getName() <<"\"" <<" finished job:" << std::endl;
        std::cout <<"Number: " << device->getCurrentJob()->getJobNumber() << std::endl;
        std::cout <<"Submitted by " << "\"" << device->getCurrentJob()->getUserName() << "\"" << std::endl;
        std::cout << device->getCurrentJob()->getPageCount() << " pages" << std::endl;

        if(!device->getJobs().empty()){
            Job* job = device->getJobs().front();
            device->getJobs().pop();
            device->set_current_job(job);
        }
        else{
            device->set_current_job(nullptr);
        }
    }

}



void System::output_info(std::string namefile){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling output_info");
    ofstream file(namefile);
    for (Device* device : devices){
        file << device->getName() << " (CO2: " << device->getEmission() <<"g/page):" << std::endl;
        file <<"    * Current:" << std::endl;

        if(device->getCurrentJob() != nullptr){
            file <<"        [#"<< device->getCurrentJob()->getJobNumber() <<"|" << device->getCurrentJob()->getUserName() <<"]" << std::endl;
        }
        file  <<"    * Queue:" << std::endl;

        std::queue<Job*> temp = device->getJobs();
        while (!temp.empty()){
            Job* job = temp.front();
            temp.pop();
            file <<"        [#"<< job->getJobNumber() <<"|" << job->getUserName() <<"]" << std::endl;
        }
    }
}

void System::clear_jobs(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear_jobs");
    while (!jobs.empty()){
        jobs.pop();
    }
    ENSURE(jobs.empty(), "clear_jobs postcondition failed");
}


void System::clear_devices(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear_devices");
    devices.clear();
    ENSURE(devices.empty(), "clear_jobs postcondition failed");
}

void System::clear(){
    REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear");
    clear_jobs();
    clear_devices();
    ENSURE(jobs.empty() && devices.empty(), "clear postcondition failed");
}






