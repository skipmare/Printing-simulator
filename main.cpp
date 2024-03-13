#include <iostream>
#include "tinyxml/tinyxml.h"

#include "string"
#include "vector"
#include <typeinfo>
#include "System.h"
using namespace std;



int main() {
    TiXmlDocument doc;
    if (!doc.LoadFile("test.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }

    System system;
    string rootName = root->Value();
    if (rootName != "SYSTEM") {
        cerr << "XML PARTIAL IMPORT: Expected <SYSTEM> ... </SYSTEM> and got <"
             << rootName <<  "> ... </" << rootName << ">." << endl;
    }

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL;
         elem = elem->NextSiblingElement()) {

        string name = elem->Value();
        try {
            if (name == "DEVICE") {
                Device device;

                for (TiXmlElement *child = elem->FirstChildElement(); child != NULL;
                     child = child->NextSiblingElement()) {
                    string eName = child->Value();
                    TiXmlNode *text = child->FirstChild();

                    if (eName == "name") {
                        device.setName(text->Value());
                    } else if (eName == "emission") {
                        device.setEmission(stoi(text->Value()));
                    } else if (eName == "speed") {
                        device.setSpeed(stoi(text->Value()));
                    } else {
                        throw std::runtime_error("Invalid information for DEVICE");
                    }
                }

                system.addDevice(device);
                cout << '\n';

                device.print();

            } else if (name == "JOB") {
                Job job;

                for (TiXmlElement *child = elem->FirstChildElement(); child != NULL;
                     child = child->NextSiblingElement()) {
                    string eName = child->Value();
                    TiXmlNode *text = child->FirstChild();

                    if (eName == "jobNumber") {
                        job.setJobNumber(stoi(text->Value()));
                    } else if (eName == "pageCount") {
                        job.setPageCount(stoi(text->Value()));
                    } else if (eName == "userName") {
                        job.setUserName(text->Value());
                    } else {
                        throw std::runtime_error("Invalid information for JOB");
                    }
                }

                system.addJob(job);
                cout << '\n';
                job.print();
            } else {
                throw std::runtime_error("Unrecognizable element");
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            continue;
        }
    }


    //system.print();
}

