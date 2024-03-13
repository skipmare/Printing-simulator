//
// Created by abdir on 13/03/2024.
//
#include "iostream"
#include "queue"
#include "stack"
#include "vector"
#include "fstream"

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
    queue<Job>& getJobs() {
        return jobs;
    }
    Job* getCurrentJob() const {
        return currentJob;
    }


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
    vector<Device> devices;

    void addJob(Job job){
        jobs.push(job);
    }

    void addDevice(Device device){
        devices.push_back(device);
    }



    void output_info(){
        ofstream file("output.txt");
        for (Device& device : devices){
            file <<device.getName()<<" (CO2: " << device.getEmission() <<"g/page):" <<std::endl;
            file <<"    * Current:" <<std::endl;
            file <<"        [#"<<device.getCurrentJob()->getJobNumber()<<"|" << device.getCurrentJob()->getUserName() <<"]" << std::endl;
            file  <<"    * Queue:" <<std::endl;
            while (!device.getJobs().empty()){

                Job job = device.getJobs().front();
                device.getJobs().pop();
                device.getJobs().push(job);

                file <<"        [#"<<job.getJobNumber()<<"|" << job.getUserName() <<"]"<< std::endl;
            }

        }
    }




};


#endif //PSE_2023_2023_SYSTEM_H
