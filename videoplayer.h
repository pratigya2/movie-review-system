#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QDialog>

namespace Ui {
class videoplayer;
}

class videoplayer : public QDialog
{
    Q_OBJECT

public:
    explicit videoplayer(QWidget *parent = nullptr);
    ~videoplayer();

private:
    Ui::videoplayer *ui;
};

#endif // VIDEOPLAYER_H
