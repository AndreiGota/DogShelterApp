#include "FileRepository.h"
#include "fstream"

void FileRepository::readFromFile() {
    std::ifstream file(this->filename);
    if (!file.is_open())
        return;

    Dog dog{};
    while (file >> dog)
        this->dogList.push_back(dog);

    file.close();
}

void FileRepository::writeToFile() {
    std::ofstream file(this->filename);
    if (!file.is_open())
        return;

    for (const auto& dog : this->dogList)
        file << dog;

    file.close();
}

FileRepository::FileRepository(string &filename): filename(filename) {
    this->readFromFile();
}

void FileRepository::addDogRepo(const Dog &dog) {
    Repository::addDogRepo(dog);
    this->writeToFile();
}

Dog FileRepository::deleteDogRepo(const Dog &dog) {
    Dog deletedDog = Repository::deleteDogRepo(dog);
    this->writeToFile();
    return deletedDog;
}

Dog FileRepository::updateDogRepo(const Dog &old_dog, const Dog &new_dog) {
    Dog updatedDog = Repository::updateDogRepo(old_dog, new_dog);
    this->writeToFile();
    return updatedDog;
}

FileRepository::~FileRepository() = default;
