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

void DocumentItem::deleteChildren () {
    while (!children.isEmpty()) {
        DocumentItem* child = children.takeLast();
        child->deleteChildren();
        delete child;
    }
}

void DocumentItem::setState(State state, bool value) {
    if (value)
        stateMask |= static_cast<uint32_t> (state);
    else
        stateMask &= ~static_cast<uint32_t> (state);
}

bool DocumentItem::getState(State state) const {
    return (static_cast<uint32_t>(state) & stateMask) != 0;
}
