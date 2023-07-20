#include "GUI.h"
#include "PictureDelegate.h"
#include <QMessageBox>
#include <QFormLayout>
#include <QLabel>
#include <QHeaderView>

void DogShelterGUI::initGui() {
    mainMode();
    adminMode();
    userMode();
    chooseRepoType();
}

void DogShelterGUI::setInitialGuiState() {
    this->populateDogList();
}

void DogShelterGUI::mainMode() {
    QFont f{"Times New Roman", 12};
    ///MAIN layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    setLayout(mainLayout);
    ///Choose MODE buttons
    chooseMode(mainLayout, f);
}

void DogShelterGUI::chooseMode(QVBoxLayout *mainLayout, QFont f) {
    QWidget* chooseMode = new QWidget{};
    QHBoxLayout* layoutMode = new QHBoxLayout{};
    buttonAdmin = new QPushButton{"Admin Mode"};
    buttonUser = new QPushButton{"User Mode"};
    buttonAdmin->setFont(f);
    buttonUser->setFont(f);
    layoutMode->addWidget(buttonAdmin);
    layoutMode->addWidget(buttonUser);
    chooseMode->setLayout(layoutMode);
    mainLayout->addWidget(chooseMode);
}

void DogShelterGUI::adminMode() {
    /// big layout
    this->adminWidget = new QWidget{};
    QHBoxLayout* layoutAdmin = new QHBoxLayout{};

    /// left side - just the list
    listDogs = new QListWidget{};
    // set the selection model
    listDogs->setSelectionMode(QAbstractItemView::SingleSelection);

    /// right side - dog information + buttons
    QWidget* rightSide = new QWidget{};
    QVBoxLayout* vLayout = new QVBoxLayout{rightSide};
    QFont f{"Times New Roman", 12};
    // dog information
    dogDataAdmin(vLayout, f);
    // buttons
    buttonsAdmin(vLayout, f);

    /// add everything to the big layout
    layoutAdmin->addWidget(listDogs);
    layoutAdmin->addWidget(rightSide);
    this->adminWidget->setLayout(layoutAdmin);

    shortcutUndo = new QShortcut(QKeySequence("Ctrl+Z"), adminWidget);
    QObject::connect(shortcutUndo, SIGNAL(activated()), this, SLOT(undo()));
    shortcutRedo = new QShortcut(QKeySequence("Ctrl+Y"), adminWidget);
    QObject::connect(shortcutRedo, SIGNAL(activated()), this, SLOT(redo()));

    updateWindow();
}

void DogShelterGUI::dogDataAdmin(QVBoxLayout *vLayout, QFont &f) {
    QWidget *dogData = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{dogData};
    breedEditAdmin = new QLineEdit{};
    nameEditAdmin = new QLineEdit{};
    ageEditAdmin = new QLineEdit{};
    siteLinkEditAdmin = new QTextEdit{};
    QLabel* breedLabel = new QLabel{"&Breed:" };
    breedLabel->setBuddy(breedEditAdmin);
    QLabel* nameLabel = new QLabel{"&Name:" };
    nameLabel->setBuddy(nameEditAdmin);
    QLabel* ageLabel = new QLabel{ "&Age: " };
    ageLabel->setBuddy(ageEditAdmin);
    QLabel* siteLinkLabel = new QLabel{ "&SiteLink:" };
    siteLinkLabel->setBuddy(siteLinkEditAdmin);
    breedLabel->setFont(f);
    nameLabel->setFont(f);
    ageLabel->setFont(f);
    siteLinkLabel->setFont(f);
    breedEditAdmin->setFont(f);
    nameEditAdmin->setFont(f);
    ageEditAdmin->setFont(f);
    siteLinkEditAdmin->setFont(f);
    formLayout->addRow(breedLabel, breedEditAdmin);
    formLayout->addRow(nameLabel, nameEditAdmin);
    formLayout->addRow(ageLabel, ageEditAdmin);
    formLayout->addRow(siteLinkLabel, siteLinkEditAdmin);
    vLayout->addWidget(dogData);
}

void DogShelterGUI::buttonsAdmin(QVBoxLayout *vLayout, const QFont &f) {
    QWidget* addDelButtons = new QWidget{};
    QHBoxLayout* hLayout = new QHBoxLayout{addDelButtons};
    addButton = new QPushButton("Add");
    addButton->setFont(f);
    deleteButton = new QPushButton("Delete");
    deleteButton->setFont(f);
    hLayout->addWidget(addButton);
    hLayout->addWidget(deleteButton);
    vLayout->addWidget(addDelButtons);

    QWidget* updUndButtons = new QWidget{};
    QHBoxLayout* hLayout1 = new QHBoxLayout{updUndButtons};
    updateButton = new QPushButton("Update");
    updateButton->setFont(f);
    undoButton = new QPushButton("Undo");
    undoButton->setFont(f);
    redoButton = new QPushButton("Redo");
    redoButton->setFont(f);
    hLayout1->addWidget(updateButton);
    hLayout1->addWidget(undoButton);
    hLayout1->addWidget(redoButton);
    vLayout->addWidget(updUndButtons);
}

void DogShelterGUI::updateWindow() {
    /// big layout
    this->updateWidget = new QWidget{};
    QHBoxLayout* layoutUpdate = new QHBoxLayout{};

    QWidget* rightSideUpdate = new QWidget{};
    QVBoxLayout* vLayout = new QVBoxLayout{rightSideUpdate};
    QFont f{"Times New Roman", 12};
    // dog information
    dogDataUpdate(vLayout, f);
    // buttons
    buttonsUpdate(vLayout, f);

    /// add everything to the big layout
    layoutUpdate->addWidget(rightSideUpdate);
    this->updateWidget->setLayout(layoutUpdate);
}

void DogShelterGUI::dogDataUpdate(QVBoxLayout *vLayout, QFont &f) {
    QWidget *dogData = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{dogData};
    breedEditUpdate = new QLineEdit{};
    nameEditUpdate = new QLineEdit{};
    ageEditUpdate = new QLineEdit{};
    siteLinkEditUpdate = new QTextEdit{};
    QLabel* breedLabel = new QLabel{"&Breed:" };
    breedLabel->setBuddy(breedEditUpdate);
    QLabel* nameLabel = new QLabel{"&Name:" };
    nameLabel->setBuddy(nameEditUpdate);
    QLabel* ageLabel = new QLabel{ "&Age: " };
    ageLabel->setBuddy(ageEditUpdate);
    QLabel* siteLinkLabel = new QLabel{ "&SiteLink:" };
    siteLinkLabel->setBuddy(siteLinkEditUpdate);
    breedLabel->setFont(f);
    nameLabel->setFont(f);
    ageLabel->setFont(f);
    siteLinkLabel->setFont(f);
    breedEditUpdate->setFont(f);
    nameEditUpdate->setFont(f);
    ageEditUpdate->setFont(f);
    siteLinkEditUpdate->setFont(f);
    formLayout->addRow(breedLabel, breedEditUpdate);
    formLayout->addRow(nameLabel, nameEditUpdate);
    formLayout->addRow(ageLabel, ageEditUpdate);
    formLayout->addRow(siteLinkLabel, siteLinkEditUpdate);
    vLayout->addWidget(dogData);
}

void DogShelterGUI::buttonsUpdate(QVBoxLayout *vLayout, const QFont &f) {
    QWidget* updateButtons = new QWidget{};
    QHBoxLayout* hLayout = new QHBoxLayout{updateButtons};
    updateButtonUpdate = new QPushButton("Update");
    updateButtonUpdate->setFont(f);
    hLayout->addWidget(updateButtonUpdate);
    vLayout->addWidget(updateButtons);
}

void DogShelterGUI::userMode() {
    /// big layout
    this->userWidget = new QWidget{};
    QHBoxLayout* layoutUser = new QHBoxLayout{};
    QFont f{"Times New Roman", 12};

    /// left side - the list and a filter option
    QWidget* leftSide = new QWidget{};
    QVBoxLayout* vLayoutLeft = new QVBoxLayout{leftSide};
    listDogsUser = new QListWidget{};
    // set the selection model
    listDogsUser->setSelectionMode(QAbstractItemView::SingleSelection);
    listDogsUser->setMinimumSize(600, 600);
    vLayoutLeft->addWidget(listDogsUser);
    // filter option
    filterUser(vLayoutLeft, f);

    /// middle side - dog information + buttons
    QWidget* middleSide = new QWidget{};
    QVBoxLayout* vLayout = new QVBoxLayout{middleSide};
    // dog information
    dogDataUser(vLayout, f);
    // buttons
    buttonsUser(vLayout, f);

    /// right side - just the adoption list
    QWidget* rightSide = new QWidget{};
    QVBoxLayout* vLayoutRight = new QVBoxLayout{rightSide};
    adoptionTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    adoptionTable->setModel(model);
    adoptionTable->setItemDelegate(new PictureDelegate{});
    adoptionTable->resizeColumnsToContents();
    adoptionTable->resizeRowsToContents();
    adoptionTable->setMinimumSize(QSize(600, 600));
    vLayoutRight->addWidget(adoptionTable);

    /// add everything to the big layout
    layoutUser->addWidget(leftSide);
    layoutUser->addWidget(middleSide);
    layoutUser->addWidget(rightSide);
    this->userWidget->setLayout(layoutUser);

    shortcutUndoUser = new QShortcut(QKeySequence("Ctrl+Z"), userWidget);
    QObject::connect(shortcutUndoUser, SIGNAL(activated()), this, SLOT(undoUser()));
    shortcutRedoUser = new QShortcut(QKeySequence("Ctrl+Y"), userWidget);
    QObject::connect(shortcutRedoUser, SIGNAL(activated()), this, SLOT(redoUser()));
}

void DogShelterGUI::dogDataUser(QVBoxLayout *vLayout, QFont f) {
    QWidget *dogData = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{dogData};
    breedEditUser = new QLineEdit{};
    nameEditUser = new QLineEdit{};
    ageEditUser = new QLineEdit{};
    siteLinkEditUser = new QTextEdit{};
    QLabel* breedLabel = new QLabel{"&Breed:" };
    breedLabel->setBuddy(breedEditUser);
    QLabel* nameLabel = new QLabel{"&Name:" };
    nameLabel->setBuddy(nameEditUser);
    QLabel* ageLabel = new QLabel{ "&Age: " };
    ageLabel->setBuddy(ageEditUser);
    QLabel* siteLinkLabel = new QLabel{ "&SiteLink:" };
    siteLinkLabel->setBuddy(siteLinkEditUser);
    breedLabel->setFont(f);
    nameLabel->setFont(f);
    ageLabel->setFont(f);
    siteLinkLabel->setFont(f);
    breedEditUser->setFont(f);
    nameEditUser->setFont(f);
    ageEditUser->setFont(f);
    siteLinkEditUser->setFont(f);
    formLayout->addRow(breedLabel, breedEditUser);
    formLayout->addRow(nameLabel, nameEditUser);
    formLayout->addRow(ageLabel, ageEditUser);
    formLayout->addRow(siteLinkLabel, siteLinkEditUser);
    vLayout->addWidget(dogData);
}

void DogShelterGUI::buttonsUser(QVBoxLayout *vLayout, QFont f) {
    QWidget* adoNexButtons = new QWidget{};
    QHBoxLayout* hLayout = new QHBoxLayout{adoNexButtons};
    adoptButton = new QPushButton("Adopt");
    adoptButton->setFont(f);
    nextButton = new QPushButton("Next");
    nextButton->setFont(f);
    hLayout->addWidget(adoptButton);
    hLayout->addWidget(nextButton);
    vLayout->addWidget(adoNexButtons);
    QWidget* disExiButtons = new QWidget{};
    QHBoxLayout* hLayout2 = new QHBoxLayout{disExiButtons};
    displayButton = new QPushButton("Display");
    undoButtonUser = new QPushButton("Undo");
    redoButtonUser = new QPushButton("Redo");
    undoButtonUser->setFont(f);
    redoButtonUser->setFont(f);
    displayButton->setFont(f);
    hLayout2->addWidget(displayButton);
    hLayout2->addWidget(undoButtonUser);
    hLayout2->addWidget(redoButtonUser);
    vLayout->addWidget(disExiButtons);
}

void DogShelterGUI::filterUser(QVBoxLayout *vLayout, QFont f) {
    filterButton = new QPushButton{"Filter"};
    filterButton->setFont(f);
    vLayout->addWidget(filterButton);
    QWidget *filterData = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{filterData};
    filterBreedEdit = new QLineEdit{};
    filterAgeEdit = new QLineEdit{};
    QLabel* breedLabel = new QLabel{"&Breed:" };
    breedLabel->setBuddy(filterBreedEdit);
    QLabel* ageLabel = new QLabel{ "&Age: " };
    ageLabel->setBuddy(filterAgeEdit);
    breedLabel->setFont(f);
    ageLabel->setFont(f);
    filterBreedEdit->setFont(f);
    filterAgeEdit->setFont(f);
    formLayout->addRow(breedLabel, filterBreedEdit);
    formLayout->addRow(ageLabel, filterAgeEdit);
    vLayout->addWidget(filterData);
    revertButton = new QPushButton{"Revert"};
    revertButton->setFont(f);
    vLayout->addWidget(revertButton);
}

void DogShelterGUI::populateDogList()
{
    // clear the list, if there are elements in it
    if (this->listDogs->count() > 0)
        this->listDogs->clear();

    if (this->listDogsUser->count() > 0)
        this->listDogsUser->clear();

    for (auto &dog : this->adminService.getAllDogs())
    {
        string age = std::to_string(dog.getAge());
        QString itemInList = QString::fromStdString(dog.getBreed() + " - " +
                                                    dog.getName() + " - " + age + " - " +
                                                    dog.getSiteLink());
        QFont f{"Times New Roman", 12};
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->listDogs->addItem(item);
    }

    for (auto &dog : this->adminService.getAllDogs())
    {
        std::string age = std::to_string(dog.getAge());
        QString itemInList = QString::fromStdString(dog.getBreed() + " - " +
                                                    dog.getName() + " - " + age + " - " +
                                                    dog.getSiteLink());
        QFont f{"Times New Roman", 12};
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->listDogsUser->addItem(item);
    }

    // set the selection on the first item in the list
    if (!this->adminService.getAllDogs().empty()) {
        this->listDogs->setCurrentRow(0);
        this->listDogsUser->setCurrentRow(0);
    }
}

void DogShelterGUI::populateAdoptionList()
{
    if(filtered) {
        QString breed = this->filterBreedEdit->text();
        QString age_str = this->filterAgeEdit->text();

        int age;
        if(age_str.toStdString().empty() || age_str.toInt() == 0) {
            age = -1;
        }
        else {
            age = age_str.toInt();
        }
        // clear the list, if there are elements in it
        if (this->listDogsUser->count() > 0)
            this->listDogsUser->clear();

        for (auto &dog : adminService.getFilteredDogs(breed.toStdString(), age))
        {
            string age = std::to_string(dog.getAge());
            QString itemInList = QString::fromStdString(dog.getBreed() + " - " +
                                                        dog.getName() + " - " + age + " - " +
                                                        dog.getSiteLink());
            QFont f{"Times New Roman", 12};
            QListWidgetItem* item = new QListWidgetItem{ itemInList };
            item->setFont(f);
            this->listDogsUser->addItem(item);
        }
        if(csv) {
            model->set_dogs(this->userServiceCsv.getAdoptionList());
        }
        if(html) {
            model->set_dogs(this->userServiceHtml.getAdoptionList());
        }

        // set the selection on the first item in the list
        if (!this->adminService.getAllDogs().empty()) {
            this->listDogsUser->setCurrentRow(0);
//            system(("start chrome " + this->adminService.getAllDogs()[0].getSiteLink()).c_str());
        }
        else {
            filtered = false;
        }
    }
    else if (!filtered) {
        if(csv) {
            model->set_dogs(this->userServiceCsv.getAdoptionList());
        }
        if(html) {
            model->set_dogs(this->userServiceHtml.getAdoptionList());
        }
    }

}

void DogShelterGUI::connectSignalsAndSlots() {
    QObject::connect(buttonAdmin, &QPushButton::clicked,this,[=](){
        this->adminWidget->setWindowState(Qt::WindowMaximized);
        this->adminWidget->show();
    });
    QObject::connect(buttonUser, &QPushButton::clicked,this,[=](){
        this->chooseRepo->setWindowState(Qt::WindowMaximized);
        this->chooseRepo->show();
    });
    QObject::connect(updateButton, &QPushButton::clicked,this,[=](){
        this->updateWidget->setWindowState(Qt::WindowMaximized);
        this->updateWidget->show();
    });
    QObject::connect(buttonCsv, &QPushButton::clicked,this,[=](){
        csv = true;
        this->userWidget->setWindowState(Qt::WindowMaximized);
        this->userWidget->show();
    });
    QObject::connect(buttonHtml, &QPushButton::clicked,this,[=](){
        html = true;
        this->userWidget->setWindowState(Qt::WindowMaximized);
        this->userWidget->show();
    });


    // when the vector is updated - re-populate the list
    QObject::connect(this, &DogShelterGUI::listUpdatedSignal, this, &DogShelterGUI::populateDogList);
    QObject::connect(this, &DogShelterGUI::listUpdatedAdoptionSignal, this, &DogShelterGUI::populateAdoptionList);

    // add a connection: function listItemChangedAdmin() will be called when an item in the list is selected
    QObject::connect(this->listDogs, &QListWidget::itemSelectionChanged, this, [this]() {
        this->listItemChangedAdmin();
    });

    QObject::connect(this->listDogsUser, &QListWidget::itemSelectionChanged, this, [this]() {
        if(!filtered)
            this->listItemChangedUser();
        else if(filtered)
            this->listItemChangedUserFilter();
    });

    // add button connections
    QObject::connect(addButton, &QPushButton::clicked, this, &DogShelterGUI::addButtonHandler);
    QObject::connect(deleteButton, &QPushButton::clicked, this, &DogShelterGUI::deleteButtonHandler);
    QObject::connect(updateButtonUpdate, &QPushButton::clicked, this, &DogShelterGUI::updateButtonHandler);
    QObject::connect(undoButton, &QPushButton::clicked, this, &DogShelterGUI::undoButtonHandler);
    QObject::connect(redoButton, &QPushButton::clicked, this, &DogShelterGUI::redoButtonHandler);
    QObject::connect(undoButtonUser, &QPushButton::clicked, this, &DogShelterGUI::undoButtonHandlerUser);
    QObject::connect(redoButtonUser, &QPushButton::clicked, this, &DogShelterGUI::redoButtonHandlerUser);
    QObject::connect(nextButton, &QPushButton::clicked, this, &DogShelterGUI::nextButtonHandler);
    QObject::connect(adoptButton, &QPushButton::clicked, this, &DogShelterGUI::adoptButtonHandler);
    QObject::connect(displayButton, &QPushButton::clicked,this, &DogShelterGUI::displayButtonHandler);
    QObject::connect(filterButton, &QPushButton::clicked,this, &DogShelterGUI::filterButtonHandler);
    QObject::connect(revertButton, &QPushButton::clicked,this, &DogShelterGUI::revertButtonHandler);

    // connect the signals to the slots
    QObject::connect(this, SIGNAL(addSignal(const string&, const string&, int, const string&)),
                     this, SLOT(add(const string&, const string&, int, const string&)));
    QObject::connect(this, SIGNAL(deleteSignal(const string&, const string&)),
                     this, SLOT(del(const string&, const string&)));
    QObject::connect(this, SIGNAL(updateSignal(const string&, const string&, const string&, const string&, int, const string&)),
                     this, SLOT(update(const string&, const string&, const string&, const string&, int, const string&)));
    QObject::connect(this, SIGNAL(adoptSignal(const string&, const string&, int, const string&)),
                     this, SLOT(adopt(const string&, const string&, int, const string&)));
}

void DogShelterGUI::revertButtonHandler()
{
    filtered = false;
    populateDogList();
}

void DogShelterGUI::filterButtonHandler()
{
    // read data from the text boxes
    filtered = true;
    QString breed = this->filterBreedEdit->text();
    QString age_str = this->filterAgeEdit->text();

    int age;
    if(age_str.toStdString().empty() || age_str.toInt() == 0) {
        age = -1;
    }
    else {
        age = age_str.toInt();
    }
    // clear the list, if there are elements in it
    if (this->listDogsUser->count() > 0)
        this->listDogsUser->clear();

    for (auto &dog : adminService.getFilteredDogs(breed.toStdString(), age))
    {
        string age = std::to_string(dog.getAge());
        QString itemInList = QString::fromStdString(dog.getBreed() + " - " +
                                                    dog.getName() + " - " + age + " - " +
                                                    dog.getSiteLink());
        QFont f{"Times New Roman", 12};
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->listDogsUser->addItem(item);
    }

    // set the selection on the first item in the list
    if (!this->adminService.getAllDogs().empty()) {
        this->listDogsUser->setCurrentRow(0);
    }

}

void DogShelterGUI::displayButtonHandler()
{
    if(html) {
        system(userServiceHtml.getDisplayCommand().c_str());
    }
    if(csv) {
        system(userServiceCsv.getDisplayCommand().c_str());
    }
}

void DogShelterGUI::add(const string& breed, const string& name, int age, const std::string& siteLink)
{
    try {
        this->adminService.addDogService(breed, name, age, siteLink);
    }
    catch (RepositoryException &re) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(re.getErrorMessage()));
    }
    catch (ValidationException &ve) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(ve.getErrorMessage()));
    }
    catch (ServiceException &se) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(se.getErrorMessage()));
    }
    emit listUpdatedSignal();
}

void DogShelterGUI::adopt(const string &breed, const string &name, int age, const string &siteLink) {
    if(html) {
        userServiceHtml.addDogService(breed, name, age, siteLink);
    }
    if(csv) {
        userServiceCsv.addDogService(breed, name, age, siteLink);
    }
    emit deleteSignal(breed, name);
    emit listUpdatedAdoptionSignal();
}

void DogShelterGUI::addButtonHandler()
{
    // read data from the textboxes
    QString breed = this->breedEditAdmin->text();
    QString name = this->nameEditAdmin->text();
    QString age = this->ageEditAdmin->text();
    QString siteLink = this->siteLinkEditAdmin->toPlainText();

    // emit the add signal
    emit addSignal(breed.toStdString(), name.toStdString(), age.toInt(), siteLink.toStdString());
}

void DogShelterGUI::del(const string& breed, const string& name)
{
    try {
        this->adminService.deleteDogService(breed, name);
    }
    catch (RepositoryException &re) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(re.getErrorMessage()));
    }
    catch (ValidationException &ve) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(ve.getErrorMessage()));
    }
    catch (ServiceException &se) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(se.getErrorMessage()));
    }
    emit listUpdatedSignal();
}

void DogShelterGUI::deleteButtonHandler()
{
    // read data from the text boxes
    QString breed = this->breedEditAdmin->text();
    QString name = this->nameEditAdmin->text();


    // emit the signal: the dogs were updated
    emit deleteSignal(breed.toStdString(), name.toStdString());
}

void DogShelterGUI::updateButtonHandler()
{
    // read data from the text boxes
    QString old_breed = this->breedEditAdmin->text();
    QString old_name = this->nameEditAdmin->text();
    QString breed = this->breedEditUpdate->text();
    QString name = this->nameEditUpdate->text();
    QString age_str = this->ageEditUpdate->text();
    QString siteLink = this->siteLinkEditUpdate->toPlainText();

    int age;
    if(age_str.toStdString().empty() || age_str.toInt() == 0) {
        age = -1;
    }
    else {
        age = age_str.toInt();
    }

    // emit the signal: the dogs were updated
    emit updateSignal(old_breed.toStdString(), old_name.toStdString(), breed.toStdString(), name.toStdString(), age, siteLink.toStdString());
}

int DogShelterGUI::getSelectedIndexAdmin()
{
    if (this->listDogs->count() == 0)
        return -1;

    if (this->listDogsUser->count() == 0)
        return -1;

    // get selected indexList
    QModelIndexList indexList = this->listDogs->selectionModel()->selectedIndexes();
    if (indexList.empty())
    {
        this->breedEditAdmin->clear();
        this->nameEditAdmin->clear();
        this->ageEditAdmin->clear();
        this->siteLinkEditAdmin->clear();
        return -1;
    }

    int index = indexList.at(0).row();
    return index;
}

int DogShelterGUI::getSelectedIndexUser()
{
    if (this->listDogs->count() == 0)
        return -1;

    if (this->listDogsUser->count() == 0)
        return -1;

    // get selected indexList
    QModelIndexList indexList = this->listDogsUser->selectionModel()->selectedIndexes();
    if (indexList.empty())
    {
        this->breedEditUser->clear();
        this->nameEditUser->clear();
        this->ageEditUser->clear();
        this->siteLinkEditUser->clear();
        return -1;
    }

    int index = indexList.at(0).row();
    return index;
}

void DogShelterGUI::listItemChangedAdmin()
{
    int index = this->getSelectedIndexAdmin();
    if (index == -1)
        return;

    if (index >= this->adminService.getAllDogs().size())
        return;

    Dog dog = this->adminService.getAllDogs()[index];

    this->breedEditAdmin->setText(QString::fromStdString(dog.getBreed()));
    this->nameEditAdmin->setText(QString::fromStdString(dog.getName()));
    this->ageEditAdmin->setText(QString::fromStdString(std::to_string(dog.getAge())));
    this->siteLinkEditAdmin->setText(QString::fromStdString(dog.getSiteLink()));
}

void DogShelterGUI::listItemChangedUser()
{
    int index = this->getSelectedIndexUser();
    if (index == -1)
        return;

    if (index == this->adminService.getAllDogs().size())
        index = 0;

    if (index > this->adminService.getAllDogs().size() || this->adminService.getAllDogs().empty())
        return;

    Dog dog = this->adminService.getAllDogs()[index];
//    if(!first) {
//        system(("start chrome " + dog.getSiteLink()).c_str());
//    }
    first = false;

    this->breedEditUser->setText(QString::fromStdString(dog.getBreed()));
    this->nameEditUser->setText(QString::fromStdString(dog.getName()));
    this->ageEditUser->setText(QString::fromStdString(std::to_string(dog.getAge())));
    this->siteLinkEditUser->setText(QString::fromStdString(dog.getSiteLink()));
}

void DogShelterGUI::listItemChangedUserFilter()
{
    QString breed = this->filterBreedEdit->text();
    QString age_str = this->filterAgeEdit->text();
    int age;
    if(age_str.toStdString().empty() || age_str.toInt() == 0) {
        age = -1;
    }
    else {
        age = age_str.toInt();
    }

    int index = this->getSelectedIndexUser();
    if (index == -1)
        return;

    if (index == this->adminService.getFilteredDogs(breed.toStdString(), age).size())
        index = 0;

    if (index > this->adminService.getFilteredDogs(breed.toStdString(), age).size() || this->adminService.getFilteredDogs(breed.toStdString(), age).empty())
        return;

    Dog dog;
    dog = this->adminService.getFilteredDogs(breed.toStdString(), age)[index];
    //system(("start chrome " + dog.getSiteLink()).c_str());


    this->breedEditUser->setText(QString::fromStdString(dog.getBreed()));
    this->nameEditUser->setText(QString::fromStdString(dog.getName()));
    this->ageEditUser->setText(QString::fromStdString(std::to_string(dog.getAge())));
    this->siteLinkEditUser->setText(QString::fromStdString(dog.getSiteLink()));
}

void DogShelterGUI::adoptButtonHandler()
{
    int index = getSelectedIndexUser();
    Dog dog;
    if(!filtered)
        dog = this->adminService.getAllDogs()[index];
    else
    {
        QString breed = this->filterBreedEdit->text();
        QString age_str = this->filterAgeEdit->text();
        int age;
        if(age_str.toStdString().empty() || age_str.toInt() == 0) {
            age = -1;
        }
        else {
            age = age_str.toInt();
        }
        dog = this->adminService.getFilteredDogs(breed.toStdString(), age)[index];
    }
    emit adoptSignal(dog.getBreed(), dog.getName(), dog.getAge(), dog.getSiteLink());
}

void DogShelterGUI::nextButtonHandler()
{
    next_index = this->getSelectedIndexUser();
    next_index++;
    if (next_index == this->adminService.getAllDogs().size())
        next_index = 0;

    if (next_index > this->adminService.getAllDogs().size() || this->adminService.getAllDogs().empty())
        return;

    Dog dog = this->adminService.getAllDogs()[next_index];

    this->breedEditUser->setText(QString::fromStdString(dog.getBreed()));
    this->nameEditUser->setText(QString::fromStdString(dog.getName()));
    this->ageEditUser->setText(QString::fromStdString(std::to_string(dog.getAge())));
    this->siteLinkEditUser->setText(QString::fromStdString(dog.getSiteLink()));

    this->listDogsUser->setCurrentRow(next_index);
}

void DogShelterGUI::update(const string &old_breed, const string &old_name, const string &breed, const string &name, int age, const string &siteLink) {
    try {
        this->adminService.updateDogService(old_breed, old_name, breed, name, age, siteLink);
    }
    catch (RepositoryException &re) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(re.getErrorMessage()));
    }
    catch (ValidationException &ve) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(ve.getErrorMessage()));
    }
    catch (ServiceException &se) {
        QMessageBox::information(adminWidget, "Error", QString::fromStdString(se.getErrorMessage()));
    }
    emit listUpdatedSignal();
}

void DogShelterGUI::chooseRepoType() {
    QFont f{"Times New Roman", 12};
    chooseRepo = new QWidget{};
    QHBoxLayout* layoutRepo = new QHBoxLayout{};
    buttonCsv = new QPushButton{"CSV Repo"};
    buttonHtml = new QPushButton{"HTML Repo"};
    buttonCsv->setFont(f);
    buttonHtml->setFont(f);
    layoutRepo->addWidget(buttonCsv);
    layoutRepo->addWidget(buttonHtml);
    chooseRepo->setLayout(layoutRepo);
}

void DogShelterGUI::undo() {
    try{
        adminService.undo();
        emit listUpdatedSignal();
        QMessageBox::information(nullptr, "Info", "Undo performed!");
    }
    catch (ServiceException& error){
        QMessageBox::information(nullptr, "Info", QString::fromStdString(error.getErrorMessage()));
    }
}

void DogShelterGUI::redo() {
    try{
        adminService.redo();
        emit listUpdatedSignal();
        QMessageBox::information(nullptr, "Info", "Redo performed!");
    }
    catch (ServiceException& error){
        QMessageBox::information(nullptr, "Info", QString::fromStdString(error.getErrorMessage()));
    }
}

void DogShelterGUI::undoButtonHandler() {
    undo();
}

void DogShelterGUI::redoButtonHandler() {
    redo();
}

void DogShelterGUI::undoUser() {
    try{
        adminService.undo();
        if(html) {
            userServiceHtml.undo();
        }
        if(csv) {
            userServiceCsv.undo();
        }
        emit listUpdatedSignal();
        emit listUpdatedAdoptionSignal();
        QMessageBox::information(nullptr, "Info", "Undo performed!");
    }
    catch (ServiceException& error){
        QMessageBox::information(nullptr, "Info", QString::fromStdString(error.getErrorMessage()));
    }
}

void DogShelterGUI::redoUser() {
    try{
        if(html) {
            userServiceHtml.redo();
        }
        if(csv) {
            userServiceCsv.redo();
        }
        adminService.redo();
        emit listUpdatedSignal();
        emit listUpdatedAdoptionSignal();
        QMessageBox::information(nullptr, "Info", "Redo performed!");
    }
    catch (ServiceException& error){
        QMessageBox::information(nullptr, "Info", QString::fromStdString(error.getErrorMessage()));
    }
}

void DogShelterGUI::undoButtonHandlerUser() {
    undoUser();
}

void DogShelterGUI::redoButtonHandlerUser() {
    redoUser();
}