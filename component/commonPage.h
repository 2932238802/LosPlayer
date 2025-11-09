#pragma once
#include "style/style.h"
#include "common/myLog.h"
#include <QWidget>
#include "listItem.h"

namespace Ui {
class CommonPage;
}

class CommonPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommonPage(QWidget *parent = nullptr);
    void setMusicPageUi(const QString& str,const QString&path);
    ~CommonPage();

private:
    void initUi();


private:
    Ui::CommonPage *ui;
};


