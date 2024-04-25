//
// Created by ADMIN on 24/04/2024.
//
#include <iostream>
#include"devices.h"

#ifndef PSE_2023_2023_BWPRINTER_H
#define PSE_2023_2023_BWPRINTER_H


class BWPrinter : public Device {
    BWPrinter* _initCheck;
    int emission_cap;
    std::string type;

public:
    bool properlyInitialized() const;

    BWPrinter();
};


#endif //PSE_2023_2023_BWPRINTER_H
