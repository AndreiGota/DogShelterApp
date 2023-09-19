#include "HTMLRepository.h"
#include "fstream"

void HtmlRepository::writeToHtmlFile() {
    std::ofstream fout(this->filename);
    if (!fout.is_open())
        return;

    fout << "<!DOCTYPE html>\n<html><head><title>Adoption List</title></head><body>\n";
    fout << "<table border=\"1\">\n";
    fout << "<tr><td>Breed</td><td>Name</td><td>Age</td><td>SiteLink</td></tr>\n";
    for (const Dog& dog: this->dogList) {
        fout << "<tr><td>" << dog.getBreed() << "</td>"
             << "<td>" << dog.getName() << "</td>"
             << "<td>" << std::to_string(dog.getAge()) << "</td>"
             << "<td><a href=\"" << dog.getSiteLink() << "\">"<<dog.getSiteLink() <<"</a></td>" << '\n';
    }
    fout << "</table></body></html>";
    fout.close();
}

HtmlRepository::HtmlRepository(string &filename): filename(filename) {}

void HtmlRepository::addDogRepo(const Dog &dog) {
    Repository::addDogRepo(dog);
    this->writeToHtmlFile();
}

string HtmlRepository::getDisplayCommand() {
    string command = "start chrome \"" + this->filename + "\"";
    return command;
}

HtmlRepository::~HtmlRepository() = default;

