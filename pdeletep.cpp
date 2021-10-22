#include "pdeletep.h"
#include "ui_pdeletep.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include<QMessageBox>
#include<QBuffer>
#include<QFileDialog>
pdeletep::pdeletep(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pdeletep)
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
pdeletep::~pdeletep()
{
    delete ui;
}

void pdeletep::on_action_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Action'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void pdeletep::on_comedy_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Comedy'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void pdeletep::on_drama_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Drama'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void pdeletep::on_romantic_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Romantic'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void pdeletep::on_scifiction_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Sci-fiction'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);

     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void pdeletep::on_horror_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select * from movie where Genre='Horror'");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->listView->setModel(modal);
     }
    if(!qry.exec()){
        qDebug()<<"Not done";
    }
}
void pdeletep::on_delete_2_clicked()
{
    QString name,del_name;
    name=ui->lineEdit->text();
    del_name=name.toUpper();
    QSqlQuery qry;
    qry.prepare("delete from movie where Name='"+del_name+"'");
    if(qry.exec())
    {
        qDebug()<<"Deleted";
    }
}
