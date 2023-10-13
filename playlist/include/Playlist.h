#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <list>

#include "Song.h"

class Playlist {
private:
    std::list<Song> all_songs;
    Song current_song;

    void play_current_song();
    std::list<Song>::iterator locate_song(Song song);

public:
    Playlist(std::list<Song> songs): all_songs(songs) {}
    void insert_song(Song song);
    void play_next();
    void play_previous();
    void resume();
    void pause();
};

#endif