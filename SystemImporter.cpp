#include "SystemImporter.h"
#include "DesignByContract.h"
#include "tinyxml/tinyxml.h"
#include "set"
#include "./Objects/BWPrinter.h"
#include "./Objects/ColorPrinter.h"
#include "./Objects/Scanner.h"
using namespace std;



SuccessEnum SystemImporter::importSystem(const char *filename, std::ostream &errorStream, System& system) {
    bool isConsistent = true;
    SuccessEnum endresult = Success;
    TiXmlDocument doc;
    set<int> jobNumbers;


    REQUIRE(system.properlyInitialized(), "system wasn't initialized when passed to SystemImporter::importGame");

    if (!doc.LoadFile(filename)) {
        errorStream <<"XML IMPORT ABORTED: " << doc.ErrorDesc() << std::endl;
        return ImportAborted;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        errorStream << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return ImportAborted;
    }

    for (TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        std::string elemName = elem->Value();
        if (elemName == "DEVICE") {

            TiXmlElement *name = elem->FirstChildElement("name");
            TiXmlElement *emission = elem->FirstChildElement("emission");
            TiXmlElement *speed = elem->FirstChildElement("speed");
            TiXmlElement *type = elem->FirstChildElement("type");



            if (name == NULL){
                errorStream << "PARTIAL IMPORT: Expected <name> ... </name>" << std::endl;
                endresult = PartialImport;

                continue;
            }
            if (emission == NULL){
                errorStream << "PARTIAL IMPORT: Expected <emission> ... </emission>" << std::endl;
                endresult = PartialImport;
                continue;
            }
            if (speed == NULL){
                errorStream << "PARTIAL IMPORT: Expected <speed> ... </speed>" << std::endl;
                endresult = PartialImport;
                continue;
            }if (type == NULL){
                errorStream << "PARTIAL IMPORT: Expected <type> ... </type> (Device)" << std::endl;
                endresult = PartialImport;
                continue;
            }

            Device *newDevice = nullptr;

            string typeString = type->GetText();

            if (typeString == "bw"){
               newDevice = new BWPrinter();
            } else if (typeString == "color"){
                newDevice = new ColorPrinter();
            } else if(typeString == "scan"){
                newDevice = new Scanner();
            }
            else {
                errorStream << "PARTIAL IMPORT: Expected types are bw, color and scan" << std::endl;
                endresult = PartialImport;
                continue;

            }

            if (name && emission && speed && type) {
                try{
                    newDevice->setName(name->GetText());
                    newDevice->setEmission(std::stoi(emission->GetText()));
                    newDevice->setSpeed(std::stoi(speed->GetText()));
                    newDevice->setType(type->GetText());
                    if(newDevice->getEmission() < 0 || newDevice->getSpeed() < 0){
                        isConsistent = false;
                    }
                    system.addDevice(newDevice);
                } catch (std::exception& e){
                    errorStream << "Partial import: " << e.what() << std::endl;
                    endresult = PartialImport;

                }
            }
        } else if (elemName == "JOB") {
            Job* newJob = new Job();
            TiXmlElement *jobNumber = elem->FirstChildElement("jobNumber");
            TiXmlElement *pageCount = elem->FirstChildElement("pageCount");
            TiXmlElement *userName = elem->FirstChildElement("userName");
            TiXmlElement *type = elem->FirstChildElement("type");
            if (jobNumber == NULL){
                errorStream << "PARTIAL IMPORT: Expected <jobNumber> ... </jobNumber>" << std::endl;
                endresult = PartialImport;
                continue;
            }
            if (pageCount == NULL){
                errorStream << "PARTIAL IMPORT: Expected <pageCount> ... </pageCount>" << std::endl;
                endresult = PartialImport;
                continue;
            }
            if (userName == NULL){
                errorStream << "PARTIAL IMPORT: Expected <userName> ... </userName>" << std::endl;
                endresult = PartialImport;
                continue;
            }if (type == NULL){
                errorStream << "PARTIAL IMPORT: Expected <type> ... </type> (Job)" << std::endl;
                endresult = PartialImport;
                continue;
            }
            string typeString = type->GetText();

            if (typeString != "bw" && typeString != "color" && typeString != "scan"){
                errorStream << "PARTIAL IMPORT: Expected types are bw, color and scan" << std::endl;
                endresult = PartialImport;
                continue;
            }



            if (jobNumber && pageCount && userName && type) {
                try {
                    int jobNumberInt = stoi(jobNumber->GetText());
                    newJob->setJobNumber(jobNumberInt);
                    newJob->setPageCount(stoi(pageCount->GetText()));
                    newJob->setUserName(userName->GetText());
                    if(newJob->getPageCount() < 0 || newJob->getJobNumber() < 0){
                        isConsistent = false;
                    }
                    jobNumbers.insert(jobNumberInt);
                    if (jobNumbers.count(jobNumberInt) > 1){
                        isConsistent = false;
                    }
                    system.addJob(newJob);
                } catch (std::exception &e) {
                    errorStream << "Partial import: " << e.what() << std::endl;
                    endresult = PartialImport;
                }
            }

        } else {
            errorStream << "Unrecognizable element: " << elemName << std::endl;
            endresult = PartialImport;
            continue;
        }

    }

    if (!isConsistent){
        errorStream << "XML IMPORT ABORTED: Inconsistent printing system." << std::endl;
        return ImportAborted;
    }

    doc.Clear();
    system.assigning_jobs();
    return endresult;

}

