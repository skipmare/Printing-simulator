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
    std::queue<Job> jobs;

public:
    Device();
    bool properlyInitialized() const;

    std::queue<Job>& getJobs();
    Job* getCurrentJob();
    void set_current_job(Job* job);
    const std::string &getName() const;
    int getEmission() const;
    int getSpeed() const;
    void setName(const std::string &xname);
    void setEmission(int xemission);
    void setSpeed(int xspeed);
    void print();


};

#endif