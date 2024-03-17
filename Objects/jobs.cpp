//
// Created by ADMIN on 15/03/2024.
//

#include "jobs.h"
#include "../DesignByContract.h"


Job::Job() {
    _initCheck = this;
    ENSURE(properlyInitialized(), "Job constructor did not end in an initialized state");
}


    bool Job::properlyInitialized() const {
        return _initCheck == this;
    }

    int Job::getJobNumber() const {
        REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getJobNumber");
        
        return jobNumber;
    }

    void Job::setJobNumber(int xjobNumber) {
        REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setJobNumber");

        this->jobNumber = xjobNumber;

}

    int Job::getPageCount() const {
        REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getPageCount");

        return pageCount;
    }

    void Job::setPageCount(int xpageCount) {
        REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setPageCount");

        this->pageCount = xpageCount;
    }

    const std::string &Job::getUserName() const {
        REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getUserName");

        return userName;
    }

    void Job::setUserName(const std::string &xuserName) {
        REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setUserName");

        this->userName = xuserName;
    }

    void Job::print(){
        REQUIRE(properlyInitialized(), "Job wasn't initialized when calling print");

        std::cout << "Job number: " << jobNumber << '\n';
        std::cout << "Page count: " << pageCount << '\n';
        std::cout << "User name: " << userName << '\n';
    }
