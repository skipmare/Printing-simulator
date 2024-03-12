#include <iostream>
#include "tinyxml.h"
#include "string"
#include "vector"
#include <typeinfo>
using namespace std;

class Elements{
    string e_name;
    string a_1_name;
    string a_2_name;
    string a_3_name;


    public:

    void set_e_name(string e_name){
        this->e_name = e_name;
    }
    void set_a_1_name(string a_1_name){
        this->a_1_name = a_1_name;
    }
    void set_a_2_name(string a_2_name){
        this->a_2_name = a_2_name;
    }
    void set_a_3_name(string a_3_name){
        this->a_3_name = a_3_name;
    }

};

