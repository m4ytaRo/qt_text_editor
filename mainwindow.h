#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QListView>

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


private slots:
    void newFile ();
    void openFile ();
    void saveFile();
    void saveFileAs();
    void changeFont();
    void setFontBold(bool bold);
    void setFontUnderlined(bool underlined);
    void setFontItalic (bool italic);

    void increaseFontSize();

private:
    Ui::MainWindow *ui;
    QString m_currentText;
    QString m_currentFile;

    QSplitter* mainSplitter;
    QListView* listView;

    void setupConnections ();
    void setupUiCustom () ;
};
#endif // MAINWINDOW_H
