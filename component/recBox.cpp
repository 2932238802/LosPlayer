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
    initConnect();
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
    // LOG() << "void RecBox::initRecBoxUi(QJsonArray data, int row)" ;


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


    currentIndex = 0;
    count = data.size()/cols;
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
    clearLayout(ui->recListDownHlayout);
    clearLayout(ui->recListUpHlayout);



    if(cols == 4)
    {
        for(int i = 4 * currentIndex ; i< 4 * currentIndex  + 4 ;i++)
        {
            RecBoxItem* item = new RecBoxItem();

            QJsonObject oj = l_btnTextAndText[i].toObject();

            item->setBtnText(oj["btn_text"].toString());
            item->setText(oj["text"].toString());

            ui->recListUpHlayout->addWidget(item);
        }
    }
    else{

        for(int i = 4 * currentIndex ; i< 4 * currentIndex  + 4 ;i++)
        {
            RecBoxItem* item = new RecBoxItem();
            QJsonObject oj = l_btnTextAndText[i].toObject();
            item->setBtnText(oj["btn_text"].toString());
            item->setText(oj["text"].toString());
            ui->recListUpHlayout->addWidget(item);
        }
        for(int i = 4 * currentIndex  + 4 ; i < 4 * currentIndex  + 8 ;i++)
        {
            RecBoxItem* item = new RecBoxItem();
            QJsonObject oj = l_btnTextAndText[i].toObject();
            item->setBtnText(oj["btn_text"].toString());
            item->setText(oj["text"].toString());
            ui->recListDownHlayout->addWidget(item);
        }
    }

}
//////////////////////////



//////////////////////////
/// \brief RecBox::onLeftBtnClicked
///
void RecBox::onLeftBtnClicked()
{
    currentIndex--;
    if(currentIndex < 0)
    {
        currentIndex = count - 1;
    }

    createRecBoxItem();
}
//////////////////////////



//////////////////////////
/// \brief RecBox::onRightBtnClicked
///
void RecBox::onRightBtnClicked()
{
    // 点击之后 就是下一组
    currentIndex++;

    currentIndex%=count;

    // 0  3
    // 1  3
    // 2  3
    // 3  0


    createRecBoxItem();
}
//////////////////////////



//////////////////////////
/// \brief RecBox::initConnect
///
void RecBox::initConnect()
{
    connect(ui->leftBtn,&QPushButton::clicked,this,&RecBox::onLeftBtnClicked);
    connect(ui->rightBtn,&QPushButton::clicked,this,&RecBox::onRightBtnClicked);
}
//////////////////////////



//////////////////////////
void RecBox::clearLayout(QLayout* layout)
{
    QLayoutItem* item;

    while((item = layout->takeAt(0))!=nullptr)
    {
        if(QWidget* it = item->widget())
        {
            it->setParent(nullptr);
            it->deleteLater();
        }
        delete item;
    }
}
//////////////////////////






