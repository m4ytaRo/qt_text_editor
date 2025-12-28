#include "rootitem.h"


RootItem::RootItem( const QString& name,
                    const QString& iconPath,
                   size_t index) : DocumentItem(name, iconPath, index) {

}

bool RootItem::isDeletable() const  {
    return false;
}
DocumentItem::Type RootItem::getType() const  {
    return DocumentItem::Type::SystemFolder;
}
