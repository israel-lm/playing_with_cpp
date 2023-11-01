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
            std::list<playing_with_cpp::song::Song> all_songs;
            playing_with_cpp::song::Song current_song;

            /**
             * @brief Locate a song in the list
             * @param song Object of the song to be found
             * @return Iterator with the location of the song
            */
            std::list<playing_with_cpp::song::Song>::iterator LocateSong(const playing_with_cpp::song::Song &song);

        public:
            Playlist(std::list<playing_with_cpp::song::Song> songs): all_songs(songs), current_song(*(songs.begin())) {}

            /**
             * @brief Insert a new song to the playlist and play it
             *
             * @param song Object of the song to be added
             */
            void InsertSong(const playing_with_cpp::song::Song &song);

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
            void DisplayList() const;


            playing_with_cpp::song::Song& GetCurrentSong() const;
        };
    }
}


#endif