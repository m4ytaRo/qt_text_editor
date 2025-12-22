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
        SystemFolder,
        Root
    };
    DocumentItem(const QString& name, const QString& iconPath);
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

    void connectUIPointer (QTreeWidgetItem* ptr) {
        uiPointer = ptr;
    }

    QTreeWidgetItem* getUIPointer () const {
        return uiPointer;
    }

    void setParent (DocumentItem* ptr) {
        parent = ptr;
    }

    void addChild(DocumentItem* ptr) {
        children.push_back(ptr);
    }

    QString getName () const {
        return name;
    }

    QString getIconPath () const {
        return iconPath;
    }

    void syncWithUI () const;


private:
    DocumentItem* parent;
    QList<DocumentItem*> children;
    QTreeWidgetItem* uiPointer;

    QString name;
    QString iconPath;
};

#endif // DOCUMENTITEM_H
