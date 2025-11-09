#pragma once

#include <QWidget>
#include "style/style.h"
#include "RecBoxItem.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QLayout>

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
    void onLeftBtnClicked();
    void onRightBtnClicked();
    void initConnect();
    void clearLayout(QLayout* layout);


private:
    Ui::RecBox *ui;
    int currentIndex;
    int count;
    QJsonArray l_btnTextAndText;
    int cols;
    int rows;
};


