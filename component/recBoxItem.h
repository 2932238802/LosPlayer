#pragma once
#include <QWidget>
#include <QPropertyAnimation>
#include "common/myLog.h"

namespace Ui {
class RecBoxItem;
}

class RecBoxItem : public QWidget
{
    Q_OBJECT

public:
    explicit RecBoxItem(QWidget *parent = nullptr);
    ~RecBoxItem();
    // void enterEvent(QEnterEvent* event) override;
    // void leaveEvent(QEvent* event) override;
    bool eventFilter(QObject* watched,QEvent* event) override;
    void setText(const QString&str);
    void setBtnText(const QString&str);

private:
    Ui::RecBoxItem *ui;
    QRect l_rect;

};
