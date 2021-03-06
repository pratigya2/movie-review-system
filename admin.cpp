#include "admin.h"
#include "ui_admin.h"
#include"admin_adding.h"
#include "movie.h"
#include"users.h"
#include "pdeletep.h"
#include"admin_series_adding.h"
#include"series.h"
#include"series_delete.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));
}

admin::~admin()
{
    delete ui;
}
//QString admin="admin";

void admin::on_pushButton_2_clicked()
{
    admin_adding a;
    a.exec();

}

void admin::on_pushButton_4_clicked()
{
   mov =new movie("admin",this);
   mov->show();
}

void admin::on_pushButton_5_clicked()
{
    users u;
    u.exec();
}

void admin::on_pushButton_3_clicked()
{
    pdeletep pdp;
    pdp.exec();

}

void admin::on_pushButton_6_clicked()
{
    admin_series_adding ads;
    ads.exec();
}

void admin::on_pushButton_7_clicked()
{
    series_delete sd;
    sd.exec();

}

void admin::on_pushButton_8_clicked()
{
    s =new series("admin",this);
    s->show();
}
