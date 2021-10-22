#ifndef VIEWHELP_H
#define VIEWHELP_H
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class viewhelp;
}

class viewhelp : public QDialog
{
    Q_OBJECT

public:
    explicit viewhelp(QWidget *parent = nullptr);
    ~viewhelp();

private:
    Ui::viewhelp *ui;
};
class view_help{
public:
    QString read(QString qsn){
        QString fromfile;
        QString content;
        QString r;
        int i;
    QFile file("C:/Users/user/Documents/New folder/text.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text|QIODevice::Append)){
       qInfo()<<("file doesnot ");
}
    QTextStream in(&file);
    file.seek(0);
    while(!in.atEnd()){
         fromfile = in.readAll();
         content +=fromfile + '\n';
    }
    i = findIndex(content,qsn);
    r = findtext(i,content);
    return r;
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
    QString findtext(int i,QString y){
        int x;
        QString desired_text;
        for ( x = i ; y[i] != ':'; i++)
        {
            desired_text+=y[i];
        }
        return desired_text;
    }


};

#endif // VIEWHELP_H
