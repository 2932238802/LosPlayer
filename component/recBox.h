#pragma once

#include <QWidget>
#include "style/style.h"
#include "RecBoxItem.h"
#include <QJsonArray>
#include<QJsonObject>

namespace Ui {
class RecBox;
}

class RecBox : public QWidget
{
    Q_OBJECT

public:
    explicit RecBox(QWidget *parent = nullptr);
    void initRecBoxUi(QJsonArray data,int row);
    ~RecBox();

private:
    void createRecBoxItem();


private:
    Ui::RecBox *ui;
    QJsonArray l_btnTextAndText;
    int cols;
    int rows;
};


