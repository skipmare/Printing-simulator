//
// Created by ADMIN on 23/04/2024.
//
#include "devices.h"
#ifndef PSE_2023_2023_PRINTER_H
#define PSE_2023_2023_PRINTER_H


class ColorPrinter : public Device {
    ColorPrinter* _initCheck;
    int emission_cap;
    std::string type;

public:
    ColorPrinter();

    bool properlyInitialized() const;
};


#endif //PSE_2023_2023_PRINTER_H
