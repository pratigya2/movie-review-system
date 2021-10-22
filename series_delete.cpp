#include "series_delete.h"
#include "ui_series_delete.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include<QMessageBox>
#include<QBuffer>
#include<QFileDialog>

series_delete::series_delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::series_delete)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w, h));
    QSqlDatabase myfile;
    myfile=QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/series.db");
    if(!myfile.open())
    {
        qDebug()<<("Failed to open the database");
    }
    else
    {
        qDebug()<<("Connected");
    }
}

series_delete::~series_delete()
{
    delete ui;
}
void series_delete::on_action_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from series where Genre='Action'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void series_delete::on_comedy_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from series where Genre='Comedy'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void series_delete::on_drama_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from series where Genre='Drama'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void series_delete::on_romantic_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from series where Genre='Romantic'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void series_delete::on_scifiction_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from series where Genre='Sci-fiction'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);

     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void series_delete::on_horror_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from series where Genre='Horror'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void series_delete::on_delete_2_clicked()
{
    QString name,del_name;
    name=ui->lineEdit->text();
    del_name=name.toUpper();
    QSqlQuery qry;
    qry.prepare("delete from series where Name='"+del_name+"'");
    if(qry.exec())
    {
        QMessageBox::information(this,"DELETED","Series is successfully deleted");
    }
}
