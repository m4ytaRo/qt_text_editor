#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QListView>
#include <QTreeWidget>
#include <QLabel>

#include "Project.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString getTextEditContent () const {
        return QString(ui->textEdit->toPlainText());
    }


private slots:
    void newFile ();
    void openFile ();
    void saveFile();
    void saveFileAs();
    void changeFont();
    void setFontBold(bool bold);
    void setFontUnderlined(bool underlined);
    void setFontItalic (bool italic);
    void onItemClicked (QTreeWidgetItem* item, int column);

    void increaseFontSize();

    void deleteNode();

private:
    Ui::MainWindow *ui;

    QString m_currentFile;

    QSplitter* mainSplitter;
    QTreeWidget* mainTree;
    QListView* listView;

    QLabel *statusLabel = nullptr;

    Project* currentProject;

    void setupConnections ();
    void setupUiCustom () ;

};
#endif // MAINWINDOW_H
