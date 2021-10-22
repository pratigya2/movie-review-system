#ifndef LANGUAGE_SERIES_H
#define LANGUAGE_SERIES_H

#include <QDialog>
#include<QPainter>
#include<QStyledItemDelegate>
#include<QByteArray>
#include"series.h"
#include"serieslist.h"

namespace Ui {
class language_series;
}

class language_series : public QDialog
{
    Q_OBJECT
    QString username_8;

public:
    explicit language_series(QString username_8,QWidget *parent = nullptr);
    ~language_series();

private slots:

    void on_nepali_clicked();

    void on_english_clicked();

    void on_chinese_clicked();

    void on_thai_clicked();

    void on_korean_clicked();

    void on_hindi_clicked();

    void on_turkish_clicked();

    void on_japanese_clicked();
    void on_tableView_activated(const QModelIndex &index);
signals:
    void send_series(QString);

private:
    Ui::language_series *ui;
     series *temp_series;
};
class ImageDelegated: public QStyledItemDelegate{
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

#endif // LANGUAGE_SERIES_H
