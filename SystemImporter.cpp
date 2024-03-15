#include "SystemImporter.h"
#include "DesignByContract.h"
#include "tinyxml/tinyxml.h"


SuccessEnum SystemImporter::importSystem(const char *filename, std::ostream &errorStream, System& system) {
    bool isConsistent = true;
    SuccessEnum endresult = Success;
    TiXmlDocument doc;
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
            Device newDevice;
            TiXmlElement *name = elem->FirstChildElement("name");
            TiXmlElement *emission = elem->FirstChildElement("emission");
            TiXmlElement *speed = elem->FirstChildElement("speed");
            if (name && emission && speed) {
                try{
                    newDevice.setName(name->GetText());
                    newDevice.setEmission(stoi(emission->GetText()));
                    newDevice.setSpeed(stoi(speed->GetText()));
                    if(newDevice.getEmission() < 0 || newDevice.getSpeed() < 0){
                        isConsistent = false;
                    }
                    system.addDevice(newDevice);
                } catch (std::exception& e){
                    errorStream << "Partial import: " << e.what() << std::endl;
                    endresult = PartialImport;

                }
            } else {
                errorStream << "Partial import: Device is missing information." << std::endl;
                endresult = PartialImport;
            }
        } else if (elemName == "JOB") {
            Job newJob;
            TiXmlElement *jobNumber = elem->FirstChildElement("jobNumber");
            TiXmlElement *pageCount = elem->FirstChildElement("pageCount");
            TiXmlElement *userName = elem->FirstChildElement("userName");
            if (jobNumber && pageCount && userName) {
                try {
                    newJob.setJobNumber(stoi(jobNumber->GetText()));
                    newJob.setPageCount(stoi(pageCount->GetText()));
                    newJob.setUserName(userName->GetText());
                    if(newJob.getPageCount() < 0 || newJob.getJobNumber() < 0){
                        isConsistent = false;
                    }
                    system.addJob(newJob);
                } catch (std::exception &e) {
                    errorStream << "Partial import: " << e.what() << std::endl;
                    endresult = PartialImport;
                }
            }

            else {
                errorStream << "Partial import: Job has invalid information." << std::endl;
                endresult = PartialImport;
            }

        } else {
            errorStream << "Unrecognizable element: " << elemName << std::endl;
            endresult = PartialImport;
            continue;
        }

    }

    if (!isConsistent){
        errorStream << "XML IMPORT ABORTED: Inconsistent printing system." << std::endl;
        //system.clear(); Nog nodig om te implementeren
        return ImportAborted;
    }


    doc.Clear();

    return endresult;

}