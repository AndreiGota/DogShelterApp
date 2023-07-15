#pragma once
#include "../Validation/DogValidator.h"
#include "../Exceptions/ValidationException.h"

class TestsValidation{
private:
    void testValidateString();
    void testValidateBreed();
    void testValidateName();
    void testValidateAgeString();
    void testValidateAge();
    void testValidateSiteLink();
public:
    void runValidationTests();
};