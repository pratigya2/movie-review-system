#include "moviemenu.h"
#include "ui_moviemenu.h"
#include "userinfo.h"
#include "genre.h"
#include"series.h"
#include<QObject>
#include "language.h"
#include<QDebug>
#include"genre_series.h"
#include"language_series.h"
moviemenu::moviemenu(QString username_1,QWidget *parent) :
    QDialog(parent),username_1(username_1),
    ui(new Ui::moviemenu)
{
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));
}
moviemenu::~moviemenu()
{
    delete ui;
}
void moviemenu::on_pushButton_clicked()
{

    usi = new userinfo(this);
    usi->show();
    connect(this, SIGNAL(send_username(QString)), usi, SLOT(receive_user_info(QString)));
    emit send_username(temp_username);

}

void moviemenu::on_pushButton_2_clicked()
{
   movie_list = new Movielist(username_1,this);
   movie_list->show();

}
void moviemenu::receive_user_info(QString username)
{
    ui->label_2->setText(username);
    temp_username = username;
}
void moviemenu::on_pushButton_3_clicked()
{
    Genre = new genre(username_1,this);
    Genre->show();
}
void moviemenu::on_pushButton_5_clicked()
{
    Language = new language(username_1,this);
    Language->show();

}
void moviemenu::on_pushButton_4_clicked()
{
   Movie_app = new movie(username_1,this);
   Movie_app->show();
}
void moviemenu::on_pushButton_11_clicked()
{
    Series =new series(username_1,this);
    Series->show();
}
void moviemenu::on_pushButton_9_clicked()
{
    gs= new genre_series(username_1,this);
    gs->show();
}
void moviemenu::on_pushButton_12_clicked()
{
    ls=new language_series(username_1,this);
    ls->show();
}

void moviemenu::on_pushButton_10_clicked()
{
    sl = new series_list(username_1,this);
     sl->show();
        }
