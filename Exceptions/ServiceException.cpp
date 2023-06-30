#include "ServiceException.h"

ServiceException::ServiceException(const string &errorMessage): errorMessage(errorMessage) {}

const string &ServiceException::getErrorMessage() const {
    return this->errorMessage;
}

