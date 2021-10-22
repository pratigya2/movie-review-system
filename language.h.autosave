#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QDialog>
#include<QPainter>
#include<QStyledItemDelegate>
#include<QByteArray>
#include"movie.h"
namespace Ui {
class language;
}

class language : public QDialog
{
    Q_OBJECT
    QString username_5;

public:
    explicit language(QString username_5,QWidget *parent = nullptr);
    ~language();

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
    void send_movie(QString);

private:
    Ui::language *ui;
    movie *temp_movie;
};
class ImageDelegates: public QStyledItemDelegate{
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
        const QByteArray & bytes = index.data().toByteArray();
        QPixmap pixmap;
        if(!bytes.isNull() && pixmap.loadFromData(bytes)){
            painter->drawPixmap(option.rect, pixmap.scaled(option.rect.size(),
                                                           Qt::KeepAspectRatio,
                                                         Qt::SmoothTransformation));
            return;
        }
        return QStyledItemDelegate::paint(painter, option, index);
    }
};

#endif // LANGUAGE_H
