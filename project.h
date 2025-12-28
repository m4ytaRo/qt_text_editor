#ifndef PROJECT_H
#define PROJECT_H

#include "documentitem.h"
#include "systemfolderitem.h"
#include "rootitem.h"

class MainWindow;

class Project
{
public:
    Project()
        : Project(nullptr) {
    }

    explicit Project(MainWindow* window): currentMainWindow(window) {
        root = new RootItem("SystemRoot", "", itemCount++);
        addItem(nullptr, root);
    }
    ~Project();

    DocumentItem* getRoot() const;

    DocumentItem* createItem (DocumentItem::Type type,
                             const QString& name,
                             const QString& iconPath);

    void addItem (DocumentItem* parent, DocumentItem* item);

    void setCurrentItem(DocumentItem* item);

    DocumentItem* getCurrentItem() {
        return currentItemOpened;
    }

    QString getCurrentContent() const {
        return currentContent;
    }
    void syncConentWithTextEdit ();


private:
    DocumentItem* root;
    DocumentItem* currentItemOpened = nullptr;
    MainWindow* currentMainWindow = nullptr;

    size_t itemCount = 0;


    QString currentContent;

    void setCurrentContent(const QString& content) {
        currentContent = content;
    }
};

#endif // PROJECT_H
