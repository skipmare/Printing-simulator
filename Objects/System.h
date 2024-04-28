//
// Created by abdir on 13/03/2024.
//
#include "iostream"
#include "queue"
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
    std::string errstring = "";
    int exejob_CO2;


    ~System();

    bool properlyInitialized() const;



    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling addJob");
     * REQUIRE(job != nullptr, "Job is nullptr");
     * ENSURE(!jobs.empty(), "addJob postcondition failed");
     */
    void addJob(Job* job);


    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling addDevice");
     * REQUIRE(device != nullptr, "Device is nullptr");
     * ENSURE(!devices.empty(), "addDevice postcondition failed");
     */
    void addDevice(Device* device);


    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling assigning_jobs");
     * ENSURE(!jobs.empty(), "assigning_jobs postcondition failed");
     */
    void assigning_jobs();


    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling execute_all_jobs");
     * REQUIRE(minute >= 0, "minute can't be negative");
     */
    void Do_job_minutes(int minutes);


    /**
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling Calculate_exejob_CO2");
     * ENSURE(getExejob_CO2() >= 0, "Calculate_exejob_CO2 postcondition failed");
     */
    void Calculate_exejob_CO2();

    /*
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling getExejob_CO2");
     */
     int getExejob_CO2();

    /*
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear_jobs");
     * ENSURE(devices.empty(), "clear_jobs postcondition failed");
     */
    void clear_jobs();


    /*
    * REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear_devices");
    * ENSURE(jobs.empty() && devices.empty(), "clear postcondition failed");
    */

    void clear_devices();


    /*
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling clear");
     * ENSURE(jobs.empty() && devices.empty(), "clear postcondition failed");
     */
    void clear();


    /*
     * REQUIRE(properlyInitialized(), "System wasn't initialized when calling getErrorStream");
     */
    std::string & getErrorString() {
        return errstring;
    }


};


#endif //PSE_2023_2023_SYSTEM_H
