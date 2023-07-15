#include "CSVRepository.h"
#include "fstream"

void CSVRepository::readFromCsvFile() {
    std::ifstream fin;
    fin.open(this->filename, std::ios::in);
    if (!fin.is_open())
        return;

    vector<string> result;
    string line, word, input;

    while (fin >> input) {
        getline(fin, line);
        std::stringstream ss(line);
        while (getline(ss, word, ','))
            result.push_back(word);
        if (result.size() != 4)
            return;
        int age = stoi(result[2]);
        Dog dog {result[0], result[1], age, result[3]};
        this->dogList.push_back(dog);
    }
    fin.close();
}

void CSVRepository::writeToCsvFile() {
    std::ofstream fout;
    fout.open(this->filename, std::ios::out);
    if (!fout.is_open())
        return;

    for (const auto& dog: this->dogList)
        fout << dog.getBreed() << ',' << dog.getName() << ',' << dog.getAge() << ',' << dog.getSiteLink() << '\n';
    fout.close();
}

CSVRepository::CSVRepository(string &filename): filename(filename) {}

void CSVRepository::addDogRepo(const Dog &dog) {
    Repository::addDogRepo(dog);
    this->writeToCsvFile();
}

string CSVRepository::getDisplayCommand() {
    string command = "notepad \"" + this->filename + "\"";
    return command;
}

CSVRepository::~CSVRepository() = default;
