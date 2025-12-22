#include "rootitem.h"


RootItem::RootItem( const QString& name,
                    const QString& iconPath) : DocumentItem(name, iconPath) {

}

bool RootItem::isDeletable() const  {
    return false;
}
DocumentItem::Type RootItem::getType() const  {
    return DocumentItem::Type::SystemFolder;
}
