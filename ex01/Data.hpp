#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data {
    std::string name;
    int age;

    //Data(); not need any Orthodox Canonical Form 
    // used as extra part 
    Data(const std::string& name = "Default", int age = 0);
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();
};

#endif
