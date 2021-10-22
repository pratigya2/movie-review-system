#include "movies.h"
#include "ui_movies.h"
#include <QFile>
#include <QTextStream>

movies::movies(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::movies)
{
    ui->setupUi(this);
}

movies::~movies()
{
    delete ui;
}

void movies::on_pushButton_clicked()
{
    QFile file("C:/Users/user/Documents/New folder/Movies.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        return;
}
    QTextStream in(&file);
    while(!in.atEnd()){
QString text = in.readAll();
ui->plainTextEdit->setPlainText(text);
    }
file.close();

}


void movies::on_pushButton_2_clicked()
{
    QFile File("C:/Users/user/Documents/New folder/Movies.txt");
    if(!File.open(QFile::WriteOnly|QFile::Text)){
        return;
    }
    QString text = ui->plainTextEdit->toPlainText();
    QTextStream out(&File);
    out<<text;
    File.flush();
    File.close();

}

