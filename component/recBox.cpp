#include "recBox.h"
#include "ui_recBox.h"

//////////////////////////
/// \brief RecBox::RecBox
/// \param parent
///
RecBox::RecBox( QWidget *parent)
    : QWidget(parent),cols(1),rows(4)
    , ui(new Ui::RecBox)
{
    ui->setupUi(this);
    ui->rightBtn->setStyleSheet(RECBOX_BTN);
    ui->leftBtn->setStyleSheet(RECBOX_BTN);
}
//////////////////////////



//////////////////////////
/// \brief RecBox::initRecBoxUi
/// \param data
/// \param row
///
void RecBox::initRecBoxUi(QJsonArray data, int row)
{
    if(2 == row)
    {
        // 下面这个模块
        cols = 8;
    }
    else if(1 == row)
    {
        // 上面这个
        ui->recListDown->hide();
        cols = 4;
    }
    else{
        LOG() << "错误行数";
    }

    l_btnTextAndText = data;

    // TODO:
    createRecBoxItem();

}
//////////////////////////


//////////////////////////
/// \brief RecBox::~RecBox
///
RecBox::~RecBox()
{
    delete ui;
}
//////////////////////////



//////////////////////////
/// \brief RecBox::createRecBoxItem
///
void RecBox::createRecBoxItem()
{
    for(int i =0 ; i< cols ;i++)
    {
        RecBoxItem* item = new RecBoxItem();

        QJsonObject oj = l_btnTextAndText[i].toObject();

        item->setBtnText(oj["btn_text"].toString());
        item->setText(oj["text"].toString());

        ui->recListUpHlayout->addWidget(item);
    }
}
//////////////////////////






