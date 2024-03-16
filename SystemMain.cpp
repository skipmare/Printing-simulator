#include <iostream>
#include "Objects/System.h"
#include "SystemImporter.h"
using namespace std;



int main() {
    System system;
    SystemImporter::importSystem("test.xml", cerr, system);
    system.output_info("output.txt");
    system.execute_all_jobs();

}

