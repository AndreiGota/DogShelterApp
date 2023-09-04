#pragma once
#include "../Repository/Repository.h"

class UndoRedo {
public:
    virtual void doUndo() = 0;
    virtual void doRedo() = 0;
    virtual ~UndoRedo() = default;
};

class UndoRedoAdd: public UndoRedo {
private:
    Dog dog;
    Repository& repository;
public:
    UndoRedoAdd(Repository& repo, const Dog& dog): repository(repo), dog(dog) {}

    void doUndo() override {
        repository.deleteDogRepo(dog);
    }

    void doRedo() override {
        repository.addDogRepo(dog);
    }
};

class UndoRedoUpdate: public UndoRedo {
private:
    Dog old_dog;
    Dog new_dog;
    Repository& repository;
public:
    UndoRedoUpdate(Repository& repo, const Dog& old_dog, const Dog& new_dog):
    repository(repo), old_dog(old_dog), new_dog(new_dog) {}

    void doUndo() override {
        repository.updateDogRepo(new_dog, old_dog);
    }

    void doRedo() override {
        repository.updateDogRepo(old_dog, new_dog);
    }
};

class UndoRedoDelete: public UndoRedo {
private:
    Repository& repository;
    Dog dog;
public:
    UndoRedoDelete(Repository& repo, const Dog& dog): repository(repo), dog(dog) {}

    void doUndo() override {
        repository.addDogRepo(dog);
    }

    void doRedo() override {
        repository.deleteDogRepo(dog);
    }
};