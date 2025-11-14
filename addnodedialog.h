#ifndef ADDNODEDIALOG_H
#define ADDNODEDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLabel>

class AddNodeDialog : public QDialog {
    Q_OBJECT
public:
    explicit AddNodeDialog(QWidget* parent = nullptr);

    QString nodeName() const;
    QString iconPath() const;

private slots:
    void chooseIcon();

private:
    QLineEdit* nameEdit;
    QString m_nodeName;
    QString m_iconPath;
};

#endif // ADDNODEDIALOG_H
