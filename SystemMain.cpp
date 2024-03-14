#include <iostream>
#include "System.h"
#include "SystemImporter.h"
using namespace std;



int main() {
    System system;
    SystemImporter::importSystem("test.xml", cerr, system);


}

