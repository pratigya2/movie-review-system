#ifndef SERIES_H
#define SERIES_H

#include <QDialog>

namespace Ui {
class series;
}

class series : public QDialog
{
    Q_OBJECT
    QString username_6;

public:
    explicit series(QString username_6,QWidget *parent = nullptr);
    ~series();
private slots:

    void receive_series(QString);



    void on_pushButton_2_clicked();


    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_13_clicked();
     void on_pushButton_10_clicked();



private:
    Ui::series *ui;
};

#endif // SERIES_H
