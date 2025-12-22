#include "documentitem.h"

DocumentItem::DocumentItem(const QString& name, const QString& iconPath, size_t index) {
    this->name = name;
    this->iconPath = iconPath;
    this->itemIndex = index;
}

DocumentItem::~DocumentItem () {
    deleteChildren();
}

void DocumentItem::syncWithUI() const {
    QTreeWidgetItem* item = this->getUIPointer();

    item->setText(0, getName());
}
