//
// Created by abdir on 01/04/2024.
//

#ifndef PSE_2023_2023_LOG_H
#define PSE_2023_2023_LOG_H
#include "iostream"

#include <iostream>
#include <fstream>

class Logger {
public:
    void logToConsole(const std::string& message);

    void logToFile(const std::string& filename, const std::string& message);
};


#endif //PSE_2023_2023_LOG_H
