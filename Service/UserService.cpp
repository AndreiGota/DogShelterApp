#include "UserService.h"

UserService::UserService(Repository &repo): repo(repo) {}

void UserService::addDogService(const string &breed, const string &name, int age, const string &siteLink) {
    dog_validator.validateBreed(breed);
    dog_validator.validateName(name);
    dog_validator.validateAge(age);
    dog_validator.validateSiteLink(siteLink);
    Dog dogToBeAdded(breed, name, age, siteLink);
    if (this->repo.searchByNameAndBreed(dogToBeAdded) == -1) {
        this->repo.addDogRepo(dogToBeAdded);
        undo_actions.push(std::make_unique<UndoRedoAdd>(this->repo, dogToBeAdded));
        while (!redo_actions.empty())
            redo_actions.pop();
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
    if (undo_actions.empty()) {
        throw ServiceException("Can't undo!\n");
    }
    auto action = std::move(undo_actions.top());
    undo_actions.pop();
    action->doUndo();
    redo_actions.push(std::move(action));
}

void UserService::redo() {
    if (redo_actions.empty()) {
        throw ServiceException("Can't redo!\n");
    }
    auto action = std::move(redo_actions.top());
    redo_actions.pop();
    action->doRedo();
    undo_actions.push(std::move(action));
}

UserService::~UserService() = default;
