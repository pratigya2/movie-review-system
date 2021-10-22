#include "series.h"
#include "ui_series.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>
#include"serieslist.h"
series::series(QString username_6,QWidget *parent) :
    QDialog(parent),
    username_6(username_6),
    ui(new Ui::series)
{
    ui->setupUi(this);
    setWindowTitle("CC");
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
    qDebug()<<"Hello pratigey";
}

series::~series()
{
    delete ui;
}
int b;
int rating_updates;
void series::on_pushButton_5_clicked()
{
    b++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_5->setIcon(*ico);
    ui->pushButton_5->setCheckable(true);
}
void series::on_pushButton_6_clicked()
{
    b++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_6->setIcon(*ico);
    ui->pushButton_6->setCheckable(true);
}

void series::on_pushButton_7_clicked()
{
    b++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_7->setIcon(*ico);
    ui->pushButton_7->setCheckable(true);
}

void series::on_pushButton_8_clicked()
{
    b++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_8->setIcon(*ico);
    ui->pushButton_8->setCheckable(true);
}
void series::on_pushButton_9_clicked()
{
    b++;
    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png"));
    ui->pushButton_9->setIcon(*ico);
    ui->pushButton_9->setCheckable(true);
    qInfo()<<b;
}
void series::receive_series(QString series_name)
{
    QPixmap pix("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png");
    int width  = ui->label_9->width();
       int height =ui->label_9->height();
      ui->label_9->setPixmap(pix.scaled(width,height));
    qDebug()<<"movie.cpp";
    ui->lineEdit->setText(series_name);
    QSqlQuery qry;
qry.prepare("SELECT * FROM series where name ='"+series_name+"'");
if(qry.exec())
{
   while(qry.next())
   {
       QString name= qry.value(0).toString();
       QString summary= qry.value(1).toString();
       QString date= qry.value(2).toString();
       QString director= qry.value(3).toString();
       QString cast= qry.value(4).toString();
       QString rating= qry.value(5).toString();
       QString trailer= qry.value(9).toString();
       QByteArray outByteArray = qry.value(6).toByteArray();
       QPixmap outPixmap = QPixmap();
       outPixmap.loadFromData( outByteArray );
       ui->label_2->setText(name);
       ui->label_3->setText("RELEASED DATE");
       ui->label_4->setText(date);
       ui->label_5->setText("SUMMARY");
       ui->textBrowser->setText(summary);
       ui->label_6->setText(cast);
       ui->label_10->setText(director);
       ui->label_11->setText("CAST MEMBERS");
       ui->label_12->setText("DIRECTOR NAME");
       ui->pushButton_10->setText("TRAILER LINK");
       ui->rate->setText(rating);
       int x = ui->image->width();
          int y =ui->image->height();
       outPixmap = outPixmap.scaledToWidth(ui->image->width(), Qt::SmoothTransformation);
      ui->image->setPixmap( outPixmap.scaled(x,y) );
   }
}
if(!qry.exec())
{
   QMessageBox::warning(this,"ERROR","Series not found");
}
QSqlQueryModel *modal2=new QSqlQueryModel;
QSqlQuery qry2;
qry2.prepare("select username,review,rating from review_table where series_name = ?");
qry2.addBindValue(series_name);
if(qry2.exec())
{
   while(qry2.next())
     {
       modal2->setQuery(qry2);
       ui->tableView->setModel(modal2);
       ui->tableView->resizeColumnsToContents();
      }
}
}
void series::on_pushButton_2_clicked()
{
    QPixmap pix("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-WfdnljkZdE.png");
    int width  = ui->label_9->width();
       int height =ui->label_9->height();
      ui->label_9->setPixmap(pix.scaled(width,height));
     QString series_name;
     QString upper;
     series_name=ui->lineEdit->text();
     upper = series_name.toUpper();
         QSqlQuery qry;
    qry.prepare("SELECT * FROM series where name ='"+upper+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            QString name= qry.value(0).toString();
            QString summary= qry.value(1).toString();
            QString date= qry.value(2).toString();
            QString director= qry.value(3).toString();
            QString cast= qry.value(4).toString();
            QString rating= qry.value(5).toString();
            QString trailer= qry.value(9).toString();
            QByteArray outByteArray = qry.value(6).toByteArray();
            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData( outByteArray );
            ui->label_2->setText(name);
            ui->label_3->setText("RELEASED DATE");
            ui->label_4->setText(date);
            ui->label_5->setText("SUMMARY");
            ui->textBrowser->setText(summary);
            ui->label_6->setText(cast);
            ui->label_10->setText(director);
            ui->label_11->setText("CAST MEMBERS");
            ui->label_12->setText("DIRECTOR NAME");
            ui->pushButton_10->setText("TRAILER LINK");
            ui->rate->setText(rating);
            int x = ui->image->width();
               int y =ui->image->height();
            outPixmap = outPixmap.scaledToWidth(ui->image->width(), Qt::SmoothTransformation);
           ui->image->setPixmap( outPixmap.scaled(x,y) );
        }
    }
   else
    {
        QMessageBox::warning(this,"ERROR","Series not found");
    }
    QSqlQueryModel *modal2=new QSqlQueryModel;
    QSqlQuery qry2;
     qry2.prepare("select username,rating,review from review_table where series_name = ?");
     qry2.addBindValue(upper);
     if(qry2.exec())
     {
        while(qry2.next())
          {
            modal2->setQuery(qry2);
            ui->tableView->setModel(modal2);
            ui->tableView->resizeColumnsToContents();
            ui->tableView->setWordWrap(true);
           ui->tableView->setTextElideMode(Qt::ElideLeft);
               ui->tableView->setColumnWidth(1,500);
           }
     }
}
void series::on_pushButton_13_clicked()
{

    QString series_name,username,review,rating;
    QString upper;
    series_name=ui->lineEdit->text();
    upper = series_name.toUpper();
    //a  = rating.toInt();
    qInfo()<<"rating"<<b;
    username=username_6;
    review=ui->add_review->text();
    QSqlQuery qry;
    qry.prepare("insert into review_table values('"+username+"','"+upper+"','"+review+"',?)");
    qry.addBindValue(b);
    if(qry.exec())
    {
        QMessageBox::information(this,"INSERTED","Review and rating inserted");
            QSqlQuery qry2;
             qry2.prepare("select * from series where name='"+upper+"' ");
             if(qry2.exec())
             {
                 while(qry2.next())
                 {
                     int demo5 =qry2.value(5).toInt();
                     rating_updates=0.5*(demo5+b);
                 }
             }
          b = 0;
    }
    QSqlQuery qry3;
      qry3.prepare("update series set Ratings=? where name='"+upper+"'");
      qry3.addBindValue(rating_updates);
      qDebug()<<rating_updates;
      if (!qry3.exec())
          qDebug() << "Error inserting rating into table:\n"
                   << qry3.lastError();

    QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("C:/Users/user/Documents/New folder/qtcode/imgonline-com-ua-shape-N6h4pB3vkwR9zPY.png"));
    ui->pushButton_5->setIcon(*ico);
    ui->pushButton_5->setCheckable(true);
    ui->pushButton_6->setIcon(*ico);
    ui->pushButton_6->setCheckable(true);
    ui->pushButton_7->setIcon(*ico);
    ui->pushButton_7->setCheckable(true);
    ui->pushButton_8->setIcon(*ico);
    ui->pushButton_8->setCheckable(true);
    ui->pushButton_9->setIcon(*ico);
    ui->pushButton_9->setCheckable(true);

}
void series::on_pushButton_10_clicked()
{
    QString upper,series_name;
    series_name=ui->lineEdit->text();
    upper = series_name.toUpper();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM series where name ='"+upper+"'");
    if(qry.exec())
    {
   while(qry.next())
   {
     QString trailer= qry.value(9).toString();
     QDesktopServices::openUrl(QUrl(trailer));
    }
    }
}
