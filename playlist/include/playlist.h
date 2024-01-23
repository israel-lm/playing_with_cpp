#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <list>
#include <algorithm>
#include <iomanip>
#include <limits>

#include "song.h"

namespace playing_with_cpp {
    namespace playlist {
        class Playlist {
        private:
            std::list<Song> allSongs;
            Song currentSong;

            /**
             * @brief Locate a song in the list
             * @param song Object of the song to be found
             * @return Iterator with the location of the song
            */
            std::list<Song>::iterator locateSong(const Song &song);

        public:
            Playlist(std::list<Song> songs): allSongs(songs), currentSong(*(songs.begin())) {}

            /**
             * @brief Insert a new song to the playlist and play it
             *
             * @param song Object of the song to be added
             */
            void insertSong(const Song &song);

            /**
             * @brief Play the song following the current playing song
             *
             */
            void playNext();

            /**
             * @brief Play the song previous to the current playing song
             *
             */
            void playPrevious();

            /**
             * @brief Play the song indicated by the object currentSong
             */
            void playCurrentSong();

            /**
             * @brief Display the list of songs present in the playlist
             *
             */
            void displayList() const;

            /**
             * @brief Get the Current playing song
             *
             * @return Song object
             */
            Song getCurrentSong() const{
                return this->currentSong;
            }

            /**
             * @brief Get all songs in the playlist
             *
             * @return List of songs
             */
            std::list<Song> getAllSongs() const{
                return this->allSongs;
            }
        };
    }
}
#endif