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

    importResult = SystemImporter::importSystem("../test.xml", cerr, system_);
    ASSERT_EQ(Success, importResult);

}









