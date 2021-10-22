#ifndef SERIES_DELETE_H
#define SERIES_DELETE_H

#include <QDialog>

namespace Ui {
class series_delete;
}

class series_delete : public QDialog
{
    Q_OBJECT

public:
    explicit series_delete(QWidget *parent = nullptr);
    ~series_delete();

private slots:
    void on_action_clicked();

    void on_comedy_clicked();

    void on_drama_clicked();

    void on_romantic_clicked();

    void on_scifiction_clicked();

    void on_horror_clicked();

    void on_delete_2_clicked();

private:
    Ui::series_delete *ui;
};

#endif // SERIES_DELETE_H
