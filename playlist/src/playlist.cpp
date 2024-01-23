#include "playlist.h"

using namespace playing_with_cpp;

std::list<playlist::Song>::iterator playlist::Playlist::locateSong(const Song &song) {
    return std::find(all_songs.begin(), all_songs.end(), song);
}


void playlist::Playlist::playCurrentSong() {
    std::cout << std::endl << "Playing: " << current_song.getName() << ", by " << current_song.getArtist() << std::endl;
}


void playlist::Playlist::insertSong(const Song &song){
    auto it = locateSong(current_song);
    all_songs.insert(it, song);
    current_song = song;
    playCurrentSong();
}


void playlist::Playlist::playNext() {
    auto it = locateSong(current_song);
    if (++it == all_songs.end())
        it = all_songs.begin();

    current_song = *it;
    playCurrentSong();
}


void playlist::Playlist::playPrevious() {
    auto it = locateSong(current_song);
    if (it == all_songs.begin())
        it = all_songs.end();

    --it;
    current_song = *it;
    playCurrentSong();
}


void playlist::Playlist::displayList() const {
    for (auto song: all_songs) {
        std::cout << "Name: " << song.getName() << ", Artist: " << song.getArtist() << ", Rating: " << song.getRating() << std::endl;
    }
}

namespace playing_with_cpp {
    namespace playlist {
        std::ostream &operator<<(std::ostream &os, const playlist::Song &s) {
            os << std::setw(20) << std::left << s.name
            << std::setw(30) << std::left << s.artist
            << std::setw(2) << std::left << s.rating;
            return os;
        }
    }
}