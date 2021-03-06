#include "movielist.h"
#include "ui_movielist.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include "movie.h"
#include<QPixmap>
Movielist::Movielist(QString username_2,QWidget *parent) : QDialog(parent),username_2(username_2),
                                        ui(new Ui::Movielist)
{
    QString qry_string, ui_label;
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Downloads/image (7).png");
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(pix.scaled(w, h));
    QSqlDatabase myfile;
    myfile = QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/user/Documents/New folder/qtcode/movie.db");
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
    qry.prepare("select Name, Date, Ratings, Genre,Image from movie order by Ratings DESC");
    if (qry.exec())
    {
        model->setQuery(qry);

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        qDebug()<<"case 0 query executed";
    }

    qry.prepare("select Image,Name,Date,Director,Language,Ratings from movie order by Ratings DESC");
    if (qry.exec())
    {
       model->setQuery(qry);
       ui->tableView->setModel(model);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->setItemDelegateForColumn(0,new ImageDelegatess);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setDefaultSectionSize(200);
    ui->tableView->setColumnWidth(0,300);
     }
}
Movielist::~Movielist()
{
    delete ui;
}

void Movielist::on_tableView_activated(const QModelIndex &index)
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

            temp_movie = new movie(username_2,this);
            temp_movie->show();
            qDebug()<<"signal";
            connect(this, SIGNAL(send_movie(QString)), temp_movie, SLOT(receive_movie(QString)));
            emit send_movie(name);
            qDebug()<<"slot";
        }
    }
    }
}

