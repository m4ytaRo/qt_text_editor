#ifndef PROJECT_H
#define PROJECT_H

#include "documentitem.h"
#include "systemfolderitem.h"
#include "rootitem.h"

class Project
{
public:
    Project();
    ~Project();

    DocumentItem* projectRoot() const;

    DocumentItem* createItem (DocumentItem::Type type,
                             const QString& name,
                             const QString& iconPath);

    void addItem (DocumentItem* parent, DocumentItem* item);

private:
    DocumentItem* root;
};

#endif // PROJECT_H
