#ifndef SYSTEMFOLDERITEM_H
#define SYSTEMFOLDERITEM_H

#include "documentitem.h"

class SystemFolderItem : public DocumentItem
{
public:
    SystemFolderItem(const QString& name,
                     const QString& iconPath,
                     size_t index);

    bool isDeletable() const override;
    DocumentItem::Type getType() const override;

};

#endif // SYSTEMFOLDERITEM_H
