#pragma once

#include <QMainWindow>
#include<QMouseEvent>
#include <QStyle>
#include<QGraphicsDropShadowEffect>
#include <QRandomGenerator>
#include <QJsonObject>
#include <QJsonArray>
#include"common/myLog.h"
#include"style/style.h"

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
    QJsonArray initNameAndPng();
    QString generateRandStr(int lenth);


public slots:
    void onGetPageid(int page_id);

private:
    QMap<int,QString> btnIdAndName;
    QString lastBtn;
    Ui::LosPlayer *ui;
    QPoint l_point;
};

