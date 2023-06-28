#pragma once
#include "exception"
#include "string"

using std::string;

class ValidationException : public std::exception{
private:
    string errorMessage;
public:
    explicit ValidationException(const string &errorMessage);
    const string &getErrorMessage() const;
};