#include "TestService.h"
#include <cassert>
#include <iostream>

void TestsService::runServiceTests() {
    this->testGetAllDogsAdministrator();
    this->testAddDogAdministrator();
    this->testDeleteDogAdministrator();
    this->testUpdateDogAdministrator();
    this->testGetLengthAllDogsAdministrator();
    this->testAddDogUser();
    this->testGetAllDogsUser();
    this->testGetFilteredDogs();
}

void TestsService::testGetAllDogsAdministrator() {
    Repository repo;
    AdminService service = AdminService{repo};
    assert(repo.getDogsRepo() == service.getAllDogs());
    service.addDogService("Dachshund", "Pixie", 4, "https://idk");
    service.addDogService("Bichon", "Toto", 5, "https://idk2");
    service.addDogService("Pug", "Alfie", 2, "https://idk3");
    assert(repo.getDogsRepo() == service.getAllDogs());
    assert(repo.getDogsRepo()[0] == service.getAllDogs()[0]);
    assert(repo.getDogsRepo()[1] == service.getAllDogs()[1]);
    assert(repo.getDogsRepo()[2] == service.getAllDogs()[2]);
}

void TestsService::testGetLengthAllDogsAdministrator() {
    Repository repo = Repository();
    AdminService service = AdminService{repo};
    assert(repo.getNrDogsRepo() == service.getLengthAllDogs());
    service.addDogService("Dachshund", "Pixie", 4, "https://idk");
    service.addDogService("Bichon", "Toto", 5, "https://idk2");
    service.addDogService("Pug", "Alfie", 2, "https://idk3");
    assert(repo.getNrDogsRepo() == service.getLengthAllDogs());
}

void TestsService::testAddDogAdministrator() {
    Repository repo = Repository();
    AdminService service = AdminService{repo};
    try{
        service.addDogService("", "", -1, "");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "The breed is empty!");
    }
    assert(service.getLengthAllDogs() == 0);
    service.addDogService("Dachshund", "Pixie", 4, "https://idk");
    assert(service.getLengthAllDogs() == 1);
    try{
        service.addDogService("Dachshund", "Pixie", 3, "https://idk2");
    }
    catch(const ServiceException &se){
        assert(se.getErrorMessage() == "Dog with this breed and name already exists!\n");
    }
}

void TestsService::testDeleteDogAdministrator() {
    Repository repo = Repository();
    AdminService service = AdminService{repo};
    assert(service.getLengthAllDogs() == 0);
    service.addDogService("Dachshund", "Pixie", 4, "https://idk");
    service.addDogService("Bichon", "Toto", 5, "https://idk2");
    service.addDogService("Pug", "Alfie", 2, "https://idk3");
    service.addDogService("Beagle", "Charlie", 3, "https://idk4");
    assert(service.getLengthAllDogs() == 4);
    service.deleteDogService("Dachshund", "Pixie");
    assert(service.getLengthAllDogs() == 3);
    assert(service.getAllDogs()[0] == Dog("Bichon", "Toto",  4, "https://idk"));
    service.deleteDogService("Beagle", "Charlie");
    assert(service.getLengthAllDogs() == 2);
    service.deleteDogService("Bichon", "Toto");
    service.deleteDogService("Pug", "Alfie");
    assert(service.getLengthAllDogs() == 0);
    try{
        service.deleteDogService("Dachshund", "Pixie");
    }
    catch(const ServiceException &se){
        assert(se.getErrorMessage() == "Dog does not exist!\n");
    }
    try{
        service.deleteDogService("", "");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "The breed is empty!");
    }
}

void TestsService::testUpdateDogAdministrator() {
    Repository repo = Repository();
    AdminService service = AdminService{repo};
    service.addDogService("Dachshund", "Pixie", 4, "https://idk");
    service.addDogService("Bichon", "Toto", 5, "https://idk2");
    service.addDogService("Pug", "Alfie", 2, "https://idk3");
    service.updateDogService("Dachshund", "Pixie", "Bulldog", "Cynthia", 7, "https://example.com");
    assert(service.getAllDogs()[0].getName() == "Cynthia");
    assert(service.getAllDogs()[0].getBreed() == "Bulldog");
    assert(service.getAllDogs()[0].getAge() == 7);
    assert(service.getAllDogs()[0].getSiteLink() == "https://example.com");

    try{
        service.updateDogService("", "", "", "Terrier", -1, "");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "The breed is empty!");
    }

    try{
        service.updateDogService("Pug", "Alfie", "Bulldog", "Andy", -5, "https://example.com");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "Age cannot be smaller than 0!");
    }

    try{
        service.updateDogService("Kitty", "Cat", "", "", -1, "");
    }
    catch(const ServiceException &se){
        assert(se.getErrorMessage() == "Dog does not exist!\n");
    }
}

void TestsService::testAddDogUser() {
    Repository repo = Repository();
    UserService service = UserService{repo};
    try{
        service.addDogService("", "", -1, "");
    }
    catch(const ValidationException &ve){
        assert(ve.getErrorMessage() == "The breed is empty!");
    }
    assert(service.getLengthAllDogs() == 0);
    service.addDogService("Dachshund", "Pixie", 4, "https://idk");
    assert(service.getLengthAllDogs() == 1);
    try{
        service.addDogService("Dachshund", "Pixie", 3, "https://idk2");
    }
    catch(const ServiceException &se){
        assert(se.getErrorMessage() == "Dog already exists");
    }
}

void TestsService::testGetAllDogsUser() {
    Repository repo;
    UserService service = UserService{repo};
    assert(repo.getDogsRepo() == service.getAdoptionList());
    service.addDogService("Dachshund", "Pixie", 4, "https://idk");
    service.addDogService("Bichon", "Toto", 5, "https://idk2");
    service.addDogService("Pug", "Alfie", 2, "https://idk3");
    assert(repo.getDogsRepo() == service.getAdoptionList());
    assert(repo.getDogsRepo()[0] == service.getAdoptionList()[0]);
    assert(repo.getDogsRepo()[1] == service.getAdoptionList()[1]);
    assert(repo.getDogsRepo()[2] == service.getAdoptionList()[2]);
}

void TestsService::testGetFilteredDogs() {
    Repository repo = Repository();
    AdminService service = AdminService{repo};
    service.addDogService("Dachshund", "Pixie", 4, "https://idk");
    service.addDogService("Bichon", "Toto", 5, "https://idk2");
    service.addDogService("Pug", "Alfie", 2, "https://idk3");
    Dog dog = Dog{"Pug", "Alfie", 2, "https://idk3"};
    assert(service.getFilteredDogs("Pug", 10)[0] == dog);
}


