#pragma once
#include "string"
#include "exception"

using std::string;

class RepositoryException: public std::exception {
private:
    string errorMessage;
public:
    explicit RepositoryException(const string& errorMessage);
    const string& getErrorMessage() const;
};
