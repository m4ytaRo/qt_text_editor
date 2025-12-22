#include "project.h"

Project::Project() {
    root = new RootItem("SystemRoot", "");
}

DocumentItem* Project::projectRoot() const {}

DocumentItem* Project::createItem (DocumentItem::Type type,
                         const QString& name,
                                  const QString& iconPath) {
    DocumentItem* item = nullptr;
    switch (type) {
    case DocumentItem::Type::SystemFolder:
        item = new SystemFolderItem(name, iconPath);
    case DocumentItem::Type::Note:
        //item = new NoteItem();
    case DocumentItem::Type::Test:
        //item = new TestItem();
    };


    return item;
}

void Project::addItem (DocumentItem* parent, DocumentItem* item) {
    parent->addChild(item);
    item->setParent(parent);
}
