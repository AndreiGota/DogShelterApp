#pragma once
#include "TestDomain.h"
#include "TestValidation.h"
#include "TestRepository.h"

class Tests {
private:
    void runDomainTests();
    void runValidationTests();
    void runRepositoryTests();
//    void runServiceTests();
public:
    void runAllTests();
};