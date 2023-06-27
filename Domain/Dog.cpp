#include "Dog.h"

Dog::Dog(): breed(""), name(""), age(-1), photo("") {

}

Dog::Dog(const string &breed, const string &name, int age, const string &photo): breed(breed), name(name), age(age), photo(photo) {

}

Dog::Dog(const Dog &anotherDog): breed(anotherDog.breed), name(anotherDog.name), age(anotherDog.age), photo(anotherDog.photo) {

}

Dog &Dog::operator=(const Dog &anotherDog) {
    this->breed = anotherDog.breed;
    this->name = anotherDog.name;
    this->age = anotherDog.age;
    this->photo = anotherDog.photo;
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

string Dog::getPhoto() const{
    return this->photo;
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

void Dog::setPhoto(std::string newPhoto) {
    this->photo = newPhoto;
}

std::string Dog::toString() const {
    std::stringstream buffer;
    buffer << "Dog \n\t breed: " << this->breed << endl << "\t name: " << this->name << endl <<
           "\t age: " << this->age << endl << "\t photo: " << this->photo << endl;
    return buffer.str();
}

std::istream &operator>>(std::istream &is, Dog &dog) {
    is >> dog.breed >> dog.name >> dog.age >> dog.photo;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Dog &dog) {
    os << dog.getBreed() << endl;
    os << dog.getName() << endl;
    os << dog.getAge() << endl;
    os << dog.getPhoto() << endl;
    return os;
}

