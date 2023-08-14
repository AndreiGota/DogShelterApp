#include <QApplication>
#include "Repository/FileRepository.h"
#include "Repository/HTMLRepository.h"
#include "Repository/CSVRepository.h"
#include "Tests/Tests.h"
#include "Service/AdministratorService.h"
#include "Service/UserService.h"
#include "Presentation/GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    string adminFile, userCsvFile, userHtmlFile;
    adminFile = "dogs.txt";
    userCsvFile = "dogs.csv";
    userHtmlFile = "dogs.html";
    Tests test{};
    test.runAllTests();
    FileRepository repoAdmin(adminFile);
    AdminService serviceAdmin{repoAdmin};
    CSVRepository repoUserCsv{userCsvFile};
    HtmlRepository repoUserHtml{userHtmlFile};
    UserService serviceUserCsv{repoUserCsv};
    UserService serviceUserHtml{repoUserHtml};
    DogShelterGUI gui {serviceAdmin, serviceUserCsv, serviceUserHtml};
    gui.setWindowState(Qt::WindowMaximized);
    gui.show();
    return QApplication::exec();
}
