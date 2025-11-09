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

    ListItem* item = new ListItem(this);
    QListWidgetItem * widgetItem = new QListWidgetItem(ui->musicList);
    widgetItem->setSizeHint(QSize(item->width(),item->height()));
    ui->musicList->setItemWidget(widgetItem,item);
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






