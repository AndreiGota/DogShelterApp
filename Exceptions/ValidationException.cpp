#include "ValidationException.h"

ValidationException::ValidationException(const std::string& errorMessage)
        : errorMessage(errorMessage) {}

const string &ValidationException::getErrorMessage() const {
    return this->errorMessage;
}

