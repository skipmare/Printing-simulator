//
// Created by abdir on 01/04/2024.
//

#ifndef PSE_2023_2023_LOG_H
#define PSE_2023_2023_LOG_H
#include "iostream"
#include <iostream>
#include <fstream>
#include "System.h"


using namespace std;


class Log {
private:
    Log* _initCheck;
    System* _system;
public:
    Log(System* system);

    /*
     * REQUIRE(properlyInitialized(), "Log wasn't initialized when calling logStatusInfo");
     */
    void logStatusInfo( bool toFile);

    /*
     * REQUIRE(properlyInitialized(), "Log wasn't initialized when calling logJobInfo");
     */
    void logJobInfo(bool toFile);

    /*
     * REQUIRE(properlyInitialized(), "Log wasn't initialized when calling logerror");
     */
    void logerror();

    bool properlyInitialized() const;
};


#endif //PSE_2023_2023_LOG_H