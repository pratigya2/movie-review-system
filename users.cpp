#include "users.h"
#include "ui_users.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include <QMessageBox>

users::users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::users)
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

users::~users()
{
    delete ui;
}

void users::on_pushButton_clicked()
{
    QSqlQuery qry ;
    QSqlQueryModel *modal=new QSqlQueryModel;
    qry.prepare("select username from users_info");
     if (qry.exec())
    {
        modal->setQuery(qry);
        ui->listView->setModel(modal);

    }
}
void users::on_pushButton_2_clicked()
{
    QString name;
    name=ui->lineEdit->text();

 QSqlQuery qry;
 qry.prepare("SELECT * FROM users_info where username ='"+name+"'");
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
 if(!qry.exec())
 {
    QMessageBox::warning(this,"ERROR","Users not found");
 }
}
