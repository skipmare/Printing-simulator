//
// Created by ADMIN on 15/03/2024.
//


#include <iostream>
#ifndef JOBS_H
#define JOBS_H

class Job {
    Job* _initCheck = this;
    int jobNumber;
    int pageCount;
    std::string userName;

public:
    bool properlyInitialized() const;

    int getJobNumber() const;

    void setJobNumber(int xjobNumber);

    int getPageCount() const;

    void setPageCount(int xpageCount);

    const std::string &getUserName() const;

    void setUserName(const std::string &xuserName);

    void print();

};

#endif // JOBS_H
