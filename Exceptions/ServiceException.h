#pragma once
#include "string"
#include "exception"

using std::string;

class ServiceException: public std::exception {
private:
    string errorMessage;
public:
    explicit ServiceException(const string& errorMessage);
    const string& getErrorMessage() const;
};