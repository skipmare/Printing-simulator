// devices.h

#ifndef PSE_2023_2023_DEVICES_H
#define PSE_2023_2023_DEVICES_H

#include <iostream>
#include <queue>
#include <string>
#include "jobs.h" // Assuming you have a Job.h header file for Job class

class Device {
    Device* _initCheck;
    std::string name;
    int emission;
    int speed;
    Job* currentJob;
    std::queue<Job> jobs;

public:
    Device(); // You might want to define a constructor
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

#endif //PSE_2023_2023_DEVICES_H