#pragma once

#include <QMainWindow>
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>

namespace Ui {
class LosPlayer;
}


class LosPlayer : public QMainWindow
{
    Q_OBJECT

public:
    LosPlayer(QWidget *parent = nullptr);

    ~LosPlayer();
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    void initConnect();
    void initUi();

private:
    Ui::LosPlayer *ui;
    QPoint l_point;
};

