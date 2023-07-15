#include <QApplication>
#include <QPushButton>
//#include "Presentation/GUI.h"
#include "Repository/FileRepository.h"
#include "Repository/HTMLRepository.h"
#include "Repository/CSVRepository.h"
#include "Tests/Tests.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    string adminFile, userCsvFile, userHtmlFile;
    adminFile = "dogs.txt";
    userCsvFile = "dogs.csv";
    userHtmlFile = "dogs.html";
    Tests test{};
    test.runAllTests();

//    FileRepository repoAdmin(adminFile);
//    AdminService serviceAdmin{repoAdmin};
//    CSVRepository repoUserCsv{userCsvFile};
//    HtmlRepository repoUserHtml{userHtmlFile};

    //UserService serviceUserCsv{repoUserCsv};
    //UserService serviceUserHtml{repoUserHtml};
    //DogShelterGUI gui {serviceAdmin, serviceUserCsv, serviceUserHtml};
    //gui.show();
    return QApplication::exec();
}
