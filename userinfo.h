#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>

namespace Ui {
class userinfo;
}

class userinfo : public QDialog
{
    Q_OBJECT

public:
    explicit userinfo(QWidget *parent = nullptr);
    ~userinfo();

public slots:
    void receive_user_info(QString);

private:
    Ui::userinfo *ui;
};

#endif // USERINFO_H
