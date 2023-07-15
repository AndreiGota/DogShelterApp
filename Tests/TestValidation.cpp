#include "TestValidation.h"
#include <cassert>


void TestsValidation::runValidationTests() {
    this->testValidateString();
    this->testValidateBreed();
    this->testValidateName();
    this->testValidateAgeString();
    this->testValidateAge();
    this->testValidateSiteLink();
}

void TestsValidation::testValidateString() {
    DogValidator validator;
    assert(validator.validateString("SomeText") == true);
    assert(validator.validateString("TextWith123") == false);
}

void TestsValidation::testValidateBreed() {
    DogValidator validator;
    try {
        validator.validateBreed("German Shepherd 123");
    } catch (const ValidationException& e) {
        assert(e.getErrorMessage() == string("The breed contains digits!"));
    }
    try {
        validator.validateBreed("");
    } catch (const ValidationException& e) {
        assert(e.getErrorMessage() == string("The breed is empty!"));
    }
}

void TestsValidation::testValidateName() {
    DogValidator validator;

    try {
        validator.validateName("Max123");
    } catch (const ValidationException& e) {
        assert(e.getErrorMessage() == string("The name contains digits!"));
    }

    try {
        validator.validateName("");
    } catch (const ValidationException& e) {
        assert(e.getErrorMessage() == string("The name is empty!The name should start with a capital letter!"));
    }
}

void TestsValidation::testValidateAgeString() {
    DogValidator validator;

    try {
        validator.validateAgeString("5a");
    } catch (const ValidationException& e) {
        assert(e.getErrorMessage() == string("The age input has non-digit characters!"));
    }
    try {
        validator.validateAgeString("");
    } catch (const ValidationException& e) {
        assert(e.getErrorMessage() == string("The age is empty!"));
    }
}

void TestsValidation::testValidateAge() {
    DogValidator validator;

    try {
        validator.validateAge(-1);
    } catch (const ValidationException& e) {
        assert(e.getErrorMessage() == string("Age cannot be smaller than 0!"));
    }
}

void TestsValidation::testValidateSiteLink() {
    DogValidator validator;

    try {
        validator.validateSiteLink("");
    } catch (const ValidationException& e) {
        assert(e.getErrorMessage() == string("The link input is empty!The link is not a valid one!"));
    }

    try {
        validator.validateSiteLink("example.com");
    } catch (const ValidationException& e) {
        assert(e.getErrorMessage() == string("The link is not a valid one!"));
    }
}
