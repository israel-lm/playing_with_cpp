#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <list>
#include <algorithm>
#include <iomanip>
#include <limits>

#include "song.h"


class Playlist {
private:
    std::list<Song> all_songs;
    Song current_song;

    /**
     * @brief Locate a song in the list
     * @param song Object of the song to be found
     * @return Iterator with the location of the song
    */
    std::list<Song>::iterator LocateSong(const Song &song);

public:
    Playlist(std::list<Song> songs): all_songs(songs), current_song(*(songs.begin())) {}

    /**
     * @brief Insert a new song to the playlist and play it
     *
     * @param song Object of the song to be added
     */
    void InsertSong(const Song &song);

    /**
     * @brief Play the song following the current playing song
     *
     */
    void PlayNext();

    /**
     * @brief Play the song previous to the current playing song
     *
     */
    void PlayPrevious();

    /**
     * @brief Play the song indicated by the object current_song
     */
    void PlayCurrentSong();

    /**
     * @brief Display the list of songs present in the playlist
     *
     */
    void DisplayList();
};

#endif