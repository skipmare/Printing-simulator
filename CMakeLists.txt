cmake_minimum_required(VERSION 3.26)
project(PSE_2023_2023)

set(CMAKE_CXX_STANDARD 14)

add_executable(PSE_2023_2023
        main.cpp
        tinyxml/tinystr.cpp
        tinyxml/tinyxml.cpp
        tinyxml/tinyxmlerror.cpp
        tinyxml/tinyxmlparser.cpp
        DesignByContract.h
        Xml_Importer.h)
