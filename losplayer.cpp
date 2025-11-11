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
    connect(ui->minBtn,&QPushButton::clicked,this,&LosPlayer::onMinimizeButtonClicked);
    connect(ui->volumeBtn,&QPushButton::clicked,this,&LosPlayer::onVolumeClicked);
    connect(ui->addLocalBtn,&QPushButton::clicked,this,&LosPlayer::onAddLocalBtnClicked);

    connect(&l_musicList,&MusicList::_oneMusicDone,this,[this](Music* music){
        Toast::showMsg(music->getMusicName() + " 加载完毕");
        ui->localPage->addMusic(music);
    });

    connect(&l_musicList,&MusicList::_allMusicDone,this,[this](){
        ui->localPage->reFresh(l_musicList);
    });

    connect(ui->likePage,&CommonPage::_updataLikeMusic,this,&LosPlayer::onUpdataLikeMusicAndPage);
    connect(ui->localPage,&CommonPage::_updataLikeMusic,this,&LosPlayer::onUpdataLikeMusicAndPage);
    connect(ui->recentPage,&CommonPage::_updataLikeMusic,this,&LosPlayer::onUpdataLikeMusicAndPage);

    connect(ui->playBtn,&QPushButton::clicked,this,&LosPlayer::onPlayMusic);
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

    // 推荐界面的设置
    ui->scrollAreaWidgetContentsForRecommandPage->setStyleSheet(COMMAND_PAGE_STYLE);
    ui->todayRecommandBox->initRecBoxUi(initNameAndPng(),1);
    ui->supplyBox->initRecBoxUi(initNameAndPng(),2);

    // commanPage界面设置
    ui->likePage->setMusicPageUi("我喜欢",":/png/likePage.png");
    ui->localPage->setMusicPageUi("本地",":/png/localPage.png");
    ui->recentPage->setMusicPageUi("最近",":/png/recentPage.png");

    ui->likePage->setMusicListType(MUSIC_LISTS_TYPE::LIKE_LIST);

    ui->localPage->setMusicListType(MUSIC_LISTS_TYPE::LOCAL_LIST);

    ui->recentPage->setMusicListType(MUSIC_LISTS_TYPE::HISTORY_LIST);

    volumeTool = new VolumeTool(this);

    volumeTool->hide();

    l_player = new QMediaPlayer(this);
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
/// \brief LosPlayer::onPlayMusic
///
void LosPlayer::onPlayMusic()
{
    //l_player;

    l_player->setSource((*(l_musicList.begin()))->getUrl());

    // 播放
    l_player->play();
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

        auto currentPage =qobject_cast<CommonPage*>(ui->stackedWidget->currentWidget());
        currentPage->reFresh(l_musicList);
    }
}
////////////////////////////


////////////////////////////
/// \brief LosPlayer::onMinimizeButtonClicked
///
void LosPlayer::onMinimizeButtonClicked()
{
    this->showMinimized();
}
////////////////////////////



////////////////////////////
/// \brief LosPlayer::onVolumeClicked
///
void LosPlayer::onVolumeClicked()
{
    if(volumeTool->isVisible())
    {
        LOG() << "音量键 隐藏";
        volumeTool->hide();

    }
    else{
        QPoint volumeGlobalPos = ui->volumeBtn->mapToGlobal(QPoint(0, 0));
        int globalX = volumeGlobalPos.x() + ui->volumeBtn->width() / 2 - volumeTool->width() / 2;
        int globalY = volumeGlobalPos.y() - volumeTool->height() - 5;
        QPoint globalTargetPos(globalX, globalY);
        volumeTool->move(globalTargetPos);
        LOG() << "音量键 显示";
        volumeTool->show();
    }
}
////////////////////////////


////////////////////////////
/// \brief LosPlayer::onAddLocalBtnClicked
///
void LosPlayer::onAddLocalBtnClicked()
{
    QFileDialog fileDialog(this);

    // 设置窗口标题
    fileDialog.setWindowTitle("添加本地下载音乐");

    QDir curDir = QDir::current();
    curDir.cdUp();
    curDir.cdUp();

    QString path = "G:\\music\\";

    // 设置过滤方式
    fileDialog.setDirectory(path);

    // 设置可以 一次打开多个
    fileDialog.setFileMode(QFileDialog::ExistingFiles);

    // fileDialog.setNameFilter("代码文件(*.h *.c *.)")

    QStringList mimes;
    mimes<< "application/octet-stream";

    fileDialog.setMimeTypeFilters(mimes);

    if(QDialog::Accepted == fileDialog.exec())
    {
        // 切换到本地下载的界面
        onGetPageid(4);


        QList<QUrl> fileUrls = fileDialog.selectedUrls();

        // 内部存放的是文件的路径

        // 将文件信息

        // 保存到本地下载界面
        l_musicList.addMusic(fileUrls);

        ui->localPage->setNeedFreshState(true);
    }

}
////////////////////////////



////////////////////////////
/// \brief LosPlayer::onUpdataLikeMusicAndPage
/// \param is_like
/// \param str
///
void LosPlayer::onUpdataLikeMusicAndPage(bool is_like, const QString &str)
{
    auto  it= l_musicList.findMusicByMusicId(str);

    if(it != l_musicList.end())
    {
        LOG() << "音乐名字为: " << (*it)->getMusicName() << " 添加为喜欢";
        (*it)->setLiked(true);
    }

    ui->likePage->addMusic(*it);

    ui->localPage->setNeedFreshState(true);
    ui->likePage->setNeedFreshState(true);
    ui->recentPage->setNeedFreshState(true);
}
////////////////////////////









