#include "Serializer.hpp"

int main()
{
    Data original("John Doe", 42);

    Data* originalPtr = &original;
    uintptr_t raw = Serializer::serialize(originalPtr);

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Original Data pointer: " << originalPtr << std::endl;
    std::cout << "Serialized uintptr_t value: " << raw << std::endl;
    std::cout << "Deserialized Data pointer: " << deserializedPtr << std::endl;

    if (originalPtr == deserializedPtr) {
        std::cout << "Success: The deserialized pointer matches the original pointer." << std::endl;
        std::cout << "Deserialized Data content: name=" << deserializedPtr->name << ", age=" << deserializedPtr->age << std::endl;
    } else {
        std::cout << "Error: The deserialized pointer does not match the original pointer." << std::endl;
    }

    return 0;
}
