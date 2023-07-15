#pragma once
#include "string"
#include "sstream"

using std::string;
using std::endl;

class Dog {
private:
    string breed;
    string name;
    int age;
    string siteLink;
public:
    //Default constructor
    Dog();

    //Constructor with parameters
    explicit Dog(const string& breed, const string& name, int age, const string& siteLink);

    //Copy constructor
    Dog(const Dog& anotherDog);

    //Assigment operator
    Dog& operator=(const Dog& anotherDog);

    //Equality operator
    bool operator==(const Dog& dogToBeComparedWith) const;

    //Destructor
    ~Dog();

    //Getters
    string getBreed() const;
    string getName() const;
    int getAge() const;
    string getSiteLink() const;

    //Setters
    void setBreed(string newBreed);
    void setName(string newName);
    void setAge(int newAge);
    void setSiteLink(string newSite);

    // Converts the Dog object to a string representation
    string toString() const;

    // Friend function to overload the input stream operator (>>)
    friend std::istream &operator>>(std::istream &is, Dog& dog);

    // Friend function to overload the output stream operator (<<)
    friend std::ostream &operator<<(std::ostream &os, const Dog& dog);
};