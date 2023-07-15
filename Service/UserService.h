#pragma once
#include "../Repository/Repository.h"
#include "UndoRedo.h"
#include "../Validation/DogValidator.h"
#include "../Exceptions/ServiceException.h"
#include "UndoRedo.h"
#include "memory"

using std::unique_ptr;

class UserService {
private:
    Repository& repo;
    DogValidator dog_validator;
    vector<unique_ptr<UndoRedo>> undo_actions;
    vector<unique_ptr<UndoRedo>> redo_actions;
public:
    /**
     * Constructor for UserService class.
     * @param repo The reference to the Repository object.
     */
    explicit UserService(Repository& repo);

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
     * Returns the total number of dogs in the repository.
     * @return The number of dogs in the repository.
     */
    int getLengthAllDogs();

    /**
     * Retrieves the display command from the repository
     * @return The display command as a string
     */
    string getDisplayCommand();

    /**
     * Retrieves the list of dogs available for adoption from the repository
     * @return A vector of Dog objects representing the adoption list
     */
    vector<Dog> getAdoptionList();

    /**
     * Undoes the last performed action
     * @throws ServiceException if there are no actions to undo.
     */
    void undo();

    /**
     * Redoes the last undone action
     * @throws ServiceException if there are no actions to redo.
     */
    void redo();

    /**
     * Destructor for UserService class.
     */
    ~UserService();
};

