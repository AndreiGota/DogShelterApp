#include "Repository.h"
#include "algorithm"

Repository::Repository() {
    this->dogList = vector<Dog>();
}

int Repository::searchByNameAndBreed(const Dog &dog) {
    auto it = std::find(this->dogList.begin(), this->dogList.end(), dog);
    if (it == this->dogList.end())
        return -1;
    return std::distance(this->dogList.begin(), it);
}

void Repository::addDogRepo(const Dog &dog) {
    int positionOfDog = this->searchByNameAndBreed(dog);
    if (positionOfDog != -1)
        throw RepositoryException("Dog already exists!");
    this->dogList.push_back(dog);
}

Dog Repository::deleteDogRepo(const Dog &dog) {
    int positionOfDog = this->searchByNameAndBreed(dog);
    if (positionOfDog == -1)
        throw RepositoryException("Dog doesn't exist!");
    Dog deletedDog = this->dogList[positionOfDog];
    this->dogList.erase(this->dogList.begin() + positionOfDog);
    return deletedDog;
}

Dog Repository::updateDogRepo(const Dog &old_dog, const Dog &new_dog) {
    int positionOfDog = this->searchByNameAndBreed(old_dog);
    if (positionOfDog == -1)
        throw RepositoryException("Dog doesn't exist!");
    Dog oldDog = this->dogList[positionOfDog];
    this->dogList[positionOfDog].setBreed(new_dog.getBreed());
    this->dogList[positionOfDog].setName(new_dog.getName());
    this->dogList[positionOfDog].setAge(new_dog.getAge());
    this->dogList[positionOfDog].setPhotoLink(new_dog.getPhotoLink());
    return oldDog;
}

int Repository::getNrDogsRepo() {
    return this->dogList.size();
}

vector<Dog> &Repository::getDogsRepo() {
    return this->dogList;
}

string Repository::getDisplayCommand() {
    return "";
}

Repository::~Repository() = default;
