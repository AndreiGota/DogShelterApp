#include <QApplication>
#include "Repository/FileRepository.h"
#include "Repository/HTMLRepository.h"
#include "Repository/CSVRepository.h"
#include "Tests/Tests.h"
#include "Service/AdministratorService.h"
#include "Service/UserService.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    string adminFile, userCsvFile, userHtmlFile;
    adminFile = "C:\\Users\\Andrei\\Downloads\\dogs.txt";
    userCsvFile = "C:\\Users\\Andrei\\Downloads\\dogs.csv";
    userHtmlFile = "C:\\Users\\Andrei\\Downloads\\dogs.html";
    Tests test{};
    test.runAllTests();
}
