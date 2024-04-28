//
// Created by ADMIN on 24/04/2024.
//
#include<iostream>
#include "devices.h"
#ifndef PSE_2023_2023_SCANNER_H
#define PSE_2023_2023_SCANNER_H

class Scanner : public Device{
    Scanner* _initCheck;
    std::string type;

public:
    bool properlyInitialized() const;

    Scanner();
};


#endif //PSE_2023_2023_SCANNER_H
