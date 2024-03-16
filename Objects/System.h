//
// Created by abdir on 13/03/2024.
//
#include "iostream"
#include "queue"
#include "stack"
#include "vector"
#include "fstream"

using namespace std;

#ifndef SYSTEM_H
#define SYSTEM_H
#include "jobs.h"
#include "devices.h"


class System {
public:
    System* _initCheck = this;
    queue<Job> jobs;
    vector<Device> devices;
    int Add_Job_Queue_index = 0;

    bool properlyInitialized() const;
    void addJob(Job job);

    void print_jobs();

    void addDevice(Device device);

    vector<Device> getDevices();

    void assigning_jobs();

    void output_info();

    void clear_jobs();

    void clear_devices();

    void clear();


};


#endif //PSE_2023_2023_SYSTEM_H
