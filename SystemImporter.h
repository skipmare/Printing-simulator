//
// Created by abdir on 12/03/2024.
//

#include "tinyxml/tinyxml.h"
#include <iostream>
#include "System.h"


#ifndef PSE_2023_2023_XML_IMPORTER_H
#define PSE_2023_2023_XML_IMPORTER_H


enum SuccessEnum {ImportAborted, PartialImport, Success};



class SystemImporter {
public:
    /*
     * Import een systeem uit een XML bestand.
     * als er een fout optreedt, wordt de foutmelding naar errorStream geschreven.
     * return ImportAborted als het bestand niet geladen kan worden.
     * return PartialImport als het bestand wel geladen kan worden, maar niet alle informatie correct is.
     * return Success als het bestand geladen kan worden en alle informatie correct is.
     * \n REQUIRE(system.properlyInitialized(), "system wasn't initialized when passed to SystemImporter::importGame");
     */
    static SuccessEnum importSystem(const char* filename, std::ostream& errorStream, System& system);




};


#endif //PSE_2023_2023_XML_IMPORTER_H
