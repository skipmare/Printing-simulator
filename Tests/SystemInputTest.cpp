//
// Created by abdir on 14/03/2024.
//


#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

#include "../System.h"
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
    <<"<system>\n"
    << "\t<devices>\n"
    << "\t\t<name>Office_Printer5</name>\n"
    << "\t\t<emission>5</emission>\n"
    << "\t\t<speed>5</speed>\n"
    << "\t</devices>\n"
    << "\t<jobs>\n"
    << "\t\t<jobNumber>89751</jobNumber>\n"
    << "\t\t<pageCount>2</pageCount>\n"
    << "\t\t<userName>SergeDemeyer</userName>\n"
    << "\t</jobs>\n"
    << "\t<jobs>\n"
    << "\t\t<jobNumber>2189</jobNumber>\n"
    << "\t\t<pageCount>3</pageCount>\n"
    << "\t\t<userName>anonymous_user</userName>\n"
    << "\t</jobs>\n"
   << "</system>";
    myfile.close();
    std::ofstream errStream;

    errStream.open("../TestInput/happydayInputERR.txt");
    importResult = SystemImporter::importSystem("../test.xml", errStream, system_);
    errStream.close();

    EXPECT_TRUE(FileIsEmpty("../TestInput/happydayInputERR.txt"));
    EXPECT_EQ(Success, importResult);

}


TEST_F(SystemInputTest, InputConsistentSystem) {
    ASSERT_TRUE(DirectoryExists("../TestInput"));

    SuccessEnum importResult;
    int fileCounter = 1;
    string filename = "../TestInput/InConsistentERR" + to_string(fileCounter) + ".xml";
    string OutputFileName = "../TestInput/InConsistentERR" + to_string(fileCounter) + ".txt";
    std::ofstream errStream;

    while (FileExists(filename)) {
        errStream.open(OutputFileName);
        importResult = SystemImporter::importSystem(filename.c_str(), errStream, system_);
        errStream.close();

        EXPECT_TRUE(FileIsEmpty("../TestInput/InconsistentInputERR.txt"));
        EXPECT_EQ(ImportAborted, importResult);

        fileCounter++;
        filename = "../TestInput/InConsistentERR" + to_string(fileCounter) + ".xml";
        OutputFileName = "../TestInput/InConsistentERR" + to_string(fileCounter) + ".txt";
    }
    EXPECT_EQ(1, fileCounter);
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

        EXPECT_TRUE(FileIsEmpty("../TestInput/InconsistentInputERR.txt"));
        EXPECT_EQ(ImportAborted, importResult);

        fileCounter++;
        filename = "../TestInput/InConsistentERR" + to_string(fileCounter) + ".xml";
        OutputFileName = "../TestInput/InputXMLSyntaxError" + to_string(fileCounter) + ".txt";
    }
    EXPECT_EQ(1, fileCounter);
}







