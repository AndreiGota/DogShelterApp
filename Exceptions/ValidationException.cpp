//
// Created by Andrei on 6/28/2023.
//
#include "ValidationException.h"

ValidationException::ValidationException(const string &errorMessage): errorMessage(errorMessage) {

}

const string &ValidationException::getErrorMessage() const {
    return this->errorMessage;
}

