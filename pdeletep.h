#ifndef PDELETEP_H
#define PDELETEP_H

#include <QDialog>

namespace Ui {
class pdeletep;
}

class pdeletep : public QDialog
{
    Q_OBJECT

public:
    explicit pdeletep(QWidget *parent = nullptr);
    ~pdeletep();

private slots:
    void on_action_clicked();

    void on_comedy_clicked();

    void on_drama_clicked();

    void on_romantic_clicked();

    void on_scifiction_clicked();

    void on_horror_clicked();

    void on_delete_2_clicked();

private:
    Ui::pdeletep *ui;
};

#endif // PDELETEP_H
