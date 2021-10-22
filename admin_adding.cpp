#include "admin_adding.h"
#include "ui_admin_adding.h"
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDebug>
#include <QSqlRecord>
#include<QMessageBox>
#include<QBuffer>
#include<QFileDialog>

admin_adding::admin_adding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_adding)
{
    ui->setupUi(this);
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

admin_adding::~admin_adding()
{
    delete ui;
}

void admin_adding::on_pushButton_6_clicked()
{
        QString name,summary,date,cast_members,ratings,genre,language,director,trailer,upp_name;
        name=ui->name->text();
        upp_name=name.toUpper();
        summary=ui->summary->text();
        date=ui->date->text();
        cast_members=ui->cast_members->text();
        ratings=ui->ratings->text();
        genre=ui->genre->text();
        language=ui->language->text();
        director=ui->cast_members_2->text();
        trailer=ui->trailer->text();
        int r;
        r=ratings.toInt();
        QString filename = QFileDialog::getOpenFileName(this, tr("choose"), "", tr("Images(*.png *.jpg *.jpeg *.bmp *.gif"));
            if (QString::compare(filename, QString()) != 0)
            {
                QImage image;
                bool valid = image.load(filename);
                if (valid)
                {
                    image = image.scaledToWidth(ui->image->width(), Qt::SmoothTransformation);
                    ui->image->setPixmap(QPixmap::fromImage(image));
                }
                QMessageBox::information(this,"SAVED","DATA IS SAVED");
            }
            QString dbName("C:/Users/user/Documents/New folder/qtcode/movie.db");
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName(dbName);
            db.open();
            QPixmap *inPixmap = new QPixmap(filename);
            QByteArray inByteArray;
            QBuffer inBuffer(&inByteArray);
            inBuffer.open(QIODevice::WriteOnly);
            inPixmap->save(&inBuffer, "PNG");
            QSqlQuery query = QSqlQuery(db);
            query.prepare("insert into movie values(:Name,:Summary,:Date,:Director,:Cast_members,:Ratings,:Image,:Genre,:Language,:Trailer_link)");
            query.bindValue(":Name",upp_name);
            query.bindValue(":Summary",summary);
            query.bindValue(":Date",date);
            query.bindValue(":Cast_members",cast_members);
            query.bindValue(":Ratings", r);
            query.bindValue(":Genre", genre);
            query.bindValue(":Language", language);
             query.bindValue(":Director", director);
              query.bindValue(":Trailer_link", trailer);
            query.bindValue(":Image", inByteArray);
            if (!query.exec())
                qDebug() << "Error inserting image into table:\n"
                         << query.lastError();
            db.close();
}

