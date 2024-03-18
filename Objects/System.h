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
    queue<Job*> jobs;
    vector<Device*> devices;
    int Add_Job_Queue_index = 0;

    bool properlyInitialized() const;

    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling addJob");
     * ENSURE(jobs.size() == old + 1, "addJob postcondition failed");
     */
    void addJob(Job* job);

    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling addDevice");
     */
    queue<Job*> getJobs();

    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling getJobs");
     * ENSURE(jobs.size() == old(jobs.size()), "getJobs postcondition failed");
     */
    void addDevice(Device* device);

    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling addDevice");
     * ENSURE(devices.size() == old+1, "addDevice postcondition failed");
     */
    vector<Device*> getDevices();

    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling getDevices");
     */
    void assigning_jobs();

    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling assigning_jobs");
     */
    void execute_all_jobs();

    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling execute_all_jobs");
     */
    void execute_job();
    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling execute_job");
     */
    void output_info(std::string namefile);


    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling output_info");
     * ENSURE(jobs.empty(), "output_info postcondition failed");
     */
    void clear_jobs();
    /*
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear_jobs");
     * ENSURE(devices.empty(), "clear_jobs postcondition failed");
     */
    void clear_devices();
    /*
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear_devices");
     * ENSURE(jobs.empty() && devices.empty(), "clear postcondition failed");
     */
    void clear();
};


#endif //PSE_2023_2023_SYSTEM_H
