#include <iostream>
#include "Objects/System.h"
#include "SystemImporter.h"
#include "./Objects/log.h"
using namespace std;



int main() {
    System system;
    Log logger = Log(&system);
    SystemImporter::importSystem("test.xml", cerr, system);
    system.Do_job_minutes(1);
    logger.logStatusInfo(true);
    logger.logJobInfo(true);
    logger.logerror();
}

