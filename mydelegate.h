
#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>


class MyDelegate : public QStyledItemDelegate
{
public:
    explicit MyDelegate(QObject *parent = nullptr)
        : QStyledItemDelegate(parent)
    {}

    void paint(QPainter *p, const QStyleOptionViewItem &opt, const QModelIndex &idx) const override
    {
        QStyleOptionViewItem option = opt;

        // 1. Если выделено — вручную рисуем фон
        if (option.state & QStyle::State_Selected) {
            p->fillRect(option.rect, QColor(0x5EBEFF));
        }

        // 2. Убираем флаги, чтобы делегат не рисовал свой фон и hover
        option.state &= ~(QStyle::State_Selected | QStyle::State_MouseOver);

        // 3. Принудительно ставим белый цвет текста при выделении
        if (opt.state & QStyle::State_Selected) {
            option.palette.setColor(QPalette::Text, Qt::white);
            option.palette.setColor(QPalette::HighlightedText, Qt::white);
        }

        // 4. Шрифт
        option.font = QFont("Consolas", 11);

        // 5. Рисуем остальное (включая текст!)
        QStyledItemDelegate::paint(p, option, idx);
    }
};


#endif // MYDELEGATE_H
