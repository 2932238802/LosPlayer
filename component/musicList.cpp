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
            LOG() << "path : " << a ;
            Music* music = new Music(a);
            musics.push_back(std::move(music));
        }
        else{
            LOG() << "path: " << a;
            LOG() << "mt.name(): " << mt.name();
        }
    }
}
//////////////////////////////
