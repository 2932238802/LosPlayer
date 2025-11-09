#pragma once
#include"music.h"
#include<QVector>
#include<QUrl>
#include<QList>
#include<QMimeDatabase>

class MusicList
{
public:
    MusicList();

    void addMusic(const QList<QUrl>& music_urls);

private:
    QVector<Music*> musics;
};

