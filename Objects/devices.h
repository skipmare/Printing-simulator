// devices.h



#include <iostream>
#include <queue>
#include <string>
#include "jobs.h"

#ifndef DEVICES_H
#define DEVICES_H

class Device {
    Device* _initCheck;
    std::string name;
    int emission;
    int speed;
    Job* currentJob;
    std::queue<Job*> jobs;

public:
    Device();

    bool properlyInitialized() const;
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getJobs");
     */
    std::queue<Job*>& getJobs();
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getCurrentJob");
     */
    Job* getCurrentJob();
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling set_current_job");
     */
    void set_current_job(Job* job);
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getName");
     */
    const std::string &getName() const;
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getEmission");
     */
    int getEmission() const;
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getSpeed");
     */
    int getSpeed() const;
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling setName");
     */
    void setName(const std::string &xname);
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling setEmission");
     */
    void setEmission(int xemission);
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling setSpeed");
     */
    void setSpeed(int xspeed);
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling print");
     */
    void print();


};

#endif