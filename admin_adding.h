#ifndef ADMIN_ADDING_H
#define ADMIN_ADDING_H

#include <QDialog>

namespace Ui {
class admin_adding;
}

class admin_adding : public QDialog
{
    Q_OBJECT

public:
    explicit admin_adding(QWidget *parent = nullptr);
    ~admin_adding();

private slots:


    void on_pushButton_6_clicked();

private:
    Ui::admin_adding *ui;
};

#endif // ADMIN_ADDING_H
