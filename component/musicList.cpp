#include "musicList.h"

//////////////////////////////
/// \brief MusicList::MusicList
///
MusicList::MusicList() {}


//////////////////////////////
/// \brief MusicList::addMusic
/// \param music_urls
///
void MusicList::addMusic(const QList<QUrl> &music_urls)
{
    LOG() << "MusicList::addMusic(const QList<QUrl> &music_urls)";
    LOG() << "music_urls.size()" << music_urls.size();

    for(const auto& a:music_urls )
    {
        QMimeDatabase mimeDB;
        QMimeType mt = mimeDB.mimeTypeForFile(a.toLocalFile());

        if(mt.name() == "audio/mpeg" || mt.name() == "audio/flac" || mt.name() == "audio/wav")
        {
            LOG() << "原始 path : " << a;

            QString localFilePath = a.toLocalFile();
            LOG() << "转换后的本地路径字符串 : " << localFilePath;

            QUrl cleanUrl = QUrl::fromLocalFile(localFilePath);
            LOG() << "“净化”后的 URL : " << cleanUrl;

            Music* music = new Music(cleanUrl);

            l_pendingMusicCount++;

            musics.push_back(music);

            connect(music,&Music::_musicLoadOver,this,[this,music](){
                l_pendingMusicCount--;

                emit _oneMusicDone(music);

                if(l_pendingMusicCount == 0)
                    {
                    emit _allMusicDone();
                }
            });


        }
        else{
            LOG() << "path: " << a;
            LOG() << "mt.name(): " << mt.name();
        }
    }
}
//////////////////////////////


//////////////////////////////
/// \brief MusicList::findMusicByMusicId
/// \param musicId
/// \return
///
qm_iter MusicList::findMusicByMusicId(const QString &musicId)
{
    for(auto i = musics.begin(); i != musics.end();i++)
    {
        if((*i)->getUuid() == musicId)
        {
            return i;
        }
    }
    return end();
}
//////////////////////////////


//////////////////////////////
/// \brief MusicList::begin
/// \return
///
qm_iter MusicList::begin()
{
    return musics.begin();
}
//////////////////////////////


//////////////////////////////
/// \brief MusicList::end
/// \return
///
qm_iter MusicList::end()
{
    return musics.end();
}
//////////////////////////////





