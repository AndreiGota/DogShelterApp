#include "PictureDelegate.h"

PictureDelegate::PictureDelegate(QWidget* parent) : QStyledItemDelegate{ parent } {}

void PictureDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const {
    if (index.column() != 3) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }
    auto name_index = index.model()->index(index.row(), 0);
    auto breed_index = index.model()->index(index.row(), 1);
    QString name = index.model()->data(name_index).toString();
    QString breed = index.model()->data(breed_index).toString();
    QPixmap pixmap("DogImages/" + name + "-" + breed + ".png");
    painter->drawPixmap(option.rect, pixmap);
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const {
    if (index.column() == 3) {
        return QSize(32, 64);
    }
    return QStyledItemDelegate::sizeHint(option, index);
}