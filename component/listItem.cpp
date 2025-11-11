#include "listItem.h"
#include "ui_listitem.h"

ListItem::ListItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListItem)
{
    ui->setupUi(this);
    initUi();
    initConnect();
    setLike(false);
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

////////////////////////////////////
/// \brief ListItem::setMusicName
/// \param music_name
///
void ListItem::setMusicName(const QString &music_name)
{
    ui->musicNameLabel->setText(music_name);
}
////////////////////////////////////


////////////////////////////////////
/// \brief ListItem::setMusicSinger
/// \param music_singer
///
void ListItem::setMusicSinger(const QString &music_singer)
{
    ui->singerLabel->setText(music_singer);
}
////////////////////////////////////


////////////////////////////////////
/// \brief ListItem::setMusicAlbum
/// \param music_album
///
void ListItem::setMusicAlbum(const QString &music_album)
{
    ui->albumLabel->setText(music_album);
}
////////////////////////////////////



////////////////////////////////////
/// \brief ListItem::setLike
/// \param is_like
///
void ListItem::setLike(bool is_like)
{
    l_isLike = is_like;
    if(l_isLike == true)
    {
        ui->likeBtn->setStyleSheet(LIST_ITEM_LIKEBTN_CLICKED);
        ui->likeBtn->setText("Y");
    }
    else{
        ui->likeBtn->setStyleSheet(LIST_ITEM_LIKEBTN_UNCLICKED);
        ui->likeBtn->setText("N");
    }
}
////////////////////////////////////



////////////////////////////////////
/// \brief ListItem::initUi
///
void ListItem::initUi()
{
    setStyleSheet(LISTITEM_STYLE);
    ui->vipLabel->setStyleSheet(LIST_ITEM_VIP_LABEL);
    ui->sqLabel->setStyleSheet(LIST_ITEM_SQ_LABAL);

}
////////////////////////////////////



////////////////////////////////////
/// \brief ListItem::initConnect
///
void ListItem::initConnect()
{
    connect(ui->likeBtn,&QPushButton::clicked,this,&ListItem::onLikeBtnClicked);
}
////////////////////////////////////



////////////////////////////////////
/// \brief ListItem::onLikeBtnClicked
///
void ListItem::onLikeBtnClicked()
{
    l_isLike = !l_isLike;
    setLike(l_isLike);

    emit _setIsLike(l_isLike);
}
////////////////////////////////////





