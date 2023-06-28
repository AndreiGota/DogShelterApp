#include "Dog.h"

Dog::Dog(): breed(""), name(""), age(-1), photoLink("") {

}

Dog::Dog(const string &breed, const string &name, int age, const string &photoLink): breed(breed), name(name), age(age), photoLink(photoLink) {

}

Dog::Dog(const Dog &anotherDog): breed(anotherDog.breed), name(anotherDog.name), age(anotherDog.age), photoLink(anotherDog.photoLink) {

}

Dog &Dog::operator=(const Dog &anotherDog) {
    this->breed = anotherDog.breed;
    this->name = anotherDog.name;
    this->age = anotherDog.age;
    this->photoLink = anotherDog.photoLink;
    return *this;
}

bool Dog::operator==(const Dog &dogToBeComparedWith) const {
    return this->breed == dogToBeComparedWith.breed && this->name == dogToBeComparedWith.name;
}

Dog::~Dog() = default;

string Dog::getBreed() const {
    return this->breed;
}

string Dog::getName() const {
    return this->name;
}

int Dog::getAge() const {
    return this->age;
}

string Dog::getPhotoLink() const{
    return this->photoLink;
}

void Dog::setBreed(std::string newBreed) {
    this->breed = newBreed;
}

void Dog::setName(std::string newName) {
    this->name = newName;
}

void Dog::setAge(int newAge) {
    this->age = newAge;
}

void Dog::setPhotoLink(std::string newPhotoLink) {
    this->photoLink = newPhotoLink;
}

std::string Dog::toString() const {
    std::stringstream buffer;
    buffer << "Dog \n\t breed: " << this->breed << endl << "\t name: " << this->name << endl <<
           "\t age: " << this->age << endl << "\t photoLink: " << this->photoLink << endl;
    return buffer.str();
}

std::istream &operator>>(std::istream &is, Dog &dog) {
    is >> dog.breed >> dog.name >> dog.age >> dog.photoLink;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Dog &dog) {
    os << dog.getBreed() << endl;
    os << dog.getName() << endl;
    os << dog.getAge() << endl;
    os << dog.getPhotoLink() << endl;
    return os;
}

