#include "PictureDelegate.h"

PictureDelegate::PictureDelegate(QWidget* parent) : QStyledItemDelegate{ parent } {}

void PictureDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const {
    if (index.column() != 3) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }
//    auto colour_index = index.model()->index(index.row(), 2);
//    QString color = index.model()->data(colour_index).toString();
//    QPixmap pixmap("../TrenchCoats/images/" + color + ".jpg");
//    if (pixmap.isNull()) pixmap = QPixmap("../TrenchCoats/images/default.jpg");
//    painter->drawPixmap(option.rect, pixmap);
    auto name_index = index.model()->index(index.row(), 0);
    auto breed_index = index.model()->index(index.row(), 1);
    QString name = index.model()->data(name_index).toString();
    QString breed = index.model()->data(breed_index).toString();
    QPixmap pixmap("C:/Users/Andrei/CLionProjects/DogShelterApp/DogImages/" + name + "-" + breed + ".png");
    painter->drawPixmap(option.rect, pixmap);
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const {
    if (index.column() == 3) {
        return QSize(32, 64);
    }
    return QStyledItemDelegate::sizeHint(option, index);
}