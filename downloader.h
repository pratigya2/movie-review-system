#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QDialog>

namespace Ui {
class downloader;
}

class downloader : public QDialog
{
    Q_OBJECT

public:
    explicit downloader(QWidget *parent = nullptr);
    ~downloader();

private:
    Ui::downloader *ui;
};

#endif // DOWNLOADER_H
