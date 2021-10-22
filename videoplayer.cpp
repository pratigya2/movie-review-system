#include <QMediaPLayer>
#include <QVideoWidgets>
#include "videoplayer.h"
#include "ui_videoplayer.h"

videoplayer::videoplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::videoplayer)
{
    ui->setupUi(this);
}

videoplayer::~videoplayer()
{
    delete ui;
}
