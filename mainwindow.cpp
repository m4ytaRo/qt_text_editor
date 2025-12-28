#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QListView>
#include <QTreeWidget>

#include "addnodedialog.h"
#include "documentitem.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qRegisterMetaType<DocumentItem*>("DocumentItem*"); // weirdo
    ui->setupUi(this);

    currentProject = new Project();

    setupUiCustom();
    setupConnections();

}

void MainWindow::setupConnections () {
    connect( ui->actionNew, &QAction::triggered, this, &MainWindow::newFile);
    connect( ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect( ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect( ui->actionSaveAs, &QAction::triggered, this, &MainWindow::saveFileAs);

    connect( ui->actionChangeFont, &QAction::triggered, this, &MainWindow::changeFont);
    connect( ui->actionMakeBold, &QAction::triggered, this, &MainWindow::setFontBold);
    connect( ui->actionMakeUnderlined, &QAction::triggered, this, &MainWindow::setFontUnderlined);
    connect( ui->actionMakeItalic, &QAction::triggered, this, &MainWindow::setFontItalic);

    connect( ui->actionIncreaseFontSize, &QAction::triggered, this, &MainWindow::increaseFontSize);

    connect( ui->actionNewNode, &QAction::triggered, this, [this]() {
        AddNodeDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QTreeWidgetItem* current = mainTree->currentItem();
            if (!current)
                current = mainTree->invisibleRootItem();

            DocumentItem* newItem = currentProject->createItem(DocumentItem::SystemFolder, dialog.nodeName(), dialog.iconPath());
            QTreeWidgetItem* newTreeItem = new QTreeWidgetItem(current);

            auto* docPtr = current->data(0, DOCUMENT_ROLE).value<DocumentItem*>();
            newItem->setParent(docPtr);
            docPtr->addChild(newItem);

            newItem->connectUIPointer(newTreeItem);
            newItem->syncWithUI();

            //newItem->set Text(0, dialog.nodeName());
            //if (!dialog.iconPath().isEmpty())
            //    newItem->setIcon(0, QIcon(dialog.iconPath()));

            mainTree->expandItem(current);
        }
    });

    connect (ui->actionDeleteNode, &QAction::triggered, this, &MainWindow::deleteNode);


    connect(mainTree, &QTreeWidget::itemClicked, this, &MainWindow::onItemClicked);
}

void MainWindow::setupUiCustom() {



    mainSplitter = new QSplitter(Qt::Horizontal, this);

    mainTree = new QTreeWidget;
    //mainTree->setHeaderLabel("Files");
    mainTree->setHeaderHidden(true);

    DocumentItem* notesItem = currentProject->createItem(DocumentItem::SystemFolder, "Notes", "");
    DocumentItem* testsItem = currentProject->createItem(DocumentItem::SystemFolder, "Tests", "");

    currentProject->addItem(currentProject->getRoot(), notesItem);
    currentProject->addItem(currentProject->getRoot(), testsItem);

    QTreeWidgetItem* notesRoot = new QTreeWidgetItem(mainTree);
    notesItem->connectUIPointer(notesRoot);
    notesItem->syncWithUI();

    QTreeWidgetItem* testsRoot = new QTreeWidgetItem(mainTree);
    testsItem->connectUIPointer(testsRoot);
    testsItem->syncWithUI();

    notesRoot->setFlags(notesRoot->flags() & ~Qt::ItemIsDragEnabled);
    testsRoot->setFlags(testsRoot->flags() & ~(Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled));


    mainTree->setDragEnabled(true);
    mainTree->setAcceptDrops(true);
    mainTree->setDropIndicatorShown(true);
    mainTree->setDragDropMode(QAbstractItemView::InternalMove);

    mainTree->expandAll();
    //mainTree->setItemDelegate(new MyDelegate(this));
    mainTree->setStyleSheet(R"(
    QTreeWidget {
        background-color: #F5F5F5;
        show-decoration-selected: 1;
        selection-background-color: #5EBEFF;
        selection-color: white;
        outline: none;
    }

    QTreeWidget::item {
        background-color: #FFFFFF;
        border: 1px solid #DDDDDD;
        color: black;
    }

    QTreeWidget::item:alternate {
        background-color: #FAFAFA;
        border: 1px solid #E5E5E5;
    }

    QTreeWidget::item:selected {
        background-color: #5EBEFF;
        border: 1px solid #5EBEFF;
        color: white;
    }

    QTreeWidget::item:selected:!active {
        background-color: #4A9AD9;
        border: 1px solid #4A9AD9;
        color: white;
    }

    QTreeWidget::branch:has-siblings:!adjoins-item {
        border-image: none;
        image: none;
    }
    QTreeWidget::branch:has-children:!has-siblings:closed,
    QTreeWidget::branch:open:has-children:!has-siblings,
)");


    mainSplitter->addWidget(mainTree);
    mainSplitter->addWidget(ui->textEdit);

    ui->toolBar->setFixedHeight(22);
    ui->toolBar->setIconSize(QSize(16, 16));
    ui->toolBar->setMovable(false);

    ui->menubar->setFixedHeight(22);
    ui->menubar->setStyleSheet(
        "QMenuBar {"
        "    background-color: #DDDDDD;"
        "    color: black;"
        "       border-bottom: 1px solid #BFBFBF;"
        "}"
        "QMenuBar::item:selected {"
        "    background: transparent;"
        "    border: none;"
        "}"
        "QMenuBar::item:pressed {"
        "    background-color: #BCBCBC;"
        "}"
        );

    setCentralWidget(mainSplitter);
}

MainWindow::~MainWindow()
{
    delete currentProject;
    delete ui;
}

void MainWindow::newFile() {

    m_currentText.clear();
    ui->textEdit->setText(QString());

}

void MainWindow::openFile() {

    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    if (fileName.isEmpty())
        return;

    QFile file (fileName);
    m_currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning (this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();


}

void MainWindow::saveFile() {



}

void MainWindow::saveFileAs() {



}

void MainWindow::changeFont() {



}

void MainWindow::setFontBold(bool italic) {



}

void MainWindow::setFontUnderlined(bool italic) {



}

void MainWindow::setFontItalic(bool italic) {



}

void MainWindow::increaseFontSize() {

    QTextEdit *editor = ui->textEdit;
    QFont font = editor->currentFont();

    font.setPointSize(font.pointSize() + 1);
    editor->setFont(font);

}

void MainWindow::deleteNode() {

    QTreeWidgetItem* item = mainTree->currentItem();
    if (!item)
        return;

    QTreeWidgetItem* parent = item->parent();

    if (parent) {
        parent->removeChild(item);
    }
    else {
        int index = mainTree->indexOfTopLevelItem(item);
        mainTree->takeTopLevelItem(index);
    }

}

void MainWindow::onItemClicked (QTreeWidgetItem* item, int column) {
    auto* doc = item->data(0, DOCUMENT_ROLE).value<DocumentItem*>(); //returning nullptr for some reason
    QString hier = "";
    if (doc != nullptr)
        hier= doc->getHeirarchy();
    ui->statusbar->showMessage(hier, 3000);

}
