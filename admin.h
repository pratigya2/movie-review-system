#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include"admin_adding.h"
#include "movie.h"
#include "series.h"

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::admin *ui;
    admin_adding *add;
    movie *mov;
    series *s;
};

#endif // ADMIN_H
