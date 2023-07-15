#pragma once
#include <QAbstractTableModel>
#include "../Domain/Dog.h"
#include <vector>

using std::vector;

class TableModel: public QAbstractTableModel {
private:
    vector<Dog> dogs;
public:
    TableModel(const vector<Dog>& adoptionList): dogs(adoptionList) {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return 100;
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && index.row() < dogs.size()) {
            Dog dog = dogs[index.row()];
            if(index.column() == 0)
                return QString::fromStdString(dog.getBreed());
            else if(index.column() == 1)
                return QString::fromStdString(dog.getName());
            else if(index.column() == 2)
                return QString::number(dog.getAge());
            else
                return QString::fromStdString(dog.getSiteLink());
        }
        return QVariant{};
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            if (section == 0)
                return QString("Breed");
            else if (section == 1)
                return QString("Name");
            else if (section == 2)
                return QString("Age");
            else if (section == 3)
                return QString("Site Link");
        }
        return QVariant();
    }

    void set_dogs(const vector<Dog>& adoptionList) {
        this->dogs = adoptionList;
        QModelIndex upRight = createIndex(0, 0);
        QModelIndex downLeft = createIndex(rowCount(), columnCount());
        emit dataChanged(upRight, downLeft);
    }

};
