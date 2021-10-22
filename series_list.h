#ifndef SERIES_LIST_H
#define SERIES_LIST_H

#include <QDialog>
#include<QPainter>
#include<QStyledItemDelegate>
#include<QByteArray>
#include"series.h"

namespace Ui {
class series_list;
}

class series_list : public QDialog
{
    Q_OBJECT
    QString username_11;

public:
    explicit series_list(QString username_11,QWidget *parent = nullptr);
    ~series_list();
private slots:
    void on_tableView_activated(const QModelIndex &index);
signals:
    void send_series(QString);

private:
    Ui::series_list *ui;
    series *temp_series;
};
class ImageDelegating: public QStyledItemDelegate{
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
        const QByteArray & bytes = index.data().toByteArray();
        QPixmap pixmap;
        if(!bytes.isNull() && pixmap.loadFromData(bytes)){
            // for BASE64 change to
//             pixmap.loadFromData(QByteArray::fromBase64(bytes));
            painter->drawPixmap(option.rect, pixmap.scaled(option.rect.size(),
                                                           Qt::KeepAspectRatio,
                                                         Qt::SmoothTransformation));
            return;
        }
        return QStyledItemDelegate::paint(painter, option, index);
    }
};

#endif // SERIES_LIST_H
