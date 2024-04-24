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
    for (Device* device : devices){
        if(device->getCurrentJob() == nullptr){
            if (!jobs.empty()){
                Job* job = jobs.front();
                jobs.pop();
                device->set_current_job(job);
            }
        }
    }

    int last_index = devices.size() - 1;

    while(!jobs.empty()){

        Job* job = jobs.front();
        jobs.pop();
        devices[Add_Job_Queue_index]->getJobs().push(job);
        Add_Job_Queue_index++;

        if (Add_Job_Queue_index > last_index){
            Add_Job_Queue_index = 0;
        }
    }

}
