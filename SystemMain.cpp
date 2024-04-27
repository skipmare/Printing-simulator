#include <iostream>
#include "Objects/System.h"
#include "SystemImporter.h"
#include "./Objects/log.h"
using namespace std;



int main() {
    System system;
    Log logger = Log(&system);
    SystemImporter::importSystem("test.xml", cerr, system);
    system.output_info("output.txt");
    system.Do_job_minutes(10);
    logger.logStatusInfo(true);
    logger.logJobInfo(true);
}

