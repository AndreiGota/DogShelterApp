#include "UserService.h"

UserService::UserService(Repository &repo): repo(repo) {}

void UserService::addDogService(const string &breed, const string &name, int age, const string &photoLink) {
    dog_validator.validateBreed(breed);
    dog_validator.validateName(name);
    dog_validator.validateAge(age);
    dog_validator.validatePhotoLink(photoLink);
    Dog dogToBeAdded(breed, name, age, photoLink);
    if (this->repo.searchByNameAndBreed(dogToBeAdded) == -1) {
        this->repo.addDogRepo(dogToBeAdded);
        undo_actions.push_back(std::make_unique<UndoRedoAdd>(this->repo, dogToBeAdded));
        redo_actions.clear();
    } else
        throw ServiceException("Dog already exists");
}

int UserService::getLengthAllDogs() {
    return this->repo.getNrDogsRepo();
}

string UserService::getDisplayCommand() {
    return this->repo.getDisplayCommand();
}

vector<Dog> UserService::getAdoptionList() {
    return this->repo.getDogsRepo();
}

void UserService::undo() {
    if(undo_actions.empty())
        throw ServiceException("Can't undo!\n");
    undo_actions[undo_actions.size() - 1]->doUndo();
    redo_actions.push_back(std::move(undo_actions[undo_actions.size() - 1]));
    undo_actions.pop_back();
}

void UserService::redo() {
    if(redo_actions.empty())
        throw ServiceException("Can't redo!\n");
    redo_actions.back()->doRedo();
    undo_actions.push_back(std::move(redo_actions[redo_actions.size() - 1]));
    redo_actions.pop_back();
}

UserService::~UserService() = default;
