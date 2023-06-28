#include "DogValidator.h"

DogValidator::DogValidator() = default;

bool DogValidator::validateString(const string &input) {
    for (char i : input)
        if (isdigit(i) != false)
            return false;
    return true;
}

void DogValidator::validateBreed(const string &breed) {
    string errors;
    if (!validateString(breed))
        errors += string("The breed contains digits!");
    if (breed.length() == 0)
        errors += string("The breed is empty!");
    if (!errors.empty())
        throw ValidationException(errors);
}

void DogValidator::validateName(const string &name) {
    string errors;
    if (!validateString(name))
        errors += string("The name contains digits!");
    if (name.length() == 0)
        errors += string("The name is empty!");
    if (!isupper(name[0]))
        errors += string("The name should start with a capital letter!");
    if (!errors.empty())
        throw ValidationException(errors);
}

void DogValidator::validateAgeString(const string &age) {
    string errors;
    if (age.empty())
        errors += string("The age is empty!");
    if (age.find_first_not_of("0123456789") != string::npos)
        errors += string("The age input has non-digit characters!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void DogValidator::validateAge(int age) {
    string errors;
    if (age < 0)
        errors += string("Age cannot be smaller than 0!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void DogValidator::validatePhotoLink(const string &photo) {
    string errors;
    if (photo.length() == 0)
        errors += std::string("The link input is empty!");
    if (photo.find("www") == std::string::npos)
        errors += std::string("The link is not a valid one!");
    if(!errors.empty())
        throw ValidationException(errors);
}

DogValidator::~DogValidator() = default;
