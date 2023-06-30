#include "AdministratorService.h"
#include <algorithm>

AdminService::AdminService(Repository &repo): repo(repo) {}

void AdminService::addDogService(const string &breed, const string &name, int age, const string &photoLink) {
    dog_validator.validateBreed(breed);
    dog_validator.validateName(name);
    dog_validator.validateAge(age);
    dog_validator.validatePhotoLink(photoLink);
    Dog dogToBeAdded(breed, name, age, photoLink);
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
                                    const string &newName, int newAge, const string &newPhotoLink) {
    dog_validator.validateBreed(oldBreed);
    dog_validator.validateName(oldName);
    Dog dogToBeUpdated{oldBreed, oldName, -1, ""};
    int index = this->repo.searchByNameAndBreed(dogToBeUpdated);
    if (index != -1) {
        dog_validator.validateBreed(newBreed);
        dog_validator.validateName(newName);
        dog_validator.validateAge(newAge);
        dog_validator.validatePhotoLink(newPhotoLink);
        Dog oldDog = this->repo.getDogsRepo()[index];
        Dog newDog{newBreed, newName, newAge, newPhotoLink};
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

void AdminService::add10Entries() {
    this->addDogService("Dachshund", "Pixie", 4, "https://dogtime.com/assets/uploads/2011/01/file_23020_dachshund-dog-breed.jpg");
    this->addDogService("Bichon", "Toto", 5, "https://rasedecaini.ro/wp-content/uploads/2019/05/rasa-bichon-maltez.jpg");
    this->addDogService("Pug", "Toby", 2, "https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/12225358/Pug-On-White-01.jpg");
    this->addDogService("German Shepherd", "Rex", 7, "https://images.saymedia-content.com/.image/t_share/MTk2NzIzMTQ2NzMxMTAzMjUw/11-dogs-like-german-shepherd.png");
    this->addDogService("Corgi", "Donna", 6, "https://dogtime.com/assets/uploads/gallery/pembroke-welsh-corgi-dog-breed-pictures/prance-8.jpg");
    this->addDogService("Corgi", "Cynthia", 1, "https://i.pinimg.com/originals/51/03/d8/5103d8dcf3285e7e73b142049d252558.jpg");
    this->addDogService("Labrador", "Charlie", 3, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRqtevyTOTKqvE9uNtGEMxfEUMJglnnBT0iVg&usqp=CAU");
    this->addDogService("Husky", "Alfie", 7, "https://highlandcanine.com/wp-content/uploads/2021/01/siberian-husky-in-the-snow.jpg");
    this->addDogService("Pug", "Ben", 1, "https://i.pinimg.com/originals/21/cc/0e/21cc0ef668b35d78ff3e7160fd556186.jpg");
    this->addDogService("Pomeranian", "Puffy", 1, "https://www.animalepierdute.ro/wp-content/uploads/2019/09/pomeranian-rase-de-caini.jpg");
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





