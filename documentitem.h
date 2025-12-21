#ifndef DOCUMENTITEM_H
#define DOCUMENTITEM_H

#include <QList>

class DocumentItem
{
public:
    enum Type {
        Note,
        Test,
        SystemFolder
    };
    virtual ~DocumentItem () = default;
    virtual bool isDeletable () const = 0;
    virtual DocumentItem::Type getType () const = 0;

    bool isRoot () const {
        return parent == nullptr;
    }
    DocumentItem* getParent () const {
        return parent;
    }
    const QList<DocumentItem*>& getChildren () const {
        return children;
    }

private:
    DocumentItem* parent;
    QList<DocumentItem*> children;
};

#endif // DOCUMENTITEM_H
