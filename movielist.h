 #ifndef MOVIELIST_H
#define MOVIELIST_H

#include <QDialog>
#include<QPainter>
#include<QStyledItemDelegate>
#include<QByteArray>
#include"movie.h"

namespace Ui {
class Movielist;
}

class Movielist : public QDialog
{
    Q_OBJECT
    QString username_2;

public:
    explicit Movielist(QString username_2,QWidget *parent = nullptr);
    ~Movielist();
    int temp;

private slots:
    void on_tableView_activated(const QModelIndex &index);
signals:
    void send_movie(QString);

private:
    Ui::Movielist *ui;
    movie *temp_movie;
};
class ImageDelegatess: public QStyledItemDelegate{
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

#endif // MOVIELIST_H
