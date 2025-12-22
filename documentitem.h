#ifndef DOCUMENTITEM_H
#define DOCUMENTITEM_H

#include <QList>
#include <QTreeWidgetItem>

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

    void deleteChildren () {
        while (!children.isEmpty()) {
            DocumentItem* child = children.takeLast();
            child->deleteChildren();
            delete child;
        }
    }

    void setUIPointer (QTreeWidgetItem* ptr) {
        uiPointer = ptr;
    }

    void setParent (DocumentItem* ptr) {
        parent = ptr;
    }

    void addChild(DocumentItem* ptr) {
        children.push_back(ptr);
    }


private:
    DocumentItem* parent;
    QList<DocumentItem*> children;
    QTreeWidgetItem* uiPointer;
};

#endif // DOCUMENTITEM_H
