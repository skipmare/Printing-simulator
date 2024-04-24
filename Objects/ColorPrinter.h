//
// Created by ADMIN on 23/04/2024.
//
#include "devices.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#ifndef PSE_2023_2023_PRINTER_H
#define PSE_2023_2023_PRINTER_H


class ColorPrinter : public Device {
    ColorPrinter* _initCheck;
    int emission_cap = 23;
    std::string type = "color";

public:
    ColorPrinter();

    bool properlyInitialized() const;
};


#endif //PSE_2023_2023_PRINTER_H

#pragma clang diagnostic pop