//
// Created by abdir on 01/04/2024.
//

#include "log.h"

void Logger::logToConsole(const std::string& message) {
    std::cout << message << std::endl;
}

void Logger::logToFile(const std::string& filename, const std::string& message) {
    std::ofstream file(filename);
    file << message << std::endl;
    file.close();
}

