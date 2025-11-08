#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QListView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}

void MainWindow::setupUiCustom () {
    mainSplitter = new QSplitter(Qt::Horizontal, this);

    listView = new QListView;

    mainSplitter->addWidget(listView);
    mainSplitter->addWidget(ui->textEdit);

    setCentralWidget(mainSplitter);
}

MainWindow::~MainWindow()
{
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
