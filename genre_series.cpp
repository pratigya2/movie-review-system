#include "genre_series.h"
#include "ui_genre_series.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include<QMessageBox>
#include<QBuffer>
#include<QFileDialog>
#include<QPixmap>

genre_series::genre_series(QString username_7,QWidget *parent) :
    QDialog(parent),
    username_7(username_7),
    ui(new Ui::genre_series)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));

    QSqlDatabase myfile;
    myfile=QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/Series.db");
    if(!myfile.open())
    {
        qDebug()<<("Failed to open the database");
    }
    else
    {
        qDebug()<<("Connected");
    }
}

genre_series::~genre_series()
{
    delete ui;
}
void genre_series::on_comedy_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from series where Genre='Comedy' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImagesDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }
}

void genre_series::on_action_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from series where Genre='Action' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImagesDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
    }
}

void genre_series::on_drama_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from series where Genre='Drama' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImagesDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);

     }

}

void genre_series::on_horror_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from series where Genre='Horror' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImagesDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);

     }

}

void genre_series::on_scifiction_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from series where Genre='Sci-fiction' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImagesDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }
}
void genre_series::on_romantic_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from series where Genre='Romantic' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImagesDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }
}
void genre_series::on_tableView_activated(const QModelIndex &index)
    {
        QString temp = ui->tableView->model()->data(index).toString();
        qDebug() << temp;
        QSqlQuery qry;
        qry.prepare("select * from series");
        if(qry.exec())
        {
        while(qry.next())
        {
            QString name=qry.value(0).toString();
            if(name==temp)
            {
                temp_series = new series(username_7,this);
                temp_series->show();
                qDebug()<<"signal";
                connect(this, SIGNAL(send_series(QString)), temp_series, SLOT(receive_series(QString)));
                emit send_series(name);
                qDebug()<<"slot";
            }
        }
        }
    }
