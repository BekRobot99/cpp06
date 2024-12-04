#include "Data.hpp"

Data::Data(const std::string& name, int age) : name(name), age(age) {}

Data::Data(const Data& other) : name(other.name), age(other.age) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
    }
    return *this;
}

Data::~Data() {}
