#include "Tests.h"


void Tests::runDomainTests(){
    TestsDomain domainTests = TestsDomain();
    domainTests.runDomainTests();
}

void Tests::runValidationTests() {
    TestsValidation validationTests = TestsValidation();
    validationTests.runValidationTests();
}

void Tests::runAllTests() {
    this->runDomainTests();
    this->runValidationTests();
    //this->runRepositoryTests();
    //this->runServiceTests();
}

