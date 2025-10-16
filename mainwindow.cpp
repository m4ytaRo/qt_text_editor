#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect( ui->actionNew, &QAction::triggered, this, &MainWindow::newFile);
    connect( ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect( ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect( ui->actionSaveAs, &QAction::triggered, this, &MainWindow::saveFileAs);

    connect( ui->actionChangeFont, &QAction::triggered, this, &MainWindow::changeFont);
    connect( ui->actionMakeBold, &QAction::triggered, this, &MainWindow::setFontBold);
    connect( ui->actionMakeUnderlined, &QAction::triggered, this, &MainWindow::setFontUnderlined);
    connect( ui->actionMakeItalic, &QAction::triggered, this, &MainWindow::setFontItalic);

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
