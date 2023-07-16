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
     * @param siteLink The link to the dog's siteLink.
     * @throws ServiceException if a dog with the same breed and name already exists.
     */
    void addDogService(const string& breed, const string& name, int age, const string& siteLink);

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
     * @param newSiteLink The new link to the dog's siteLink.
     * @throws ServiceException if the dog does not exist.
     */
    void updateDogService(const string& oldBreed, const string& oldName, const string& newBreed, const string& newName, int newAge, const string& newSiteLink);

    /**
     * Returns the total number of adoptedDogs in the repository.
     * @return The number of adoptedDogs in the repository.
     */
    int getLengthAllDogs();

    /**
     * Returns a vector containing all the adoptedDogs in the repository.
     * @return A vector of Dog objects representing all the adoptedDogs in the repository.
     */
    vector<Dog> getAllDogs();

    /**
     * Returns a vector containing the adoptedDogs that match the given breed and age criteria.
     * @param breed The breed of the adoptedDogs to filter by. If empty, all breeds are considered.
     * @param age The maximum age of the adoptedDogs to filter by. Dogs with an age less than this value are included.
     * @return A vector of Dog objects representing the filtered adoptedDogs.
     */
    vector<Dog> getFilteredDogs(const string& breed, int age);

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
