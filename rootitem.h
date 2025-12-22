#ifndef ROOTITEM_H
#define ROOTITEM_H

#include "documentitem.h"

class RootItem : public DocumentItem
{
public:
    RootItem(const QString& name,
                     const QString& iconPath);

    bool isDeletable() const override;
    DocumentItem::Type getType() const override;

};


#endif // ROOTITEM_H
