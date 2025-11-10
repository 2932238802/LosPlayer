#pragma once
#include <QWidget>
#include <algorithm>
#include <QListWidgetItem>

#include "style/style.h"
#include "common/myLog.h"

#include "musicList.h"
#include "listItem.h"

namespace Ui {
class CommonPage;
}


class CommonPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommonPage(QWidget *parent = nullptr);
    void setMusicListType(MUSIC_LISTS_TYPE list_type);
    void setMusicPageUi(const QString& str,const QString&path);
    void addMusicToMusicPage(MusicList &list);
    void addMusic(Music* music);
    void reFresh(MusicList& music_list);
    QListWidgetItem* findListWidgetsByUUid(const QString& uuid);
    ~CommonPage();

private:
    void initUi();


private:
    Ui::CommonPage *ui;
    MUSIC_LISTS_TYPE listType;
    QVector<QString> musicOfPage;
};


