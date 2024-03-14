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
      this->jobNumber = jobNumber;}

    int getPageCount() const {
        return pageCount;
    }

    void setPageCount(int pageCount) {
        this->pageCount = pageCount;
    }

    const string &getUserName() const {
        return userName;
    }

    void setUserName(const string &userName) {
        this->userName = userName;
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
    Job* currentJob = nullptr;
    queue<Job> jobs;

public:
    queue<Job>& getJobs() {
        return jobs;
    }
    Job* getCurrentJob() {
        return currentJob;
    }
    void set_current_job(Job* job){
        currentJob = job;
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
        this->name = name;
    }

    void setEmission(int emission) {
        this->emission = emission;
    }

    void setSpeed(int speed) {
        this->speed = speed;
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
    int Add_Job_Queue_index = 0;

    void addJob(Job job){
        jobs.push(job);
    }
    void print_jobs(){
        while (!jobs.empty()){
            Job job = jobs.front();
            jobs.pop();
            job.print();
        }
    }

    void addDevice(Device device){
        devices.push_back(device);
    }

    void assigning_jobs(){
        for (Device& device : devices){
            if(device.getCurrentJob() == nullptr){
                if (!jobs.empty()){
                    // You can't store the address of a local variable; you need to dynamically allocate the Job object
                    Job* job = new Job(jobs.front());
                    jobs.pop();
                    device.set_current_job(job);
                }
            }
        }

        int last_index = devices.size() - 1;

        while(!jobs.empty()){

            Job* job = new Job(jobs.front());
            jobs.pop();
            devices[Add_Job_Queue_index].getJobs().push(*job);
            Add_Job_Queue_index++;

            if (Add_Job_Queue_index > last_index){
                Add_Job_Queue_index = 0;
            }
        }
    }

    void output_info(){
        ofstream file("output.txt");
        for (Device& device : devices){
            file << device.getName() << " (CO2: " << device.getEmission() <<"g/page):" << std::endl;
            file <<"    * Current:" << std::endl;
            // Check if getCurrentJob() returns a nullptr before dereferencing it.
            if(device.getCurrentJob() != nullptr){
                file <<"        [#"<< device.getCurrentJob()->getJobNumber() <<"|" << device.getCurrentJob()->getUserName() <<"]" << std::endl;
            }
            file  <<"    * Queue:" << std::endl;

            queue<Job> temp = device.getJobs();
            while (!temp.empty()){
                Job& job = temp.front();
                temp.pop();
                file <<"        [#"<< job.getJobNumber() <<"|" << job.getUserName() <<"]" << std::endl;
            }
        }
    }






};


#endif //PSE_2023_2023_SYSTEM_H
