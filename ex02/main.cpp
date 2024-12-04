#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate() {
    int random = std::rand() % 3;

    if (random == 0) {
        std::cout << "Generated: A" << std::endl;
        return new A();
    } else if (random == 1) {
        std::cout << "Generated: B" << std::endl;
        return new B();
    } else {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Type: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Type: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Type: C" << std::endl;
    } else {
        std::cout << "Type: Unknown" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
        return;
    } catch (...) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type: B" << std::endl;
        return;
    } catch (...) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type: C" << std::endl;
        return;
    } catch (...) {
        std::cout << "Type: Unknown" << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    Base* base = generate();

    std::cout << "Identify using pointer: ";
    identify(base);

    std::cout << "Identify using reference: ";
    identify(*base);

    delete base;

    return 0;
}
