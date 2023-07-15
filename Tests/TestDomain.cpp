#include "TestDomain.h"
#include <cassert>

void TestsDomain::runDomainTests() {
    this->testImplicitConstructor();
    this->testExplicitConstructor();
    this->testGettersAndSetters();
    this->testCopy();
    this->testCopyConstructor();
    this->testEqualOperator();
    this->testToStringMethod();
    this->testDoubleEqualOperator();
}

void TestsDomain::testImplicitConstructor() {
    Dog dog{};
    assert(dog.getBreed().empty());
    assert(dog.getName().empty());
    assert(dog.getAge() == -1);
    assert(dog.getSiteLink().empty());
}

void TestsDomain::testExplicitConstructor() {
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    assert(dog1.getBreed() == "Dachshund");
    assert(dog1.getName() == "Pixie");
    assert(dog1.getAge() == 4);
    assert(dog1.getSiteLink() == "https://idk");
}

void TestsDomain::testGettersAndSetters() {
    Dog dog{};
    dog.setBreed("Bichon");
    dog.setName("Toto");
    dog.setAge(5);
    dog.setSiteLink("https://idk2");
    assert(dog.getBreed() == "Bichon");
    assert(dog.getName() == "Toto");
    assert(dog.getAge() == 5);
    assert(dog.getSiteLink() == "https://idk2");
}

void TestsDomain::testCopy() {
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog dog2{dog1}; //One way to make a copy of dog1 in dog2
    dog1.setName("Cynthia");
    assert(dog1.getBreed() == "Dachshund");
    assert(dog1.getName() == "Cynthia");
    assert(dog1.getAge() == 4);
    assert(dog1.getSiteLink() == "https://idk");
    assert(dog2.getBreed() == "Dachshund");
    assert(dog2.getName() == "Pixie");
    assert(dog2.getAge() == 4);
    assert(dog2.getSiteLink() == "https://idk");
}

void TestsDomain::testCopyConstructor() {
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog dog2{dog1}; //One way to make a copy of dog1 in dog2
    Dog dog3 = dog2; //Another way to make a copy of dog1 in dog2 (calling the copy-constructor "=")
    dog2.setName("Cynthia");
    assert(dog2.getBreed() == "Dachshund");
    assert(dog2.getName() == "Cynthia");
    assert(dog2.getAge() == 4);
    assert(dog2.getSiteLink() == "https://idk");
    assert(dog3.getBreed() == "Dachshund");
    assert(dog3.getName() == "Pixie");
    assert(dog3.getAge() == 4);
    assert(dog3.getSiteLink() == "https://idk");
}

void TestsDomain::testEqualOperator() {
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog dog2{dog1}; //One way to make a copy of dog1 in dog2
    Dog dog3 = dog2; //Another way to make a copy of dog1 in dog2 (calling the copy-constructor "=")
    Dog dog4;
    dog4 = dog3; //We can also do it like this, but it does not call the copy-constructor ("=" operator)
    dog3.setName("Cynthia");
    assert(dog3.getBreed() == "Dachshund");
    assert(dog3.getName() == "Cynthia");
    assert(dog3.getAge() == 4);
    assert(dog3.getSiteLink() == "https://idk");
    assert(dog4.getBreed() == "Dachshund");
    assert(dog4.getName() == "Pixie");
    assert(dog4.getAge() == 4);
    assert(dog4.getSiteLink() == "https://idk");
}

void TestsDomain::testToStringMethod() {
    Dog dog{};
    dog.setBreed("Bichon");
    dog.setName("Toto");
    dog.setAge(5);
    dog.setSiteLink("https://idk2");
    assert(dog.toString() == "Dog \n\t breed: Bichon\n\t name: Toto\n\t age: 5\n\t siteLink: https://idk2\n");
}

void TestsDomain::testDoubleEqualOperator() {
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog dog2{"Dachshund", "Pixie", 5, "https://idk2"};
    assert(dog1 == dog2);
}