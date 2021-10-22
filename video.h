#ifndef VIDEO_H
#define VIDEO_H

#include <QDialog>

namespace Ui {
class video;
}

class video : public QDialog
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = nullptr);
    ~video();

private:
    Ui::video *ui;
};

#endif // VIDEO_H
