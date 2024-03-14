#include <iostream>
#include "tinyxml/tinyxml.h"

#include "string"
#include "vector"
#include <typeinfo>
#include "System.h"
#include "SystemImporter.h"
using namespace std;



int main() {
    System system;
    std::ifstream file("test.xml");

    SystemImporter::importSystem("test.xml", cerr, system);

}

