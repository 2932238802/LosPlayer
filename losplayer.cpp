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
    initNameAndPng();
    initUi();
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

    connect(ui->recommand,&BtFrom::_pageId,this,&LosPlayer::onGetPageid);
    connect(ui->like,&BtFrom::_pageId,this,&LosPlayer::onGetPageid);
    connect(ui->local,&BtFrom::_pageId,this,&LosPlayer::onGetPageid);
    connect(ui->musicHall,&BtFrom::_pageId,this,&LosPlayer::onGetPageid);
    connect(ui->audio,&BtFrom::_pageId,this,&LosPlayer::onGetPageid);
    connect(ui->recent,&BtFrom::_pageId,this,&LosPlayer::onGetPageid);
}

void LosPlayer::initUi()
{
    setAttribute(Qt::WA_TranslucentBackground,true);
    this->setStyleSheet(GLOBAL_STYLE_SHEET);
    lastBtn = "recommand";
    ui->recommand->showLineBox(true);
    ui->recommand->setProperty("clicked", true);
    ui->audio->setProperty("clicked",false);
    ui->musicHall->setProperty("clicked",false);
    ui->like->setProperty("clicked",false);
    ui->local->setProperty("clicked",false);
    ui->recent->setProperty("clicked",false);

    btnIdAndName.insert(0,"recommand");
    btnIdAndName.insert(1,"audio");
    btnIdAndName.insert(2,"musicHall");
    btnIdAndName.insert(3,"like");
    btnIdAndName.insert(4,"local");
    btnIdAndName.insert(5,"recent");

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0,0);
    shadow->setColor("#000000");
    shadow->setBlurRadius(10);
    this->setGraphicsEffect(shadow);

    ui->recommand->setSelfStyle("推荐","recommand~");
    ui->recommand->setPageId(0);

    ui->audio->setSelfStyle("电台","audio~");
    ui->audio->setPageId(1);

    ui->musicHall->setSelfStyle("音乐厅","musichall~");
    ui->musicHall->setPageId(2);

    ui->local->setSelfStyle("本地","local~");
    ui->local->setPageId(4);

    ui->like->setSelfStyle("喜欢","like~");
    ui->like->setPageId(3);

    ui->recent->setSelfStyle("最近","recent~");
    ui->recent->setPageId(5);


    ui->scrollAreaWidgetContentsForRecommandPage->setStyleSheet(COMMAND_PAGE_STYLE);\

    ui->todayRecommandBox->initRecBoxUi(initNameAndPng(),1);
    ui->supplyBox->initRecBoxUi(initNameAndPng(),2);
}
////////////////////////////


////////////////////////////
/// \brief LosPlayer::initName
/// 初始化 一些标签名字
QJsonArray LosPlayer::initNameAndPng()
{
    QJsonObject obj;
    QJsonArray arr;
    for(int i = 0; i < 30; i++)
    {
        obj.insert("btn_text",generateRandStr(3));
        obj.insert("text",generateRandStr(3));
        arr.append(obj);
    }

    return arr;
}
////////////////////////////


////////////////////////////
/// \brief LosPlayer::generateRandStr
///
QString LosPlayer::generateRandStr(int lenth)
{
    QString initStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    QString ans;
    ans.clear();
    const int initStrSize = initStr.size();
    for(int i = 0; i < lenth ; i++)
    {
        int cPos = QRandomGenerator::global()->bounded(initStrSize);
        QChar c = initStr.at(cPos);
        ans.append(c);
    }
    return ans;
}
////////////////////////////


////////////////////////////
/// \brief LosPlayer::onGetPageid
/// \param page_id
///
void LosPlayer::onGetPageid(int page_id)
{
    ui->stackedWidget->setCurrentIndex(page_id);
    QString newBtnName = btnIdAndName[page_id];

    if (newBtnName != lastBtn)
    {
        BtFrom* newBtFrom = this->findChild<BtFrom*>(newBtnName);
        BtFrom* lastBtFrom = this->findChild<BtFrom*>(lastBtn);


        if (lastBtFrom && newBtFrom && newBtnName!=lastBtn) {
            lastBtFrom->setProperty("clicked", false);
            newBtFrom->setProperty("clicked", true);

            lastBtFrom->showLineBox(false);
            lastBtFrom->style()->unpolish(lastBtFrom);
            lastBtFrom->style()->polish(lastBtFrom);

            newBtFrom->showLineBox(true);
            newBtFrom->style()->unpolish(newBtFrom);
            newBtFrom->style()->polish(newBtFrom);

            LOG() << "之前的 " << lastBtn << " 现在的 " << newBtnName;
        }

        lastBtn = newBtnName;
    }
}

////////////////////////////
