#include "../Repository/Repository.h"
#include "../Exceptions/RepositoryException.h"

class TestsRepository{
private:
    void testSearchByNameAndBreed();
    void testAddDogRepo();
    void testDeleteDogRepo();
    void testUpdateDogRepo();
    void testGetNrDogsRepo();
    void testGetDogsRepo();
public:
    void runRepositoryTests();
};

