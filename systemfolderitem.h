#ifndef SYSTEMFOLDERITEM_H
#define SYSTEMFOLDERITEM_H

#include "documentitem.h"

class SystemFolderItem : public DocumentItem
{
public:
    SystemFolderItem();

    bool isDeletable() const override {
        return false;
    }
    DocumentItem::Type getType() const override {
        return DocumentItem::Type::SystemFolder;
    }
};

#endif // SYSTEMFOLDERITEM_H
