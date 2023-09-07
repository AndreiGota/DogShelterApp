#include <QWidget>
#include <QShortcut>
#include <QTableView>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "../Service/AdministratorService.h"
#include "../Service/UserService.h"
#include "TableModel.h"

class DogShelterGUI: public QWidget {
Q_OBJECT

private:
    AdminService &adminService;
    UserService &userServiceCsv;
    UserService &userServiceHtml;
    int next_index = 0;
    bool filtered = false;
    bool csv = false;
    bool html = false;
    bool first = true;
    QWidget* adminWidget;
    QWidget* userWidget;
    QWidget* updateWidget;
    QListWidget* listDogs;
    QListWidget* listDogsUser;
    QLineEdit* breedEditAdmin;
    QLineEdit* nameEditAdmin;
    QLineEdit* ageEditAdmin;
    QTextEdit* siteLinkEditAdmin;
    QLineEdit* breedEditUpdate;
    QLineEdit* nameEditUpdate;
    QLineEdit* ageEditUpdate;
    QTextEdit* siteLinkEditUpdate;
    QLineEdit* breedEditUser;
    QLineEdit* nameEditUser;
    QLineEdit* ageEditUser;
    QTextEdit* siteLinkEditUser;
    QLineEdit* filterBreedEdit;
    QLineEdit* filterAgeEdit;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* undoButton;
    QPushButton* redoButton;
    QPushButton* adoptButton;
    QPushButton* nextButton;
    QPushButton* displayButton;
    QPushButton* filterButton;
    QPushButton* revertButton;
    QPushButton* buttonAdmin;
    QPushButton* buttonUser;
    QPushButton* exitApp;
    QPushButton* updateButtonUpdate;
    QPushButton* buttonCsv;
    QPushButton* buttonHtml;
    QWidget* chooseRepo;
    QTableView* adoptionTable = new QTableView;
    DogTableModel* model = new DogTableModel(userServiceCsv.getAdoptionList());
    QShortcut *shortcutUndo;
    QShortcut *shortcutRedo;
    QShortcut *shortcutUndoUser;
    QShortcut *shortcutRedoUser;
    QPushButton* undoButtonUser;
    QPushButton* redoButtonUser;

    void initGui();
    void connectSignalsAndSlots();
    void setInitialGuiState();
    void mainMode();
    void chooseMode(QVBoxLayout *mainLayout, QFont f);
    void chooseRepoType();
    void adminMode();
    void userMode();
    void updateWindow();
    void buttonsAdmin(QVBoxLayout *vLayout, const QFont &f);
    void dogDataAdmin(QVBoxLayout *vLayout, QFont &f);
    void dogDataUser(QVBoxLayout *pLayout, QFont font);
    void buttonsUser(QVBoxLayout *pLayout, QFont font);
    void filterUser(QVBoxLayout *pLayout, QFont font);
    void populateDogList();
    void listItemChangedAdmin();
    void listItemChangedUserFilter();
    void addButtonHandler();
    void deleteButtonHandler();
    int getSelectedIndexAdmin();
    void dogDataUpdate(QVBoxLayout *vLayout, QFont &f);
    void buttonsUpdate(QVBoxLayout *vLayout, const QFont &f);
    void updateButtonHandler();
    void undoButtonHandler();
    void redoButtonHandler();
    void undoButtonHandlerUser();
    void redoButtonHandlerUser();
    void listItemChangedUser();
    int getSelectedIndexUser();
    void nextButtonHandler();
    void adoptButtonHandler();
    void populateAdoptionList();
    void displayButtonHandler();
    void revertButtonHandler();
    void filterButtonHandler();

signals:

    void listUpdatedSignal();
    void listUpdatedAdoptionSignal();
    void addSignal(const string& breed, const string& name, int age, const string& siteLink);
    void deleteSignal(const string& breed, const string& name);
    void updateSignal(const string& old_breed, const string& old_name, const string& breed, const string& name, int age, const string& siteLink);
    void adoptSignal(const string&, const string&, int, const string&);

public:

    DogShelterGUI(AdminService &serviceAdmin, UserService &serviceUserCsv, UserService &serviceUserHtml) :
    adminService {serviceAdmin}, userServiceCsv {serviceUserCsv}, userServiceHtml {serviceUserHtml}{
        this->initGui();
        this->connectSignalsAndSlots();
        this->setInitialGuiState();
    }

public slots:
    void add(const string &breed, const string &name, int age, const string &siteLink);
    void del(const string &breed, const string &name);
    void update(const string &old_breed, const string &old_name, const string &breed, const string &name, int age, const string &siteLink);
    void adopt(const string& breed, const string& name, int age, const string& siteLink);
    void undo();
    void redo();
    void undoUser();
    void redoUser();
};