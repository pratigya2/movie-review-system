#include "userinfo.h"
#include "ui_userinfo.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>

userinfo::userinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userinfo)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w, h));
    QSqlDatabase myfile;
    myfile=QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/movie.db");
    if(!myfile.open())
    {
        qDebug()<<("Failed to open the database");
    }
    else
    {
        qDebug()<<("Connected");

    }
}
userinfo::~userinfo()
{
    delete ui;
}

void userinfo::receive_user_info(QString username)
{
    qDebug()<<username;
    QString username_2;
    username_2 = username.toUpper();
    ui->label_2->setText(username_2);

//    ui->textBrowser->setText(line2);
    QSqlQuery qry;
    qry.prepare("select * from users_info where username=?");
    qry.addBindValue(username);
    if(qry.exec())
    {
        while(qry.next())
        {
            QString fname= qry.value(0).toString();
            QString lname= qry.value(1).toString();
            QString age= qry.value(2).toString();
            QString gender= qry.value(3).toString();
            QString country= qry.value(4).toString();
            ui->firstname->setText(fname);
            ui->lastname->setText(lname);
            ui->age->setText(age);
            ui->gender->setText(gender);
            ui->country->setText(country);

        }
    }
}

