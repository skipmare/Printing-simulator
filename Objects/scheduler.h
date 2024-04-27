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

public:
    scheduler(std::vector<Device*> & devices, std::queue<Job*> jobs);
    bool properlyInitialized() const;

    void schedule();

    Device* getLeastWorkloadScanner();

    Device* getLeastWorkloadBWPrinter();

    Device* getLeastWorkloadColorPrinter();



};


#endif //PSE_2023_2023_SCHEDULER_H
