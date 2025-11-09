#pragma once
#include <QWidget>
#include <QEvent>
#include "style/style.h"


namespace Ui {
class ListItem;
}

class ListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ListItem(QWidget *parent = nullptr);
    ~ListItem();

    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

private:
    void initUi();

private:
    Ui::ListItem *ui;
};

