#pragma once

#include <QObject>
#include <QUrl>
#include<QUuid>
#include<QMediaPlayer>
#include <QMediaMetaData>
#include "common/myLog.h"

class Music  : public QObject
{
    Q_OBJECT
public:
    Music(QUrl url,QObject *parent = nullptr);

    void setMusicName(const QString& music_name);
    void setMusicSinger(const QString& music_singer);
    void setMusicAlbum(const QString& album);
    void setMusicDuration(qint64 duration);
    void setUrl(const QUrl& url);
    void setLiked(bool);
    void setHistory(bool);

    QString getMusicName() const;
    QString getMusicSinger() const;
    QString getMusicAlbum() const;
    QString getUuid() const;
    qint64 getMusicDuration() const;
    QUrl getUrl() const;
    bool getLiked() const;
    bool getHistory() const;

private:
    void parseData();

private slots:
    void onLoadMusicDone();

private:
    QString l_musicId;

    QString l_musicName;

    QString l_musicSinger;

    QString l_album;

    QUrl l_musicUrl;

    // 就是longlong
    qint64 l_duration;

    bool l_isHistory;

    bool l_isLike;

    QMediaPlayer*player;
signals:
};


