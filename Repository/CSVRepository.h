#pragma once
#include "Repository.h"

class CSVRepository : public Repository {
private:
    // The filename associated with the CsvRepository
    string& filename;

    // Reads dog data from a CSV file and populates the dogList vector
    void readFromCsvFile();

    // Writes the dog data from the dogList vector to a CSV file
    void writeToCsvFile();
public:
    // Constructor for creating a new CsvRepository object with a specified filename
    // Parameters:
    // - fileName: A reference to the filename to be associated with the CsvRepository object
    explicit CSVRepository(string &filename);

    // Adds a dog to the repository and updates the CSV file
    // Parameters:
    // - dog: The element (in this case, a Dog object) to add to the repository
    void addDogRepo(const Dog& dog) override;

    // Retrieves the display command specific to the CsvRepository
    // Returns:
    // - A string representing the display command for the CsvRepository
    string getDisplayCommand() override;

    // Destructor
    ~CSVRepository();
};