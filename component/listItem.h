#pragma once
#include <QWidget>
#include <QEvent>
#include "style/style.h"


namespace Ui {
class ListItem;
}

class ListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ListItem(QWidget *parent = nullptr);
    ~ListItem();

    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void setMusicName(const QString& music_name);
    void setMusicSinger(const QString& music_singer);
    void setMusicAlbum(const QString& music_album);
    void setLike(bool is_like);

private:
    void initUi();
    void initConnect();

private:
    void onLikeBtnClicked();


private:
    bool l_isLike;
    Ui::ListItem *ui;
};

