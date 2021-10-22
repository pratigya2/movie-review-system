#include "language.h"
#include "ui_language.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include<QMessageBox>
#include<QBuffer>
#include<QPixmap>
#include<QFileDialog>

language::language(QString username_5,QWidget *parent) :
    QDialog(parent),
    username_5(username_5),
    ui(new Ui::language)
{
    ui->setupUi(this);
    // ui->username->setText(username_5);
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

language::~language()
{
    delete ui;
}


void language::on_nepali_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
     QSqlQuery qry;
     qry.prepare("select Image,Name,Date,Director,Genre,Ratings from movie where Language='Nepali' order by Ratings DESC");
     if (qry.exec())
     {
        modal->setQuery(qry);
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setItemDelegateForColumn(0,new ImageDelegates);
     ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableView->horizontalHeader()->setStretchLastSection(true);
     ui->tableView->verticalHeader()->setDefaultSectionSize(200);
     ui->tableView->setColumnWidth(0,300);
      }

}

void language::on_english_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from movie where Language='English' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegates);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language::on_chinese_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from movie where Language='Chinese' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegates);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language::on_thai_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from movie where Language='Thai'order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegates);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language::on_korean_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from movie where Language='Korean' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegates);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language::on_hindi_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from movie where Language='Hindi' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegates);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language::on_turkish_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from movie where Language='Turkish' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegates);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language::on_japanese_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from movie where Language='Japanese' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegates);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}
void language::on_tableView_activated(const QModelIndex &index)
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

                temp_movie = new movie(username_5,this);
                temp_movie->show();
                qDebug()<<"signal";
                connect(this, SIGNAL(send_movie(QString)), temp_movie, SLOT(receive_movie(QString)));
                emit send_movie(name);
                qDebug()<<"slot";
            }
        }
        }
    }
