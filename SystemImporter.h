//
// Created by abdir on 12/03/2024.
//

#include "tinyxml/tinyxml.h"
#include <iostream>

#ifndef PSE_2023_2023_XML_IMPORTER_H
#define PSE_2023_2023_XML_IMPORTER_H


enum SuccessEnum {ImportAborted, PartialImport, Success};



class SystemImporter {
public:
    static SuccessEnum importSystem(const char* filename, std::ostream& errorStream);




};


#endif //PSE_2023_2023_XML_IMPORTER_H
