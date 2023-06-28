#pragma once
#include "Repository.h"

class FileRepository: public Repository {
private:
    // Reference to the filename associated with the FileRepository
    string& filename;

    // Reads dog data from a file and populates the dogList vector
    void readFromFile();

    // Writes the dog data from the dogList vector to a file
    void writeToFile();
public:
    // Constructor for creating a new FileRepository object with a specified filename
    // Parameters:
    // - filename: A reference to the filename to be associated with the FileRepository object
    explicit FileRepository(string& filename);

    // Adds a Dog to the repository and updates the file
    // Parameters:
    // - dog: The Dog object to add to the repository
    void addDogRepo(const Dog& dog) override;

    // Deletes a Dog from the repository and updates the file
    // Parameters:
    // - dog: The Dog object to delete from the repository
    // Returns:
    // - The deleted Dog object
    Dog deleteDogRepo(const Dog& dog) override;

    // Updates a Dog in the repository and updates the file
    // Parameters:
    // - old_dog: The Dog object to be updated
    // - new_dog: The new Dog object that replaces the old Dog object
    // Returns:
    // - The updated Dog object
    Dog updateDogRepo(const Dog& old_dog, const Dog& new_dog) override;

    //Destructor
    ~FileRepository();
};
