#ifndef MOVIEMENU_H
#define MOVIEMENU_H
#include "userinfo.h"
#include"movielist.h"
#include"movie.h"
#include"genre.h"
#include"language.h"
#include"genre_series.h"
#include"language_series.h"
#include"series.h"
#include <QDialog>
#include "series_list.h"

namespace Ui {
class moviemenu;
}

class moviemenu : public QDialog
{
    Q_OBJECT
    QString username_1;

public:
    explicit moviemenu(QString username_1,QWidget *parent = nullptr);
    ~moviemenu();
    QString temp_username;

signals:
    void send_data(int);
    void send_username(QString);
public slots:
void receive_user_info(QString);

    void on_pushButton_clicked();
//    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();

private slots:


    void on_pushButton_4_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::moviemenu *ui;
    userinfo *usi;
    Movielist *movie_list;
    movie *Movie_app;
    genre *Genre;
    language *Language;
    genre_series *gs;
    series *Series;
    language_series *ls;
    series_list *sl;

};

#endif // MOVIEMENU_H
