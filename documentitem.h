#ifndef DOCUMENTITEM_H
#define DOCUMENTITEM_H

#include <QList>
#include <QTreeWidgetItem>


class DocumentItem
{
public:
    enum Type {
        SystemFolder,
        Root
    };
    enum class State : uint32_t {
        Visible = 0,
        HideChildrenWhenInvisible = 1 << 0
    };
    DocumentItem(const QString& name, const QString& iconPath, size_t index);
    virtual ~DocumentItem ();
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

    void deleteChildren ();

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

    bool isVisible () const {
        return getState(State::Visible);
    }
    void setVisibility(bool vis) {
        setState(State::Visible, vis);
    }



private:
    DocumentItem* parent;
    QList<DocumentItem*> children;
    QTreeWidgetItem* uiPointer;

    QString name;
    QString iconPath;

    size_t itemIndex;
    uint32_t stateMask;

    void setState(State state, bool value);
    bool getState(State state) const;

};

#endif // DOCUMENTITEM_H
