#include "addnodedialog.h"
#include <QVBoxLayout>
#include <QFileDialog>

AddNodeDialog::AddNodeDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Добавить ветку");

    auto* layout = new QVBoxLayout(this);

    auto* nameLabel = new QLabel("Имя ветки:");
    nameEdit = new QLineEdit;
    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);

    auto* iconButton = new QPushButton("Выбрать иконку");
    layout->addWidget(iconButton);
    connect(iconButton, &QPushButton::clicked, this, &AddNodeDialog::chooseIcon);

    auto* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(buttons);

    connect(buttons, &QDialogButtonBox::accepted, this, [this]() {
        m_nodeName = nameEdit->text();
        if (m_nodeName.isEmpty()) return;
        accept();
    });
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

void AddNodeDialog::chooseIcon() {
    QString path = QFileDialog::getOpenFileName(
        this, "Выбрать иконку", "", "Изображения (*.png *.jpg *.ico)");
    if (!path.isEmpty()) {
        m_iconPath = path;
    }
}

QString AddNodeDialog::nodeName() const {
    return m_nodeName;
}

QString AddNodeDialog::iconPath() const {
    return m_iconPath;
}
