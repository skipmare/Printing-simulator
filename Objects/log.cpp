//
// Created by abdir on 01/04/2024.
//

#include "log.h"


Log::Log(System* system) : _system(system){}

// Nog functies toevoegen...

bool Log::properlyInitialized() const {
    return _initCheck == this;
}

void Log::logStatusInfo(bool toFile) {
    std::string status;
    status = "# === [System Status] === #\n";
    status += "\n";
    status += "--== Devices ==--\n";
    status += "\n";
    for (Device *device: _system->devices) {
        status += "* " + device->getName() + ":\n";
        status += "* CO2: " + std::to_string(device->getEmission()) + "g/page" + "\n";
        status += "* " + std::to_string(device->getSpeed()) + " pages / minute\n";
        if(device->getType() == "bw"){
            status += "* Black-and-white printer\n";
        } else if(device->getType() == "color"){
            status += "* Color printer\n";
        } else if(device->getType() == "scan"){
            status += "* Scanner\n";
        }
        status += "\n";
    }
    status += "--== Jobs ==--\n";
    status += "\n";
    std::queue<Job*> temp = _system->jobs;
    while (!temp.empty()) {
        Job* job = temp.front();
        status += "[Job #" + std::to_string(job->getJobNumber()) + "]\n";
        status += "* Owner: " + job->getUserName() + "\n";
        status += "* Device: " + job->getDevice() + "\n";
        status += "* Status: " + job->getStatus() + "\n";
        status += "* Total Pages: " + std::to_string(job->getPageCount()) + "\n";
        status += "* Total CO2: " + std::to_string(job->getTotalCO2()) + "g CO2\n";
        status += "\n";
        temp.pop();
    }
    if (toFile) {
        std::ofstream file;
        file.open("status.txt");
        file << status;
        file.close();
    } else {
        std::cout << status;
    }

}

void Log::logJobInfo(bool toFile) {
    std::string JobInfos;
    for (Device *device: _system->devices) {
        for(Job* job : device->getDoneJobs()){
            JobInfos += "Printer \"" + device->getName() + "\" " + "finished ";
            if(device->getType() == "bw"){
                JobInfos += "black-and-white printing job:\n";
            } else if(device->getType() == "color"){
                JobInfos += "color-printing job: \n";
            } else if(device->getType() == "scan"){
                JobInfos += "scanning job: \n";
            }
            JobInfos += "Number: " + std::to_string(job->getJobNumber()) + "\n";
            JobInfos += "Submitted by \"" + job->getUserName() + "\"\n";
            JobInfos += std::to_string(job->getPageCount()) + " pages \n";
            JobInfos += "\n";
            JobInfos += "CO2-counter: " + std::to_string(_system->getExejob_CO2()) + "g CO2\n";

        }
    }
    if (toFile) {
        std::ofstream file;
        file.open("jobinfos.txt");
        file << JobInfos;
        file.close();
    } else {
        std::cout << JobInfos;
    }

}



