#include "genre.h"
#include "ui_genre.h"
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
#include "movie.h"

genre::genre(QString username_4,QWidget *parent) :
    QDialog(parent),
    username_4(username_4),
    ui(new Ui::genre)
{
    ui->setupUi(this);
    //ui->username->setText(username_4);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));

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
genre::~genre()
{
    delete ui;
}
void genre::on_comedy_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from movie where Genre='Comedy' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }
}

void genre::on_action_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from movie where Genre='Action' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
    }
}

void genre::on_drama_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from movie where Genre='Drama' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);

     }

}

void genre::on_horror_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from movie where Genre='Horror' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);

     }

}

void genre::on_scifiction_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from movie where Genre='Sci-fiction' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }
}
void genre::on_romantic_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Language,Ratings from movie where Genre='Romantic' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegate);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void genre::on_tableView_activated(const QModelIndex &index)
    {
        QString temp = ui->tableView->model()->data(index).toString();
        qDebug() << temp;
        QSqlQuery qry;
        qry.prepare("select * from movie");
        if(qry.exec())
        {
        while(qry.next())
        {
            QString name=qry.value(0).toString();
            if(name==temp)
            {

                temp_movie = new movie(username_4,this);
                temp_movie->show();
                qDebug()<<"signal";
                connect(this, SIGNAL(send_movie(QString)), temp_movie, SLOT(receive_movie(QString)));
                emit send_movie(name);
                qDebug()<<"slot";
            }
        }
        }
    }


