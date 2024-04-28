//
// Created by ADMIN on 23/04/2024.
//
#include "devices.h"
#include <queue>
#include <vector>
#include "jobs.h"
#include "./BWPrinter.h"
#include "./ColorPrinter.h"
#include "./Scanner.h"
#include <set>
#ifndef PSE_2023_2023_SCHEDULER_H
#define PSE_2023_2023_SCHEDULER_H


class scheduler {
    scheduler* _initCheck;

    std::queue<Job*> jobs;
    std::vector<Device*> devices;

    std::vector<Device*> Scanners;
    std::vector<Device*> Printers;
    std::vector<Device*> ColorPrinters;

    int bwEmmisionCap = 8;
    int colorEmmisionCap = 23;
    int scanEmmisionCap = 12;

    std::string& errorStream;

public:
    scheduler(std::vector<Device*> & devices, std::queue<Job*> & jobs, std::string & errorStream);
    bool properlyInitialized() const;

    /*
     * REQUIRE(properlyInitialized(), "Scheduler wasn't initialized when calling schedule");
     */
    void schedule();

    /*
     * REQUIRE(properlyInitialized(), "Scheduler wasn't initialized when calling LeastWorkloadDevice");
     */
    Device* LeastWorkloadDevice(const std::vector<Device *>& devices_to_use,  int cap);



};


#endif //PSE_2023_2023_SCHEDULER_H
