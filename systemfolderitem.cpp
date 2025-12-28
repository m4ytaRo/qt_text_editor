#include "systemfolderitem.h"


SystemFolderItem::SystemFolderItem(const QString& name,
                                   const QString& iconPath,
                                   size_t index) : DocumentItem(name, iconPath, index) {

}

bool SystemFolderItem::isDeletable() const  {
    return false;
}
DocumentItem::Type SystemFolderItem::getType() const  {
    return DocumentItem::Type::SystemFolder;
}
