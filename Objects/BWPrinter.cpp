//
// Created by ADMIN on 24/04/2024.
//

#include "BWPrinter.h"

BWPrinter::BWPrinter() {
    _initCheck = this;
    this->emission_cap = 8;
    this->type = "bw";
}

bool BWPrinter::properlyInitialized() const {
    return _initCheck == this;
}