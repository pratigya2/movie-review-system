#ifndef ADMIN_SERIES_ADDING_H
#define ADMIN_SERIES_ADDING_H

#include <QDialog>

namespace Ui {
class admin_series_adding;
}

class admin_series_adding : public QDialog
{
    Q_OBJECT

public:
    explicit admin_series_adding(QWidget *parent = nullptr);
    ~admin_series_adding();

private slots:


    void on_pushButton_6_clicked();

private:
    Ui::admin_series_adding *ui;
};

#endif // ADMIN_SERIES_ADDING_H
