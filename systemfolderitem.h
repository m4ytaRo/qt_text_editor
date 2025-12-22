#ifndef SYSTEMFOLDERITEM_H
#define SYSTEMFOLDERITEM_H

#include "documentitem.h"

class SystemFolderItem : public DocumentItem
{
public:
    SystemFolderItem(DocumentItem* parent, QTreeWidgetItem* uiConnectedItem);

    bool isDeletable() const override;
    DocumentItem::Type getType() const override;

};

#endif // SYSTEMFOLDERITEM_H
