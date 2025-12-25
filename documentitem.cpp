#include "documentitem.h"

DocumentItem::DocumentItem(const QString& name, const QString& iconPath, size_t index) {
    this->name = name;
    this->iconPath = iconPath;
    this->itemIndex = index;

    this->stateMask = 0;
    setState(State::Visible, true);
    setState(State::Locked, false);


    QVariant v = QVariant::fromValue(this);
    qDebug() << "isValid:" << v.isValid();
    qDebug() << "canConvert<DocumentItem*>:" << v.canConvert<DocumentItem*>();

    DocumentItem* ptr = v.value<DocumentItem*>();
    qDebug() << "ptr:" << ptr << "this:" << this;
}

DocumentItem::~DocumentItem () {
    deleteChildren();
}

void DocumentItem::syncWithUI() const {
    QTreeWidgetItem* item = this->getUIPointer();
    item->setData(0, Qt::UserRole + 1, QVariant::fromValue(this)); // maybe Qt::UserRole not Qt::UserRole + 1

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

QString DocumentItem::getHeirarchy() const {


    if (this->isRoot())
        return "";

    return parent->getHeirarchy() + "/" + getName();
}
