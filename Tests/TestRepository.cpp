#include "TestRepository.h"
#include <cassert>

void TestsRepository::runRepositoryTests() {
    this->testAddDogRepo();
    this->testDeleteDogRepo();
    this->testGetDogsRepo();
    this->testGetNrDogsRepo();
    this->testSearchByNameAndBreed();
    this->testGetNrDogsRepo();
}

void TestsRepository::testSearchByNameAndBreed() {
    Repository repo;
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    assert(repo.getNrDogsRepo() == 0);
    repo.addDogRepo(dog1);
    assert(repo.getNrDogsRepo() == 1);
    Dog dogToSearchFor{"Dachshund", "Pixie", -1, ""};
    int findDogPos = repo.searchByNameAndBreed(dogToSearchFor);
    assert(repo.getDogsRepo()[findDogPos] == dog1);
    assert(findDogPos == 0);
    Dog dogToSearchForNonexistent{"Kitty", "Cat", -1, ""};
    int findNonexistentDogPos = repo.searchByNameAndBreed(dogToSearchForNonexistent);
    assert(findNonexistentDogPos == -1);
}

void TestsRepository::testAddDogRepo() {
    Repository repo;
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    assert(repo.getNrDogsRepo() == 0);
    repo.addDogRepo(dog1);
    assert(repo.getNrDogsRepo() == 1);
    assert(repo.getDogsRepo()[0] == dog1);
    try{
        repo.addDogRepo(dog1);
    }
    catch(const RepositoryException &re){
        assert(re.getErrorMessage() == "Dog already exists!");
    }
}

void TestsRepository::testDeleteDogRepo() {
    Repository repo;
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog dog2{"Bichon", "Toto", 5, "https://idk2"};
    Dog dog3{"Pug", "Alfie", 2, "https://idk3"};
    assert(repo.getNrDogsRepo() == 0);
    repo.addDogRepo(dog1);
    repo.addDogRepo(dog2);
    repo.addDogRepo(dog3);
    assert(repo.getNrDogsRepo() == 3);
    repo.deleteDogRepo(dog1);
    assert(repo.getNrDogsRepo() == 2);
    assert(repo.getDogsRepo()[0] == dog2);
    repo.deleteDogRepo(dog3);
    assert(repo.getNrDogsRepo() == 1);
    assert(repo.getDogsRepo()[0] == dog2);
    repo.deleteDogRepo(dog2);
    assert(repo.getNrDogsRepo() == 0);
    try{
        repo.deleteDogRepo(dog1);
    }
    catch(const RepositoryException &re){
        assert(re.getErrorMessage() == "Dog doesn't exist!");
    }
}

void TestsRepository::testUpdateDogRepo() {
    Repository repo;
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog dog2{"Bichon", "Toto", 5, "https://idk2"};
    Dog dog3{"Pug", "Alfie", 2, "https://idk3"};
    assert(repo.getNrDogsRepo() == 0);
    repo.addDogRepo(dog1);
    assert(repo.getNrDogsRepo() == 1);
    assert(repo.getDogsRepo()[0] == dog1);
    assert(repo.getDogsRepo()[0].getBreed() == "Dachshund");
    assert(repo.getDogsRepo()[0].getName() == "Pixie");
    assert(repo.getDogsRepo()[0].getAge() == 4);
    assert(repo.getDogsRepo()[0].getSiteLink() == "https://idk");
    repo.updateDogRepo(dog1, dog2);
    assert(repo.getDogsRepo()[0].getBreed() == "Bichon");
    assert(repo.getDogsRepo()[0].getName() == "Toto");
    assert(repo.getDogsRepo()[0].getAge() == 5);
    assert(repo.getDogsRepo()[0].getSiteLink() == "https://idk2");
    try{
        repo.updateDogRepo(dog3, dog1);
    }
    catch(const RepositoryException &re){
        assert(re.getErrorMessage() == "Dog doesn't exist!");
    }
}

void TestsRepository::testGetNrDogsRepo() {
    Repository repo;
    assert(repo.getNrDogsRepo() == 0);
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    repo.addDogRepo(dog1);
    assert(repo.getNrDogsRepo() == 1);
    repo.deleteDogRepo(dog1);
    assert(repo.getNrDogsRepo() == 0);
}

void TestsRepository::testGetDogsRepo() {
    Repository repo;
    Dog dog1{"Dachshund", "Pixie", 4, "https://idk"};
    Dog dog2{"Bichon", "Toto", 5, "https://idk2"};
    Dog dog3{"Pug", "Alfie", 2, "https://idk3"};
    assert(repo.getNrDogsRepo() == 0);
    repo.addDogRepo(dog1);
    repo.addDogRepo(dog2);
    repo.addDogRepo(dog3);
    assert(repo.getNrDogsRepo() == 3);
    int findDog1Pos = repo.searchByNameAndBreed(dog1);
    int findDog2Pos = repo.searchByNameAndBreed(dog2);
    int findDog3Pos = repo.searchByNameAndBreed(dog3);
    assert(repo.getDogsRepo()[findDog1Pos] == dog1);
    assert(repo.getDogsRepo()[findDog2Pos] == dog2);
    assert(repo.getDogsRepo()[findDog3Pos] == dog3);
}

