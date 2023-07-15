#include "ValidationException.h"

ValidationException::ValidationException(const string &errorMessage): errorMessage(errorMessage) {

}

const string &ValidationException::getErrorMessage() const {
    return this->errorMessage;
}

