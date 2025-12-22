#include "systemfolderitem.h"

SystemFolderItem::SystemFolderItem(DocumentItem* parent, QTreeWidgetItem* uiConnectedItem) {
    setParent(parent);
    setUIPointer(uiConnectedItem);
}

bool SystemFolderItem::isDeletable() const  {
    return false;
}
DocumentItem::Type SystemFolderItem::getType() const  {
    return DocumentItem::Type::SystemFolder;
}
