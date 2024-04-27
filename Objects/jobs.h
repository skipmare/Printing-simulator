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

    std::string Device;
    int TotalCO2;
    std::string Status;
    std::string type;
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

    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setType");
     */
    void setType(const std::string &xType);

    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling getType");
     */
    const std::string &getType() const;

    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setStatus");
     */
    void setStatus(int currentjobornot, int number);

    /*
     * REQUIRE(properlyInitialized(), "Job wasn't initialized when calling setTotalCO2");
     */
    void setTotalCO2(int xTotalCO2);

    void setDevice(const std::string Device);

    std::string getDevice();

    int getTotalCO2();

    std::string getStatus();
};

#endif // JOBS_H