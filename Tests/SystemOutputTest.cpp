//
// Created by ADMIN on 16/03/2024.
//
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

#include "../Objects/System.h"
#include "../SystemImporter.h"
#include "../Utils.h"


class OutputTest : public ::testing::Test {
protected:
    friend class System;

    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    System system_;

};
/*
TEST_F(OutputTest, OutputHappyDay) {
    ASSERT_TRUE(DirectoryExists("../TestOutput"));

    ofstream myfile;
    SuccessEnum importResult;

    myfile.open("../TestOutput/happyday.xml");
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

    errStream.open("../TestOutput/happydayOutputERR.txt");
    importResult = SystemImporter::importSystem("../test.xml", errStream, system_);
    errStream.close();

    EXPECT_TRUE(FileIsEmpty("../TestOutput/happydayOutputERR.txt"));
    EXPECT_EQ(Success, importResult);

    system_.clear();
    EXPECT_TRUE(system_.devices.empty() && system_.jobs.empty());

}

TEST_F(OutputTest, correctOutput) {
    ASSERT_TRUE(DirectoryExists("../TestOutput"));
    EXPECT_TRUE(FileExists("../TestOutput/happyDayExpectedOut.txt"));

    System system;
    SystemImporter::importSystem("../TestOutput/happyday.xml", cerr, system);
    system.output_info("../TestOutput/happyDayOut.txt");

    EXPECT_TRUE(FileCompare("../TestOutput/happyDayOut.txt", "../TestOutput/happyDayExpectedOut.txt"));
}
*/