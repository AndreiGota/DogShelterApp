#pragma once
#include "../Service/AdministratorService.h"
#include "../Exceptions/ServiceException.h"
#include "../Exceptions/ValidationException.h"
#include "../Service/UserService.h"

class TestsService {
private:
    void testGetAllDogsAdministrator();
    void testGetLengthAllDogsAdministrator();
    void testAddDogAdministrator();
    void testDeleteDogAdministrator();
    void testUpdateDogAdministrator();
    void testAddDogUser();
    void testGetAllDogsUser();
    void testGetFilteredDogs();
public:
    void runServiceTests();
};