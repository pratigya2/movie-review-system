#ifndef HELP_H
#define HELP_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "file.h"


#include <QDialog>

namespace Ui {
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();


private slots:
    void on_pushButton_clicked();
//    void on_pushButton_6_pressed();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_14_clicked();


    void on_pushButton_16_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::help *ui;
    file *f;
};
class view{
public:
    QString read(QString name){
        QString content;
        QString fromfile;
       QString s;
       int i;
        QFile file("C:/Users/user/Downloads/qt1-main/qt1-main/text.txt");
        if(!file.open(QFile::ReadOnly|QFile::Text|QIODevice::Append)){
           qInfo()<<("file doesnot ");
    }
        QTextStream in(&file);
        file.seek(0);
        while(!in.atEnd()){
             fromfile = in.readAll();
             content +=fromfile + '\n';
        }
        i=findIndex(content,name);
        s = findtext(i,content);
        qInfo()<<s;
        return s;
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
};
#endif // HELP_H
