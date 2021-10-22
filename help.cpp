#include "help.h"
#include "ui_help.h"
#include <QMessageBox>
#include "file.h"
#include <QDebug>



help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
   // ui->setupUi(this);
    //help::showMaximized();
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/image (6).png");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));
}
help::~help()
{
    delete ui;
}
void help::on_pushButton_clicked()
{
    f = new file(this);
    hide();
    f->show();
}
//void help::on_pushButton_6_pressed()
//{
//    h = new helping(this);
//    hide();
//    h->show();
//}
void help::on_pushButton_6_clicked()
{
   view v;
   QString n = "What is C.C(Cinephile Choose)?";
   QString s;
    s = v.read(n);
    QMessageBox::information(this,"INFORMATION",s);
}

void help::on_pushButton_7_clicked()
{
    view v;
    QString n = "Is this free to use?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);

}

void help::on_pushButton_8_clicked()
{
    view v;
    QString n = "How can I access my information?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);

}

void help::on_pushButton_14_clicked()
{
    view v;
    QString n = "Can I not use the app without logging in?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);

}

void help::on_pushButton_16_clicked()
{
    view v;
    QString n = "Is my password encrypted?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);


}

void help::on_pushButton_10_clicked()
{
    view v;
    QString n = "How to view movies?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);

}


void help::on_pushButton_11_clicked()
{
    view v;
    QString n = "How are movies added?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);

}

void help::on_pushButton_12_clicked()
{
    view v;
    QString n = "What language movies and shows can be expected?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);

}


void help::on_pushButton_18_clicked()
{
    view v;
    QString n = "How are reviews classified?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);
}

void help::on_pushButton_19_clicked()
{
    view v;
    QString n = "Are all reviews and ratings counted?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);
}

void help::on_pushButton_20_clicked()
{
    view v;
    QString n = "Can we rate in terms of genre too?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);
}

void help::on_pushButton_17_clicked()
{
    view v;
    QString n = " Is there a word limit for review?";
    QString s;
     s = v.read(n);
     QMessageBox::information(this,"INFORMATION",s);
}
