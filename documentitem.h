#ifndef DOCUMENTITEM_H
#define DOCUMENTITEM_H

#include <QList>
#include <QTreeWidgetItem>

constexpr int DOCUMENT_ROLE = Qt::UserRole + 1;

class DocumentItem
{
public:
    enum Type {
        SystemFolder,
        Root
    };
    enum class State : uint32_t {
        Visible = 0,
        Locked = 1 << 0
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

    void setContent (QString content) {
        this->content = content;
    }

    QString getContent () const {
        return content;
    }

    void syncWithUI ();

    bool isVisible () const {
        return getState(State::Visible);
    }
    void setVisibility(bool vis) {
        setState(State::Visible, vis);
    }

    QString getHeirarchy() const;



private:
    DocumentItem* parent = nullptr;
    QList<DocumentItem*> children;
    QTreeWidgetItem* uiPointer;

    QString name;
    QString iconPath;
    QString content;

    size_t itemIndex;
    uint32_t stateMask;

    void setState(State state, bool value);
    bool getState(State state) const;

};

//Q_DECLARE_METATYPE(DocumentItem*); // weirdo
Q_DECLARE_OPAQUE_POINTER(DocumentItem*)

#endif // DOCUMENTITEM_H
