#pragma once
#include "Repository.h"

class FileRepository: public Repository {
private:
    string& filename;
    void readFromFile();
    void writeToFile();
public:
    explicit FileRepository(string& filename);
    void addDogRepo(const Dog& dog) override;
    Dog deleteDogRepo(const Dog& dog) override;
    Dog updateDogRepo(const Dog& old_dog, const Dog& new_dog) override;
    ~FileRepository();
};