//
// Created by ADMIN on 15/03/2024.
//


#include <iostream>
#ifndef JOBS_H
#define JOBS_H

class Job {
    /*
     * ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
    */
    Job* _initCheck = this;
    int jobNumber;
    int pageCount;
    std::string userName;

public:
    Job();

    bool properlyInitialized() const;
    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getJobNumber");
    */
    int getJobNumber() const;

    /*\
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setJobNumber");
     */
    void setJobNumber(int xjobNumber);

    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getPageCount");
     */
    int getPageCount() const;
    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setPageCount");
     */
    void setPageCount(int xpageCount);
    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getUserName");
     */
    const std::string &getUserName() const;

    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setUserName");
     */
    void setUserName(const std::string &xuserName);
    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling print");
     */
    void print();

};

#endif // JOBS_H
