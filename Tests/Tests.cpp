#include "Tests.h"

void Tests::runAllTests() {
    this->runDomainTests();
    this->runValidationTests();
    this->runRepositoryTests();
    this->runServiceTests();
}

void Tests::runDomainTests(){
    TestsDomain domainTests = TestsDomain();
    domainTests.runDomainTests();
}

void Tests::runValidationTests() {
    TestsValidation validationTests = TestsValidation();
    validationTests.runValidationTests();
}
void Tests::runRepositoryTests() {
    TestsRepository repositoryTests = TestsRepository();
    repositoryTests.runRepositoryTests();
}

void Tests::runServiceTests() {
    TestsService serviceTests = TestsService();
    serviceTests.runServiceTests();
}


