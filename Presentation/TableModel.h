#include <QAbstractTableModel>
#include "../Service/AdministratorService.h"
#include "../Service/UserService.h"

class DogTableModel: public QAbstractTableModel {
private:
    vector<Dog> adoptedDogs;
public:
    DogTableModel(vector<Dog> dogs);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void set_dogs(const vector<Dog>& adoptionList);
};