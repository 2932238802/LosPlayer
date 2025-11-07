#include "losplayer.h"
#include "ui_losplayer.h"


////////////////////////////
/// \brief LosPlayer::LosPlayer
/// \param parent
///
LosPlayer::LosPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LosPlayer)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

    ui->head->installEventFilter(this);



    initConnect();
}
////////////////////////////



////////////////////////////
/// \brief LosPlayer::~LosPlayer
///
LosPlayer::~LosPlayer()
{
    delete ui;
}
////////////////////////////




////////////////////////////
/// \brief LosPlayer::eventFilter
/// \param obj
/// \param event
/// \return
///
bool LosPlayer::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->head)
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

        if(event->type() == QEvent::MouseButtonPress)
        {
            if(mouseEvent->button() == Qt::LeftButton)
            {
                l_point = mouseEvent->globalPos() - frameGeometry().topLeft();
                return true;
            }
        }
        else if (event->type() == QEvent::MouseMove)
        {
            if(mouseEvent->buttons() & Qt::LeftButton)
            {
                move( mouseEvent->globalPos() - l_point);
                return true;
            }
        }
    }
    return QMainWindow::eventFilter(obj,event);
}
////////////////////////////




////////////////////////////
/// \brief LosPlayer::initConnect
///
void LosPlayer::initConnect()
{
    connect(ui->quitBtn,&QPushButton::clicked,this,[=](){
        close();
    });



}

void LosPlayer::initUi()
{
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0,0);
    shadow->setColor("#000000");
    shadow->setBlurRadius(10);
    this->setGraphicsEffect(shadow);



}
////////////////////////////
