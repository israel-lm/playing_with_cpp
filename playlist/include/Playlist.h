#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <list>
#include <algorithm>
#include <iomanip>
#include <limits>

#include "Song.h"


class Playlist {
private:
    std::list<Song> all_songs;
    Song current_song;

    /**
     * @brief Locate a song in the list
     * @param song Object of the song to be found
     * @return Iterator with the location of the song
    */
    std::list<Song>::iterator locate_song(const Song &song);

public:
    Playlist(std::list<Song> songs): all_songs(songs), current_song(*(songs.begin())) {}

    /**
     * @brief Insert a new song to the playlist and play it
     *
     * @param song Object of the song to be added
     */
    void insert_song(const Song &song);

    /**
     * @brief Play the song following the current playing song
     *
     */
    void play_next();

    /**
     * @brief Play the song previous to the current playing song
     *
     */
    void play_previous();

    /**
     * @brief Play the song indicated by the object current_song
     */
    void play_current_song();

    /**
     * @brief Display the list of songs present in the playlist
     *
     */
    void display_list();
};

#endif