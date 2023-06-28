#include "RepositoryException.h"

RepositoryException::RepositoryException(const string &errorMessage): errorMessage(errorMessage) {

}

const string& RepositoryException::getErrorMessage() const {
    return this->errorMessage;
}
