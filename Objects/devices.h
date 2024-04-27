// devices.h



#include <iostream>
#include <queue>
#include <string>
#include "jobs.h"

#ifndef DEVICES_H
#define DEVICES_H

class Device {
    Device* _initCheck;
protected:
    Job* currentJob;
    std::queue<Job*> jobs;
    std::vector<Job*> done_jobs;

    std::string name;
    int emission;
    int speed;
    std::string type;
    int workload = 0;
    int currentjob_workload = 0;
public:
    Device();

    bool properlyInitialized() const;
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getJobs");
     */
    std::queue<Job*>& getJobs();
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling setType");
     */
    void setType(const std::string xtype);
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getType");
     */
    std::string getType();
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
    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling give_job");
     */
    void give_job(Job* job);

    /*
     * REQUIRE(properlyInitialized(), "Device wasn't initialized when calling getWorkload");
     */
    int getWorkload() const;


    /*
     *REQUIRE(properlyInitialized(), "Device wasn't initialized when calling DoJob_Min");
     */
    void DoJob_Min();

    /*
     *REQUIRE(properlyInitialized(), "Device wasn't initialized when calling status_jobsqueue");
     */
    void status_jobsqueue();

    std::vector<Job*> getDoneJobs();

};

#endif