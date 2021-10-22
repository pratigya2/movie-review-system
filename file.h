#ifndef FILE_H
#define FILE_H
#include <QDialog>

namespace Ui {
class file;
}

class file : public QDialog
{
    Q_OBJECT

public:
    explicit file(QWidget *parent = nullptr);
    ~file();

private slots:
    void on_pushButton_8_clicked();

private:
    Ui::file *ui;
};

#endif // FILE_H
