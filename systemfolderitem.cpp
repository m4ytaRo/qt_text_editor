#include "systemfolderitem.h"


SystemFolderItem::SystemFolderItem(const QString& name,
                                   const QString& iconPath,
                                   DocumentItem* parent,
                                   QTreeWidgetItem* uiConnectedItem) : DocumentItem(name, iconPath) {
    setParent(parent);
    setUIPointer(uiConnectedItem);
}

bool SystemFolderItem::isDeletable() const  {
    return false;
}
DocumentItem::Type SystemFolderItem::getType() const  {
    return DocumentItem::Type::SystemFolder;
}
