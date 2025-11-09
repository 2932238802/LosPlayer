#include "music.h"

Music::Music(QUrl url,QObject *parent)
    :QObject(parent)
{
    this->l_musicUrl = url;
    l_musicId = QUuid::createUuid().toString();
    player = new QMediaPlayer(this);

    connect(player,&QMediaPlayer::metaDataChanged,this,&Music::onLoadMusicDone);


    parseData();

}


void Music::setMusicName(const QString& music_name){

    this->l_musicName = music_name;
}

void Music::setMusicSinger(const QString& music_singer){
    this->l_musicSinger = music_singer;
}

void Music::setMusicAlbum(const QString& album){
    this->l_album = album;
}

void Music::setMusicDuration(qint64 duration){
    this->l_duration = duration;
}

void Music::setUrl(const QUrl& url){
    this->l_musicUrl = url;
}

void Music::setLiked(bool is_like){
    this->l_isLike =is_like;
}

void Music::setHistory(bool is_histoty){
    this->l_isHistory =is_histoty;
}

QString Music::getMusicName() const{
    return l_musicName;
}
QString Music::getMusicSinger() const{
    return l_musicSinger;
}
QString Music::getMusicAlbum() const{
    return l_album;
}

QString Music::getUuid() const
{
    return l_musicId;
}

qint64 Music::getMusicDuration() const{
    return l_duration;
}

QUrl Music::getUrl() const{
    return l_musicUrl;
}

bool Music::getLiked() const{
    return l_isLike;
}

bool Music::getHistory() const
{
    return l_isHistory;
}


//////////////////
/// \brief Music::parseData
///
void Music::parseData()
{
    player->setSource(l_musicUrl);
}
//////////////////


//////////////////
/// \brief Music::onLoadMusicDone
///
void Music::onLoadMusicDone()
{
    QMediaMetaData metaData = player->metaData();

    l_musicName = metaData.value(QMediaMetaData::Title).toString();
    l_album = metaData.value(QMediaMetaData::AlbumTitle).toString();
    l_musicSinger = metaData.value(QMediaMetaData::Author).toString();
    l_duration = metaData.value(QMediaMetaData::Duration).toLongLong();

    LOG() << "onLoadMusicDone()";
    LOG() << "l_musicName: " << l_musicName;
    LOG() << "l_album: " << l_album;
    LOG() << "l_musicSinger: " << l_musicSinger;
    LOG() << "l_duration: " << l_duration;
}
//////////////////









