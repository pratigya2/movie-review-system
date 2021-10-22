#ifndef GENRE_SERIES_H
#define GENRE_SERIES_H

#include <QDialog>
#include<QPainter>
#include<QStyledItemDelegate>
#include<QByteArray>
#include"series.h"
#include"serieslist.h"

namespace Ui {
class genre_series;
}

class genre_series : public QDialog
{
    Q_OBJECT
    QString username_7;

public:
    explicit genre_series(QString username_7,QWidget *parent = nullptr);
    ~genre_series();
private slots:
    void on_comedy_clicked();
    void on_action_clicked();
    void on_drama_clicked();
    void on_horror_clicked();
    void on_scifiction_clicked();
    void on_romantic_clicked();
    void on_tableView_activated(const QModelIndex &index);
signals:
    void send_series(QString);

private:
    Ui::genre_series *ui;
    serieslist *series_list;
    series *temp_series;
};
class ImagesDelegate: public QStyledItemDelegate{
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

#endif // GENRE_SERIES_H
