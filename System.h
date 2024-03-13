//
// Created by abdir on 13/03/2024.
//
#include "iostream"
#include "queue"
#include "stack"
#include "vector"

using namespace std;

#ifndef PSE_2023_2023_SYSTEM_H
#define PSE_2023_2023_SYSTEM_H

class Job {
private:
    int jobNumber;
    int pageCount;
    string userName;

public:

    int getJobNumber() const {
        return jobNumber;
    }

    void setJobNumber(int jobNumber) {
        Job::jobNumber = jobNumber;}

    int getPageCount() const {
        return pageCount;
    }

    void setPageCount(int pageCount) {
        Job::pageCount = pageCount;
    }

    const string &getUserName() const {
        return userName;
    }

    void setUserName(const string &userName) {
        Job::userName = userName;
    }

    void print(){
        cout << "Job number: " << jobNumber << '\n';
        cout << "Page count: " << pageCount << '\n';
        cout << "User name: " << userName << '\n';
    }

};

class Device {
private:
    std::string name;
    int emission;
    int speed;
    Job* currentJob;
    queue<Job> jobs;

public:
    const std::string &getName() const {
        return name;
    }

    int getEmission() const {
        return emission;
    }

    int getSpeed() const {
        return speed;
    }

    void setName(const std::string &name) {
        Device::name = name;
    }

    void setEmission(int emission) {
        Device::emission = emission;
    }

    void setSpeed(int speed) {
        Device::speed = speed;
    }

    void print(){
        cout << "Name: " << name << '\n';
        cout << "Emission: " << emission << '\n';
        cout << "Speed: " << speed << '\n';
    }
};

class System {
public:
    queue<Job> jobs;
    stack<Device> devices;

    void addJob(Job job){
        jobs.push(job);
    }

    Job getJob(){
        Job job = jobs.front();
        jobs.pop();
        return job;
    }

    void addDevice(Device device){
        devices.push(device);
    }

    Device getDevice() {
        Device device = devices.top();
        devices.pop();
        return device;

    }


    void print(){
        cout << "Jobs: " << '\n';
        while (!jobs.empty()){
            jobs.front().print();
            jobs.pop();
        }
        cout << "Devices: " << '\n';
        while (!devices.empty()){
            devices.top().print();
            devices.pop();
        }
    }



};


#endif //PSE_2023_2023_SYSTEM_H
