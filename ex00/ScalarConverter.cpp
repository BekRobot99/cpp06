#include "ScalarConverter.hpp"
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    try {
        if (isChar(literal)) {
            char c = literal[1];
            displayConversion(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), false, false);
        } else if (isInt(literal)) {
            int i = std::stoi(literal);
            displayConversion(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i), i < 0 || i > 255, false);
        } else if (isFloat(literal)) {
            float f = std::stof(literal);
            displayConversion(
                static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f), 
                f < 0 || f > 255 || !std::isfinite(f), !std::isfinite(f)
            );
        } else if (isDouble(literal)) {
            double d = std::stod(literal);
            displayConversion(
                static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d, 
                d < 0 || d > 255 || !std::isfinite(d), !std::isfinite(d)
            );
        } else {
            throw std::invalid_argument("Invalid literal");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        displayConversion(0, 0, 0.0f, 0.0, true, true);
    }
}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isInt(const std::string& literal) {
    try {
        std::stoi(literal);
        return true;
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isFloat(const std::string& literal) {
    try {
        if (literal == "-inff" || literal == "+inff" || literal == "nanf")
            return true;
        if (literal.back() == 'f') {
            std::stof(literal.substr(0, literal.length() - 1));
            return true;
        }
        return false;
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isDouble(const std::string& literal) {
    try {
        if (literal == "-inf" || literal == "+inf" || literal == "nan")
            return true;
        std::stod(literal);
        return true;
    } catch (...) {
        return false;
    }
}

void ScalarConverter::displayConversion(char c, int i, float f, double d, bool impossibleChar, bool impossibleInt) {
    if (impossibleChar)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    if (impossibleInt)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}
