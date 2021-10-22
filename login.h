#ifndef LOGIN_H
#define LOGIN_H

#include "movie.h"
#include <QDialog>
#include"userinfo.h"
#include"moviemenu.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

//signals:
//     void send(QString);
signals:
void send_d(QString);


private slots:


    void on_pushButton_3_clicked();



private:
    Ui::login *ui;
    movie *mov;
    moviemenu *Moviemenu;
    userinfo *UserInfo;

};

#endif // LOGIN_H
