#include "RecBoxItem.h"
#include "ui_recboxitem.h"

///////////////////////////
/// \brief RecBoxItem::RecBoxItem
/// \param parent
///
RecBoxItem::RecBoxItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecBoxItem)
{
    ui->setupUi(this);
    ui->recMusicBtn->installEventFilter(this);
}
///////////////////////////


///////////////////////////
/// \brief RecBoxItem::~RecBoxItem
///
RecBoxItem::~RecBoxItem()
{
    delete ui;
}
///////////////////////////


// void RecBoxItem::enterEvent(QEnterEvent *event)
// {
//     ui->recMusicBtn->setCursor(Qt::PointingHandCursor);
//     QWidget::enterEvent(event);
// }

// void RecBoxItem::leaveEvent(QEvent *event)
// {
//     ui->recMusicBtn->unsetCursor();
//     QWidget::leaveEvent(event);
// }


///////////////////////////
/// \brief RecBoxItem::eventFilter
/// \param watched
/// \param event
/// \return
///
bool RecBoxItem::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->recMusicBtn)
    {
        if (event->type() == QEvent::Enter)
        {
            ui->recMusicBtn->setCursor(Qt::PointingHandCursor);

            if (l_rect.isEmpty()) {
                l_rect = this->geometry();
            }

            QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry", this);
            animation->setDuration(300);

            QRect endGeo = l_rect;
            endGeo.moveTop(l_rect.top() - 15);

            animation->setStartValue(this->geometry());
            animation->setEndValue(endGeo);
            animation->setEasingCurve(QEasingCurve::OutQuad);
            animation->start(QAbstractAnimation::DeleteWhenStopped);
            return true;
        }
        else if (event->type() == QEvent::Leave)
        {
            ui->recMusicBtn->unsetCursor();

            if (l_rect.isEmpty()) {
                return QWidget::eventFilter(watched, event);
            }

            QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry", this);
            animation->setDuration(300);
            animation->setStartValue(this->geometry());
            animation->setEndValue(l_rect);
            animation->setEasingCurve(QEasingCurve::OutQuad);
            animation->start(QAbstractAnimation::DeleteWhenStopped);

            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}
///////////////////////////



///////////////////////////
/// \brief RecBoxItem::setText
/// \param str
///
void RecBoxItem::setText(const QString &str)
{
    ui->recBoxText->setText(str);
}
///////////////////////////


///////////////////////////
/// \brief RecBoxItem::setBtnText
/// \param path
/// 用图片简单处理一下 就简单用文字处理一下
void RecBoxItem::setBtnText(const QString &path)
{
    ui->recMusicBtn->setText(path);
}
///////////////////////////

















