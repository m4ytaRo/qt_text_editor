#ifndef SYSTEMFOLDERITEM_H
#define SYSTEMFOLDERITEM_H

#include "documentitem.h"

class SystemFolderItem : public DocumentItem
{
public:
    SystemFolderItem(DocumentItem* parent);

    bool isDeletable() const override;
    DocumentItem::Type getType() const override;

};

#endif // SYSTEMFOLDERITEM_H
