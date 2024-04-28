//
// Created by ADMIN on 23/04/2024.
//

#include "ColorPrinter.h"

bool ColorPrinter::properlyInitialized() const {
    return _initCheck == this;
}
ColorPrinter::ColorPrinter() {
    _initCheck = this;
    this->type = "color";
}
