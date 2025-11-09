#include "listItem.h"
#include "ui_listitem.h"

ListItem::ListItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListItem)
{
    ui->setupUi(this);
    initUi();
}

ListItem::~ListItem()
{
    delete ui;
}

void ListItem::enterEvent(QEnterEvent *event)
{
    setStyleSheet("background-color: #EFEFEF");
    QWidget::enterEvent(event);
}

void ListItem::leaveEvent(QEvent *event)
{
    setStyleSheet("");
    QWidget::leaveEvent(event);
}

void ListItem::initUi()
{
    setStyleSheet(LISTITEM_STYLE);
    ui->vipLabel->setStyleSheet(LIST_ITEM_VIP_LABEL);
    ui->sqLabel->setStyleSheet(LIST_ITEM_SQ_LABAL);

}
