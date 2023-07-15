#pragma once
#include "../Domain/Dog.h"

class TestsDomain{
private:

    //Test for the implicit constructor of Dog
    void testImplicitConstructor();

    //Test for the explicit constructor of Dog
    void testExplicitConstructor();

    //Test all the getters & setters
    void testGettersAndSetters();

    //Test to see that if we modify a dog, its copy won't also get modified
    void testCopy();

    //Test the copy constructor
    void testCopyConstructor();

    //Test the "=" operator
    void testEqualOperator();

    //Test the toString method
    void testToStringMethod();

    //Test the "==" operator (breed && name - the same)
    void testDoubleEqualOperator();

public:
    void runDomainTests();
};