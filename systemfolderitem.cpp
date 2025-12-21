#include "systemfolderitem.h"

SystemFolderItem::SystemFolderItem(DocumentItem* parent) {

}

bool SystemFolderItem::isDeletable() const  {
    return false;
}
DocumentItem::Type SystemFolderItem::getType() const  {
    return DocumentItem::Type::SystemFolder;
}
