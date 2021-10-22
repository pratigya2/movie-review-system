#ifndef ADDINGSERIES_H
#define ADDINGSERIES_H

#include <QDialog>

namespace Ui {
class addingseries;
}

class addingseries : public QDialog
{
    Q_OBJECT

public:
    explicit addingseries(QWidget *parent = nullptr);
    ~addingseries();

private:
    Ui::addingseries *ui;
};

#endif // ADDINGSERIES_H
