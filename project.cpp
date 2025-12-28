#include "project.h"




Project::~Project () {
    delete root;
}

DocumentItem* Project::getRoot() const {
    return root;
}

DocumentItem* Project::createItem (DocumentItem::Type type,
                         const QString& name,
                                  const QString& iconPath) {
    DocumentItem* item = nullptr;
    switch (type) {
    case DocumentItem::Type::SystemFolder:
        item = new SystemFolderItem(name, iconPath, itemCount++);
    case DocumentItem::Type::Root:
        item = new RootItem(name, iconPath, itemCount++);
    }



    return item;
}

void Project::addItem (DocumentItem* parent, DocumentItem* item) {
    if (parent != nullptr)
        parent->addChild(item);
    item->setParent(parent);
}

void Project::setCurrentItem(DocumentItem* item) {
    if (currentItemOpened != nullptr) {
        currentItemOpened->setContent(currentContent);
    }
    qDebug() << currentContent;
    currentItemOpened = item;

    setCurrentContent(currentItemOpened->getContent());
}


