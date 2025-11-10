#include "commonPage.h"
#include "ui_commonpage.h"

/////////////////////
/// \brief CommonPage::CommonPage
/// \param parent
///
CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
    initUi();
}
/////////////////////



/////////////////////
/// \brief CommonPage::setMusicListType
/// \param list_type
///
void CommonPage::setMusicListType(MUSIC_LISTS_TYPE list_type)
{
    listType = list_type;
}
/////////////////////


/////////////////////
/// \brief CommonPage::~CommonPage
///
CommonPage::~CommonPage()
{
    delete ui;
}
/////////////////////



/////////////////////
/// \brief CommonPage::initUi
///
void CommonPage::initUi()
{
    // 播放按钮设置
    ui->playBtn->setStyleSheet(COMMON_PAGE_PLAYBTN);

    // 图片设置
    ui->musicImage->setText("Image~");

    // 标题设置
    ui->pageTitle->setStyleSheet(COMMON_PAGE_TITLESTYLE);

    ui->musicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->musicList->setStyleSheet(MUSIC_LIST_STYLE);
}
/////////////////////


/////////////////////
/// \brief CommonPage::setMusicPageUi
/// \param str
/// \param path
///
void CommonPage::setMusicPageUi(const QString &str, const QString &path)
{
    LOG() << "CommonPage::setMusicPageUi(const QString &str, const QString &path)";
    LOG() << "path: " << path;
    ui->pageTitle->setText(str);
    ui->musicImage->setPixmap(QPixmap(path));
    ui->musicImage->setScaledContents(true); // 尺寸缩放
}
/////////////////////


/////////////////////
/// \brief CommonPage::addMusicToMusicPage
/// \param list
///
void CommonPage::addMusicToMusicPage(MusicList &list)
{
    for(auto a:list)
    {
        auto pos = std::find(musicOfPage.begin(),musicOfPage.end(),a->getUuid());
        if(pos==musicOfPage.end())
        {
            addMusic(a);
        }
    }
}
/////////////////////


/////////////////////
/// \brief CommonPage::addMusic
/// \param music
///
void CommonPage::addMusic(Music *music)
{
    switch(listType)
    {
    case MUSIC_LISTS_TYPE::HISTORY_LIST:
    {
        // 历史播放
        if(music->getHistory())
        {
            musicOfPage.push_back(music->getUuid());
        }
        break;
    }
    case MUSIC_LISTS_TYPE::LIKE_LIST:
    {
        if(music->getLiked())
        {
            musicOfPage.push_back(music->getUuid());
        }
        break;
    }
    case MUSIC_LISTS_TYPE::LOCAL_LIST:
    {
        musicOfPage.push_back(music->getUuid());
        break;
    }
    default:{
        LOG() << "暂时不支持";
    }
    }
}
/////////////////////


/////////////////////
/// \brief CommonPage::reFresh
/// \param music_list
/// 负责将歌曲的信息 更新到界面上
void CommonPage::reFresh(MusicList &music_list)
{
    LOG() << "CommonPage::reFresh(MusicList &music_list)";




    for(auto music_id: musicOfPage)
    {
        if (findListWidgetsByUUid(music_id)) {
            continue;
        }

        auto it = music_list.findMusicByMusicId(music_id);

        ListItem* item = new ListItem(this);

        // 设置歌曲名称
        item->setMusicAlbum((*it)->getMusicAlbum());
        item->setMusicName((*it)->getMusicName());
        item->setMusicSinger((*it)->getMusicSinger());

        QListWidgetItem * widgetItem = new QListWidgetItem(ui->musicList);
        widgetItem->setSizeHint(QSize(item->width(),item->height()));

        widgetItem->setData(Qt::UserRole,music_id);
        ui->musicList->setItemWidget(widgetItem,item);
    }
}
/////////////////////



/////////////////////
/// \brief CommonPage::findListWidgetsByUUid
/// \param uuid
/// \return
///
QListWidgetItem *CommonPage::findListWidgetsByUUid(const QString &uuid)
{
    const int role = Qt::UserRole;

    for(int i =0 ; i < ui->musicList->count(); i++)
    {
        QListWidgetItem* item = ui->musicList->item(i);
        if (item->data(role).toString() == uuid) {
            return item;
        }
    }
    return nullptr;
}
/////////////////////






