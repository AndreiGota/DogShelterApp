#include "TableModel.h"

DogTableModel::DogTableModel(vector<Dog> dogs): adoptedDogs(dogs) {

}

int DogTableModel::rowCount(const QModelIndex &parent) const {
    return 50;
}

int DogTableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant DogTableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole && index.row() < adoptedDogs.size()) {
        Dog dog = adoptedDogs[index.row()];
        if(index.column() == 0)
            return QString::fromStdString(dog.getName());
        else if(index.column() == 1)
            return QString::fromStdString(dog.getBreed());
        else if(index.column() == 2)
            return QString::number(dog.getAge());
        else if(index.column() == 3)
            return QString::fromStdString(dog.getSiteLink());
    }
    return QVariant{};
}

QVariant DogTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
                case 0:
                    return QString("Name");
                case 1:
                    return QString("Breed");
                case 2:
                    return QString("Age");
                case 3:
                    return QString("Photo");
                default:
                    break;
            }
        }
    }
    return QVariant();
}

void DogTableModel::set_dogs(const vector<Dog> &adoptionList) {
    this->adoptedDogs = adoptionList;
    QModelIndex upRight = createIndex(0, 0);
    QModelIndex downLeft = createIndex(rowCount(), columnCount());
    emit dataChanged(upRight, downLeft);
}
