//
// Created by abdir on 14/03/2024.
//


#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

#include "../Objects/System.h"
#include "../SystemImporter.h"
#include "../Utils.h"


class SystemInputTest : public ::testing::Test {
protected:
    friend class System;

    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    System system_;

};



TEST_F(SystemInputTest, InputHappyDay) {
    ASSERT_TRUE(DirectoryExists("../TestInput"));

    ofstream myfile;
    SuccessEnum importResult;

    myfile.open("../TestInput/happyday.xml");
    myfile << "<?xml version=\"1.0\" ?>\n"
    <<"<SYSTEM>\n"
    << "\t<DEVICE>\n"
    << "\t\t<name>Office_Printer5</name>\n"
    << "\t\t<emission>5</emission>\n"
    << "\t\t<type>bw</type>\n"
    << "\t\t<speed>5</speed>\n"
    << "\t</DEVICE>\n"
    << "\t<JOB>\n"
    << "\t\t<jobNumber>89751</jobNumber>\n"
    << "\t\t<pageCount>2</pageCount>\n"
    << "\t\t<type>bw</type>\n"
    << "\t\t<userName>SergeDemeyer</userName>\n"
    << "\t</JOB>\n"
    << "\t<JOB>\n"
    << "\t\t<jobNumber>2189</jobNumber>\n"
    << "\t\t<pageCount>3</pageCount>\n"
    << "\t\t<type>bw</type>\n"
    << "\t\t<userName>anonymous_user</userName>\n"
    << "\t</JOB>\n"
   << "</SYSTEM>";
    myfile.close();
    std::ofstream errStream;

    errStream.open("../TestInput/happydayInputERR.txt");
    importResult = SystemImporter::importSystem("../TestInput/happyday.xml", errStream, system_);
    errStream.close();

    EXPECT_TRUE(FileIsEmpty("../TestInput/happydayInputERR.txt"));
    EXPECT_EQ(Success, importResult);

    system_.clear();
    EXPECT_TRUE(system_.devices.empty() && system_.jobs.empty());


}


TEST_F(SystemInputTest, InputInconsistency) {
    ASSERT_TRUE(DirectoryExists("../TestInput"));

    SuccessEnum importResult;
    int fileCounter = 1;
    string filename = "../TestInput/InconsistentERR" + to_string(fileCounter) + ".xml";
    string OutputFileName = "../TestInput/InconsistentERR" + to_string(fileCounter) + ".txt";
    std::ofstream errStream;

    while (FileExists(filename)) {
        errStream.open(OutputFileName);
        importResult = SystemImporter::importSystem(filename.c_str(), errStream, system_);
        errStream.close();

        EXPECT_TRUE(FileCompare("../TestInput/InconsistentERR.txt", OutputFileName));
        EXPECT_EQ(ImportAborted, importResult);


        fileCounter++;
        OutputFileName = "../TestInput/InConsistentERR" + to_string(fileCounter) + ".txt";
        filename = "../TestInput/InconsistentERR" + to_string(fileCounter) + ".xml";
        system_.clear();
        EXPECT_TRUE(system_.devices.empty() && system_.jobs.empty());
    }
    EXPECT_EQ(6, fileCounter);
}





TEST_F(SystemInputTest, InputXMLSyntaxErrors) {
    ASSERT_TRUE(DirectoryExists("../TestInput"));

    SuccessEnum importResult;
    int fileCounter = 1;
    string filename = "../TestInput/InputXMLSyntaxError" + to_string(fileCounter) + ".xml";
    string OutputFileName = "../TestInput/InputXMLSyntaxError" + to_string(fileCounter) + ".txt";
    std::ofstream errStream;

    while (FileExists(filename)) {
        errStream.open(OutputFileName);
        importResult = SystemImporter::importSystem(filename.c_str(), errStream, system_);
        errStream.close();

        EXPECT_EQ(ImportAborted, importResult);


        fileCounter++;
        filename = "../TestInput/InputXMLSyntaxError" + to_string(fileCounter) + ".xml";
        OutputFileName = "../TestInput/InputXMLSyntaxError" + to_string(fileCounter) + ".txt";

        system_.clear();
        EXPECT_TRUE(system_.devices.empty() && system_.jobs.empty());
    }
    EXPECT_EQ(5, fileCounter);
}




/*
TEST_F(SystemInputTest, InputLegalSystem) {
    ASSERT_TRUE(DirectoryExists("../TestInput"));

    SuccessEnum importResult;
    int fileCounter = 1;
    string filename = "../TestInput/InputLegalSystem" + to_string(fileCounter) + ".xml";
    string OutputFileName = "../TestInput/InputLegalSystemERR.txt";
    std::ofstream errStream;

    while (FileExists(filename)) {
        errStream.open(OutputFileName);
        importResult = SystemImporter::importSystem(filename.c_str(), errStream, system_);
        errStream.close();

        EXPECT_EQ(Success, importResult);
        EXPECT_TRUE(FileIsEmpty(OutputFileName));


        fileCounter++;
        filename = "../TestInput/InputLegalSystem" + to_string(fileCounter) + ".xml";

        system_.clear();
        EXPECT_TRUE(system_.devices.empty() && system_.jobs.empty());
    }
    EXPECT_EQ(4, fileCounter);

}



TEST_F(SystemInputTest, InputIllegalSystem) {
    ASSERT_TRUE(DirectoryExists("../TestInput"));

    SuccessEnum importResult;
    int fileCounter = 1;
    string filename = "../TestInput/InputIllegalSystem" + to_string(fileCounter) + ".xml";
    string OutputFileName = "../TestInput/InputIllegalSystemERR" + to_string(fileCounter) + ".txt";
    std::ofstream errStream;

    while (FileExists(filename)) {
        errStream.open(OutputFileName);
        importResult = SystemImporter::importSystem(filename.c_str(), errStream, system_);
        errStream.close();

        EXPECT_EQ(PartialImport, importResult);


        fileCounter++;
        filename = "../TestInput/InputIllegalSystem" + to_string(fileCounter) + ".xml";
        OutputFileName = "../TestInput/InputXMLSyntaxError" + to_string(fileCounter) + ".txt";

        system_.clear();
        EXPECT_TRUE(system_.devices.empty() && system_.jobs.empty());
    }
    EXPECT_EQ(8, fileCounter);

}
*/