#include "language_series.h"
#include "ui_language_series.h"
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
language_series::language_series(QString username_8,QWidget *parent) :
    QDialog(parent),
    username_8(username_8),
    ui(new Ui::language_series)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
     int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));

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

language_series::~language_series()
{
    delete ui;
}

void language_series::on_nepali_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
     QSqlQuery qry;
     qry.prepare("select Image,Name,Date,Director,Genre,Ratings from series where Language='Nepali' order by Ratings DESC");
     if (qry.exec())
     {
        modal->setQuery(qry);
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setItemDelegateForColumn(0,new ImageDelegated);
     ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableView->horizontalHeader()->setStretchLastSection(true);
     ui->tableView->verticalHeader()->setDefaultSectionSize(200);
     ui->tableView->setColumnWidth(0,300);
      }

}

void language_series::on_english_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from series where Language='English' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegated);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language_series::on_chinese_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from series where Language='Chinese' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegated);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language_series::on_thai_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from series where Language='Thai'order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegated);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language_series::on_korean_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from series where Language='Korean' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegated);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language_series::on_hindi_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from series where Language='Hindi' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegated);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language_series::on_turkish_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from movie where Language='Turkish' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegated);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}

void language_series::on_japanese_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("select Image,Name,Date,Director,Genre,Ratings from series where Language='Japanese' order by Ratings DESC");
    if (qry.exec())
    {
       modal->setQuery(qry);
       ui->tableView->setModel(modal);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegated);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }

}
void language_series::on_tableView_activated(const QModelIndex &index)
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
                temp_series = new series(username_8,this);
                temp_series->show();
                qDebug()<<"signal";
                connect(this, SIGNAL(send_series(QString)), temp_series, SLOT(receive_series(QString)));
                emit send_series(name);
                qDebug()<<"slot";
            }
        }
        }
    }
