#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "help.h"
#include "file.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QHash>
#include <QMultiHash>
#include <QList>
#include<QtSql>
#include <QChar>
#include<QDebug>
#include<QRandomGenerator>
#include<QFileInfo>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlRecord>
#include<QSqlQueryModel>
#include "movie.h"
#include "login.h"
#include "genre.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString UUsername;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

   // void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
        help *h;
        file *f;
        movie *m;
        login *l;
        genre *g;
};
class User{
public:
void write_data(QString fname,QString lname,QString age,QString username,QString pw)
{
    User u;
    QString encrypted;
    QFile File("C:/Users/user/Downloads/qt1-main/qt1-main/myfile.txt");
    if(!File.open(QFile::WriteOnly|QFile::Text|QIODevice::Append)){
        return;
    }
int i ;
    QTextStream out(&File);
    QMultiHash <QString,QString>check;
     encrypted= u.encrypt(pw);
    check.insert(username,lname);
    check.insert(username,age);
    check.insert(username,fname);
   check.insert(username,encrypted);
   //check.insert(fname,username);
    out<<username<<":";
    QList<QString>values = check.values(username);
    for(i=0;i<values.size();i++){
        out<<values.at(i)<<":";
    }
    out<<'\n';

    File.flush();
    File.close();
    fflush(stdin);
    }
int login(QString line,QString pw){
    QString content;
    QString fromfile;
   QString s;
   User u;
   QString encrypted;
  encrypted = u.encrypt(pw);
  qInfo()<<encrypted;
    QFile file("C:/Users/user/Downloads/qt1-main/qt1-main/myfile.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text|QIODevice::Append)){
       qInfo()<<("file doesnot ");
}
    QTextStream in(&file);
    file.seek(0);
    while(!in.atEnd()){
         fromfile = in.readAll();
         content +=fromfile + '\n';
    }
        qInfo()<<(content);
         if((content.contains(line))){
             int a;
             a = findIndex(content,line);
             qInfo()<<(a);
             a = a +line.length();
             a = a+1;
            s = u.findtext(a,content);
            qInfo()<<(s);
            if(s.compare(encrypted,Qt::CaseSensitive)==0){
             return 1;
             }
            else{
                return 0;
            }
         }
         else{
           return 0;
     }
}
QString findtext(int i,QString y){
    int x;
    QString desired_text;
    for ( x = i ; y[i] != ':'; i++)
    {
        desired_text+=y[i];
    }
    return desired_text;
}
int findIndex(QString src, QString str)
{
    int count = 0;
    int i;
    for ( i = 0; i < src.length(); i++)
    {
        if (src[i] == str[0])
        {
            count = 0;
            for (int k = 0; k < str.length(); k++)
            {
                if (src[i + k] == str[k])
                    count++;
            }
            if (count == str.length())
                return i;
        }
    }
}
QString encrypt(QString password){
            int i;
            int ascii;
            int k;
QString aux_password;
    QString encrypted_password2;
     QString final_encryption;
    for(i=0;i<(password.length()*2);i++){
        ascii = password[i].toLatin1();
        k = ascii + 7;
        aux_password[i] = QChar(k);
        qInfo()<<aux_password;
        encrypted_password2[2*i+1]=aux_password[i];
        encrypted_password2[2*(i)]= QChar(i + 189);
        final_encryption[i]=encrypted_password2[i];
    }
    return final_encryption;


}
};
#endif // MAINWINDOW_H
