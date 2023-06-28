#pragma once
#include "../Domain/Dog.h"
#include "../Exceptions/RepositoryException.h"
#include "vector"

using std::vector;

class Repository {
protected:
    // A vector to store Dog objects
    vector<Dog> dogList;

public:
    // Constructor
    Repository();

    // Searches for a Dog in the repository by name and breed
    // Parameters:
    // - dog: The Dog object to search for
    // Returns:
    // - The index of the found Dog object in the repository, or -1 if not found
    int searchByNameAndBreed(const Dog& dog);

    // Adds a Dog to the repository
    // Parameters:
    // - dog: The Dog object to add to the repository
    virtual void addDogRepo(const Dog &dog);

    // Deletes a Dog from the repository
    // Parameters:
    // - dog: The Dog object to delete from the repository
    // Returns:
    // - The deleted Dog object
    virtual Dog deleteDogRepo(const Dog& dog);

    // Updates a Dog in the repository
    // Parameters:
    // - old_dog: The Dog object to be updated
    // - new_dog: The new Dog object that replaces the old Dog object
    // Returns:
    // - The updated Dog object
    virtual Dog updateDogRepo(const Dog& old_dog, const Dog& new_dog);

    // Retrieves the number of dogs in the repository
    // Returns:
    // - The number of dogs in the repository
    int getNrDogsRepo();

    // Retrieves a reference to the vector of dogs in the repository
    // Returns:
    // - A reference to the vector of dogs in the repository
    vector<Dog>& getDogsRepo();

    // Retrieves the display command for the repository
    // Returns:
    // - A string representing the display command for the repository
    virtual string getDisplayCommand();

    // Destructor
    ~Repository();
};
