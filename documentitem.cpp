#include "documentitem.h"

DocumentItem::DocumentItem(const QString& name, const QString& iconPath) {
    this->name = name;
    this->iconPath = iconPath;
}

void DocumentItem::syncWithUI() const {
    QTreeWidgetItem* item = this->getUIPointer();

    item->setText(0, getName());
}
