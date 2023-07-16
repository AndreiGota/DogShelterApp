//#pragma once
//#include <QAbstractTableModel>
//#include "../Domain/Dog.h"
//#include <vector>
//#include <QPixmap>
//
//using std::vector;
//
////class TableModel: public QAbstractTableModel {
////private:
////    vector<Dog> adoptedDogs;
////public:
////    TableModel(const vector<Dog>& adoptionList): adoptedDogs(adoptionList) {}
////
////    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
////        return 100;
////    }
////
////    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
////        return 5;
////    }
////
////    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
//////        if (role == Qt::DisplayRole && index.row() < adoptedDogs.size()) {
//////            Dog dog = adoptedDogs[index.row()];
//////            if(index.column() == 0)
//////                return QString::fromStdString(dog.getBreed());
//////            else if(index.column() == 1)
//////                return QString::fromStdString(dog.getName());
//////            else if(index.column() == 2)
//////                return QString::number(dog.getAge());
//////            else
//////                return QString::fromStdString(dog.getSiteLink());
//////        }
//////        return QVariant{};
////        int row = index.row();
////        int column = index.column();
////
////        Dog currentDog = this->adoptedDogs[row];
////        if (role == Qt::DisplayRole || role == Qt::EditRole)
////        {
////            switch (column) {
////                case 0:
////                    return QString::fromStdString(currentDog.getBreed());
////                case 1:
////                    return QString::fromStdString(currentDog.getName());
////                case 2:
////                    return QString::number(currentDog.getAge());
////                case 3:
////                    return QString::fromStdString(currentDog.getSiteLink());
////                default:
////                    break;
////            }
////        }
////        return QVariant{};
////    }
////
////    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
////        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
////            switch (section) {
////                case 0:
////                    return QString("Breed");
////                case 1:
////                    return QString("Name");
////                case 2:
////                    return QString("Age");
////                case 3:
////                    return QString("Site Link");
////                case 4:
////                    return QString("Photo");
////                default:
////                    break;
////            }
////        }
////        return QVariant{};
////    }
////
////    void set_dogs(const vector<Dog>& adoptionList) {
////        this->adoptedDogs = adoptionList;
////        QModelIndex upRight = createIndex(0, 0);
////        QModelIndex downLeft = createIndex(rowCount(), columnCount());
////        emit dataChanged(upRight, downLeft);
////    }
////
////};
//class TableModel: public QAbstractTableModel{
//
//    vector<Dog> dogs;
//
//public:
//
//    TableModel(const vector<Dog>& adoptionList) : dogs(adoptionList){
//    }
//
//    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
//        return dogs.size();
//    }
//
//    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
//        return 4;
//    }
//
//    QVariant data(const QModelIndex& index, int role) const {
//        if (role == Qt::DisplayRole || role == Qt::EditRole) {
//            if (index.row() < dogs.size()) {
//                const Dog& dog = dogs[index.row()];
//                if (index.column() == 0)
//                    return QString::fromStdString(dog.getBreed());
//                else if (index.column() == 1)
//                    return QString::fromStdString(dog.getName());
//                else if (index.column() == 2)
//                    return QString::number(dog.getAge());
//                else if (index.column() == 3)
//                    return QString::fromStdString(dog.getSiteLink());
//            }
//        }
//
//        return QVariant{};
//    }
//
//
//    void set_dogs(const vector<Dog>& adoptionList) {
//        this->dogs = adoptionList;
//        QModelIndex upRight = createIndex(0, 0);
//        QModelIndex downLeft = createIndex(rowCount(), columnCount());
//        emit dataChanged(upRight, downLeft);
//    }
//
//};
