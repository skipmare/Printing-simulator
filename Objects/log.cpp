//
// Created by abdir on 01/04/2024.
//

#include "log.h"

Log::Log(System* system) : _system(system){}

// Nog functies toevoegen...

bool Log::properlyInitialized() const {
    return _initCheck == this;
}

void Log::logStatusInfo( bool toFile) {

}

void Log::logJobInfo(bool toFile) {

}



