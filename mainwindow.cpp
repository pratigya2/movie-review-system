#include"movielist.h"
#include "mainwindow.h"
#include <QDir>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include<QDebug>
#include "help.h"
#include "file.h"
#include "movie.h"
#include "login.h"
#include"admin.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
//    ui->setupUi(this);
    MainWindow::showMaximized();
    ui->setupUi(this);
    setWindowTitle("CC");
    QPixmap pix("C:/Users/user/Downloads/qt1-main/qt1-main/blurr.jpeg");
    int w = ui->label->width();
       int h =ui->label->height();
      ui->label->setPixmap(pix.scaled(w,h));

    //ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_2_clicked()
{ f = new file(this);
    hide();
    f->show();
    }
void MainWindow::on_pushButton_4_clicked()
{
  close();
}
void MainWindow::on_pushButton_3_clicked()
{
    h = new help(this);
    h ->show();
}
QString name="name";

void MainWindow::on_pushButton_clicked()
{
    m = new movie(name,this);
    hide();
    m->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    l = new login(this);
        hide();
        l->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    g = new genre(name,this);
        hide();
        g->show();

}

void MainWindow::on_pushButton_7_clicked()
{
    admin ad;
    hide();
    ad.exec();

}



//void MainWindow::on_pushButton_9_clicked()
//{
//    Movielist movie_list;
//    movie_list.setModal(true);
//    hide();
//    movie_list.exec();
//}

