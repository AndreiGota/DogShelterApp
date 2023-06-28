#pragma once
#include "Repository.h"

class HtmlRepository : public Repository  {
private:
    // The filename associated with the HtmlRepository
    string &filename;

    // Writes the dog data from the dogList vector to a HTML file
    void writeToHtmlFile();
public:
    // Constructor for creating a new HtmlRepository object with a specified filename
    // Parameters:
    // - fileName: A reference to the filename to be associated with the HtmlRepository object
    explicit HtmlRepository(string &filename);

    // Adds a dog to the repository and updates the HTML file
    // Parameters:
    // - dog: The element (in this case, a Dog object) to add to the repository
    void addDogRepo(const Dog& dog) override;

    // Retrieves the display command specific to the HTMLRepository
    // Returns:
    // - A string representing the display command for the HTMLRepository
    string getDisplayCommand() override;

    //Destructor
    ~HtmlRepository();
};
