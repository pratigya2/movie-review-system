#include "downloader.h"
#include "ui_downloader.h"
#include <QHttp2Configuration>
#include <QFile>

downloader::downloader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::downloader)
{
    ui->setupUi(this);
}

downloader::~downloader()
{
    delete ui;
}
