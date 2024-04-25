//
// Created by ADMIN on 24/04/2024.
//

#include "Scanner.h"

bool Scanner::properlyInitialized() const {
    return _initCheck == this;
}

Scanner::Scanner() {
    _initCheck = this;
    this->emission_cap = 12;
    this->type = "scan=";
}