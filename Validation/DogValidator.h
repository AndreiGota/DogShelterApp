#pragma once
#include "../Domain/Dog.h"
#include "../Exceptions/ValidationException.h"

class DogValidator {
public:
    DogValidator();
    bool validateString(const string& input);
    void validateBreed(const string& breed);
    void validateName(const string& name);
    void validateAgeString(const string& age);
    void validateAge(int age);
    void validateSiteLink(const string& siteLink);
    ~DogValidator();
};