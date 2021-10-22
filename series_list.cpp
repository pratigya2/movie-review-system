#include "series_list.h"
#include "ui_series_list.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include "series.h"
#include<QPixmap>

series_list::series_list(QString username_11,QWidget *parent) :
    QDialog(parent),username_11(username_11),
    ui(new Ui::series_list)
{
    QString qry_string, ui_label;
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w, h));
    QSqlDatabase myfile;
    myfile = QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/Series.db");
    if (!myfile.open())
    {
        qDebug() << ("Failed to open the database");
    }
    else
    {
        qDebug() << ("Connected");
    }


    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select Name, Date, Ratings, Genre,Image from series order by Ratings DESC");
    if (qry.exec())
    {
        model->setQuery(qry);

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        qDebug()<<"case 0 query executed";
    }

    qry.prepare("select Image,Name,Date,Director,Language,Ratings from series order by Ratings DESC");
    if (qry.exec())
    {
       model->setQuery(qry);
       ui->tableView->setModel(model);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegating);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }
}


series_list::~series_list()
{
    delete ui;
}
void series_list::on_tableView_activated(const QModelIndex &index)
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

            temp_series = new series(username_11,this);
            temp_series->show();
            qDebug()<<"signal";
            connect(this, SIGNAL(send_series(QString)), temp_series, SLOT(receive_series(QString)));
            emit send_series(name);
            qDebug()<<"slot";
        }
    }
    }
}

