//
// Created by ADMIN on 15/03/2024.
//

#include "jobs.h"


    Job::Job() {
        _initCheck = this;
    }

    bool Job::properlyInitialized() const {
        return _initCheck == this;
    }

    int Job::getJobNumber() const {
        return jobNumber;
    }

    void Job::setJobNumber(int xjobNumber) {
        this->jobNumber = xjobNumber;}

    int Job::getPageCount() const {
        return pageCount;
    }

    void Job::setPageCount(int xpageCount) {
        this->pageCount = xpageCount;
    }

    const std::string &Job::getUserName() const {
        return userName;
    }

    void Job::setUserName(const std::string &xuserName) {
        this->userName = xuserName;
    }

    void Job::print(){
        std::cout << "Job number: " << jobNumber << '\n';
        std::cout << "Page count: " << pageCount << '\n';
        std::cout << "User name: " << userName << '\n';
    }
