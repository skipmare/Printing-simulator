//
// Created by abdir on 13/03/2024.
//

#include "System.h"

#include "iostream"
#include "queue"
#include "stack"
#include "vector"
#include "fstream"

using namespace std;


#include "jobs.h"
#include "devices.h"

    bool System::properlyInitialized() const {
        return _initCheck == this;
    }

    void System::addJob(Job job){
        jobs.push(job);
    }

    void System::print_jobs(){
        while (!jobs.empty()){
            Job job = jobs.front();
            jobs.pop();
            job.print();
        }
    }

    void System::addDevice(Device device){
        devices.push_back(device);
    }

    void System::assigning_jobs(){
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

    void System::output_info(){
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

    void System::clear_jobs(){
        while (!jobs.empty()){
            jobs.pop();
        }
    }


    void System::clear_devices(){
        devices.clear();
    }

    void System::clear(){
        clear_jobs();
        clear_devices();
    }

    vector<Device> System::getDevices() {
        return devices;
    }
