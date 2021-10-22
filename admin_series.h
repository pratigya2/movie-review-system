#ifndef ADMIN_SERIES_H
#define ADMIN_SERIES_H

#include <QDialog>

namespace Ui {
class admin_series;
}

class admin_series : public QDialog
{
    Q_OBJECT

public:
    explicit admin_series(QWidget *parent = nullptr);
    ~admin_series();

private slots:


    void on_pushButton_6_clicked();

private:
    Ui::admin_series *ui;
};

#endif // ADMIN_SERIES_H
