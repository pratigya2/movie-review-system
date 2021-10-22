#include "addingseries.h"
#include "ui_addingseries.h"

addingseries::addingseries(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addingseries)
{
    ui->setupUi(this);
}

addingseries::~addingseries()
{
    delete ui;
}
