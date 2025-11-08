#include "btFrom.h"
#include "ui/ui_btfrom.h"


BtFrom::BtFrom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BtFrom)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground, true);

    showLineBox(false);

    line1Animation = new QPropertyAnimation(ui->line_1, "geometry", this);
    line1Animation->setDuration(1000);
    line1Animation->setKeyValueAt(0, QRect(13,20,3,0));
    line1Animation->setKeyValueAt(0.5, QRect(13,0,2,20));
    line1Animation->setKeyValueAt(1, QRect(13,20,2,0));
    line1Animation->setLoopCount(-1);
    line1Animation->start();

    line2Animation = new QPropertyAnimation(ui->line_2, "geometry", this);
    line2Animation->setDuration(1100);
    line2Animation->setKeyValueAt(0, QRect(0,20,3,0));
    line2Animation->setKeyValueAt(0.5, QRect(0,0,3,20));
    line2Animation->setKeyValueAt(1, QRect(0,20,3,0));
    line2Animation->setLoopCount(-1);
    line2Animation->start();

    line3Animation = new QPropertyAnimation(ui->line_3, "geometry", this);
    line3Animation->setDuration(1200);
    line3Animation->setKeyValueAt(0, QRect(26,20,3,0));
    line3Animation->setKeyValueAt(0.5, QRect(26,0,3,20));
    line3Animation->setKeyValueAt(1, QRect(26,20,3,0));
    line3Animation->setLoopCount(-1);
    line3Animation->start();

    line4Animation = new QPropertyAnimation(ui->line_4, "geometry", this);
    line4Animation->setDuration(900);
    line4Animation->setKeyValueAt(0, QRect(39,20,3,0));
    line4Animation->setKeyValueAt(0.5, QRect(39,0,3,20));
    line4Animation->setKeyValueAt(1, QRect(39,20,3,0));
    line4Animation->setLoopCount(-1);
    line4Animation->start();


}

//////////////////
/// \brief BtFrom::setSelfStyle
/// \param str
///
void BtFrom::setSelfStyle(const QString &str,const QString&text)
{
    ui->icon->setText(str);
    ui->text->setText(text);
}
//////////////////


//////////////////
void BtFrom::setPageId(int page_id)
{
    this->pageId = page_id;
}
//////////////////


//////////////////
/// \brief BtFrom::showLineBox
/// \param is_true
///
void BtFrom::showLineBox(bool is_true)
{
    if(is_true)
    {
        this->ui->lineBox->show();
    }
    else{
        this->ui->lineBox->hide();
    }
}
//////////////////


//////////////////
/// \brief BtFrom::~BtFrom
///
BtFrom::~BtFrom()
{
    delete ui;
}
//////////////////



//////////////////
/// \brief BtFrom::mousePressEvent
/// \param event
///
void BtFrom::mousePressEvent(QMouseEvent *event)
{
    emit _pageId(pageId);
}
//////////////////












