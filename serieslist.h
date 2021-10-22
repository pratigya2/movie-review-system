#ifndef SERIESLIST_H
#define SERIESLIST_H

#include <QDialog>
#include<QPainter>
#include<QStyledItemDelegate>
#include<QByteArray>
#include"series.h"

namespace Ui {
class serieslist;
}

class serieslist : public QDialog
{
    Q_OBJECT
    QString username_10;

public:
    explicit serieslist(QString username_10,QWidget *parent = nullptr);
    ~serieslist();
     int temp;

signals:
    void send_series(QString);
private slots:
    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::serieslist *ui;
    series *temp_series;
};
class ImageDelegatedd: public QStyledItemDelegate{
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

#endif // SERIESLIST_H
