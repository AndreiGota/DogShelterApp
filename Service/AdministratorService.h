#pragma once
#include "../Repository/Repository.h"
#include "UndoRedo.h"
#include "../Validation/DogValidator.h"
#include "../Exceptions/ServiceException.h"
#include "UndoRedo.h"
#include "memory"

using std::unique_ptr;

class AdminService {
private:
    Repository& repo;
    DogValidator dog_validator;
    vector<unique_ptr<UndoRedo>> undo_actions;
    vector<unique_ptr<UndoRedo>> redo_actions;
public:
    /**
     * Constructor for AdminService class.
     * @param repo The reference to the Repository object.
     */
    explicit AdminService(Repository& repo);

    /**
     * Adds a new dog to the repository.
     * @param breed The breed of the dog.
     * @param name The name of the dog.
     * @param age The age of the dog.
     * @param photoLink The link to the dog's photo.
     * @throws ServiceException if a dog with the same breed and name already exists.
     */
    void addDogService(const string& breed, const string& name, int age, const string& photoLink);

    /**
     * Deletes a dog from the repository.
     * @param breed The breed of the dog.
     * @param name The name of the dog.
     * @throws ServiceException if the dog does not exist.
     */
    void deleteDogService(const string& breed, const string& name);

    /**
     * Updates the information of a dog in the repository.
     * @param oldBreed The current breed of the dog.
     * @param oldName The current name of the dog.
     * @param newBreed The new breed of the dog.
     * @param newName The new name of the dog.
     * @param newAge The new age of the dog.
     * @param newPhotoLink The new link to the dog's photo.
     * @throws ServiceException if the dog does not exist.
     */
    void updateDogService(const string& oldBreed, const string& oldName, const string& newBreed, const string& newName, int newAge, const string& newPhotoLink);

    /**
     * Returns the total number of dogs in the repository.
     * @return The number of dogs in the repository.
     */
    int getLengthAllDogs();

    /**
     * Returns a vector containing all the dogs in the repository.
     * @return A vector of Dog objects representing all the dogs in the repository.
     */
    vector<Dog> getAllDogs();

    /**
     * Returns a vector containing the dogs that match the given breed and age criteria.
     * @param breed The breed of the dogs to filter by. If empty, all breeds are considered.
     * @param age The maximum age of the dogs to filter by. Dogs with an age less than this value are included.
     * @return A vector of Dog objects representing the filtered dogs.
     */
    vector<Dog> getFilteredDogs(const string& breed, int age);

    /**
     * Adds 10 pre-defined dog entries to the repository.
     */
    void add10Entries();

    /**
     * Undoes the last performed action (addition, deletion, or update) on the repository.
     * @throws ServiceException if there are no actions to undo.
     */
    void undo();

    /**
     * Redoes the last undone action (addition, deletion, or update) on the repository.
     * @throws ServiceException if there are no actions to redo.
     */
    void redo();

    /**
     * Destructor for AdminService class.
     */
    ~AdminService();
};
