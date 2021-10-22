#ifndef MOVIES_H
#define MOVIES_H

#include <QDialog>

namespace Ui {
class movies;
}

class movies : public QDialog
{
    Q_OBJECT

public:
    explicit movies(QWidget *parent = nullptr);
    ~movies();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::movies *ui;
};

#endif // MOVIES_H
