#include "AdministratorService.h"
#include <algorithm>

AdminService::AdminService(Repository &repo): repo(repo) {}

void AdminService::addDogService(const string &breed, const string &name, int age, const string &siteLink) {
    dog_validator.validateBreed(breed);
    dog_validator.validateName(name);
    dog_validator.validateAge(age);
    dog_validator.validateSiteLink(siteLink);
    Dog dogToBeAdded(breed, name, age, siteLink);
    if (this->repo.searchByNameAndBreed(dogToBeAdded) == -1)
        this->repo.addDogRepo(dogToBeAdded);
    else
        throw ServiceException("Dog with this breed and name already exists!\n");
    undo_actions.push_back(std::make_unique<UndoRedoAdd>(this->repo, dogToBeAdded));
    redo_actions.clear();
}

void AdminService::deleteDogService(const string &breed, const string &name) {
    dog_validator.validateBreed(breed);
    dog_validator.validateName(name);
    Dog dogToBeDeleted(breed, name, -1, "");
    int index = this->repo.searchByNameAndBreed(dogToBeDeleted);
    if (index != -1) {
        Dog actualDog = this->repo.getDogsRepo()[index];
        this->repo.deleteDogRepo(dogToBeDeleted);
        undo_actions.push_back(std::make_unique<UndoRedoDelete>(this->repo, actualDog));
    } else
        throw ServiceException("Dog does not exist!\n");
}

void AdminService::updateDogService(const string &oldBreed, const string &oldName, const string &newBreed,
                                    const string &newName, int newAge, const string &newSiteLink) {
    dog_validator.validateBreed(oldBreed);
    dog_validator.validateName(oldName);
    Dog dogToBeUpdated{oldBreed, oldName, -1, ""};
    int index = this->repo.searchByNameAndBreed(dogToBeUpdated);
    if (index != -1) {
        dog_validator.validateBreed(newBreed);
        dog_validator.validateName(newName);
        dog_validator.validateAge(newAge);
        dog_validator.validateSiteLink(newSiteLink);
        Dog oldDog = this->repo.getDogsRepo()[index];
        Dog newDog{newBreed, newName, newAge, newSiteLink};
        undo_actions.push_back(std::make_unique<UndoRedoUpdate>(this->repo, dogToBeUpdated, newDog));
        redo_actions.clear();
        this->repo.updateDogRepo(dogToBeUpdated, newDog);
    }
    else
        throw ServiceException("Dog does not exist!\n");
}

int AdminService::getLengthAllDogs() {
    return this->repo.getNrDogsRepo();
}

vector<Dog> AdminService::getAllDogs() {
    return this->repo.getDogsRepo();
}

vector<Dog> AdminService::getFilteredDogs(const string &breed, int age) {
    vector<Dog> filteredDogs;
    std::copy_if(this->repo.getDogsRepo().begin(), this->repo.getDogsRepo().end(), std::back_inserter(filteredDogs),
                 [&breed, &age](Dog& dog) {
        return (breed.empty() || dog.getBreed() == breed) && dog.getAge() < age;
    });
    return filteredDogs;
}

void AdminService::undo() {
    if (undo_actions.empty())
        throw ServiceException("Can't undo!\n");
    undo_actions[undo_actions.size() - 1]->doUndo();
    redo_actions.push_back(std::move(undo_actions[undo_actions.size() - 1]));
    undo_actions.pop_back();
}

void AdminService::redo() {
    if(redo_actions.empty())
        throw ServiceException("Can't redo!\n");
    redo_actions.back()->doRedo();
    undo_actions.push_back(std::move(redo_actions[redo_actions.size() - 1]));
    redo_actions.pop_back();
}

AdminService::~AdminService() = default;





