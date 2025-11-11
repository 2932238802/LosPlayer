#pragma once
#include"music.h"
#include<QObject>
#include<QVector>
#include<QUrl>
#include<QList>
#include<QMimeDatabase>


typedef QVector<Music*>::iterator qm_iter;
class MusicList: public QObject
{
    Q_OBJECT
public:
    MusicList();

    void addMusic(const QList<QUrl>& music_urls);
    qm_iter findMusicByMusicId(const QString & musicId);

    qm_iter begin();
    qm_iter end();

signals:
    void _oneMusicDone(Music*);
    void _allMusicDone();

private:
    QVector<Music*> musics;
    int l_pendingMusicCount = 0;
};

