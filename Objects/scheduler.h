//
// Created by ADMIN on 23/04/2024.
//
#include "devices.h"
#include <queue>
#include <vector>
#include "jobs.h"
#ifndef PSE_2023_2023_SCHEDULER_H
#define PSE_2023_2023_SCHEDULER_H


class scheduler {
    scheduler* _initCheck;

    std::queue<Job*> jobs;
    std::vector<Device*> devices;
    int Add_Job_Queue_index = 0;

public:
    scheduler(std::vector<Device*> & devices, std::queue<Job*> & jobs);
    bool properlyInitialized() const;

    void schedule();
};


#endif //PSE_2023_2023_SCHEDULER_H
