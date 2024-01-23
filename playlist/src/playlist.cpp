#include "playlist.h"

using namespace playing_with_cpp;

std::list<playlist::Song>::iterator playlist::Playlist::locateSong(const Song &song) {
    return std::find(allSongs.begin(), allSongs.end(), song);
}


void playlist::Playlist::playCurrentSong() {
    std::cout << std::endl << "Playing: " << currentSong.getName() << ", by " << currentSong.getArtist() << std::endl;
}


void playlist::Playlist::insertSong(const Song &song){
    auto it = locateSong(currentSong);
    allSongs.insert(it, song);
    currentSong = song;
    playCurrentSong();
}


void playlist::Playlist::playNext() {
    auto it = locateSong(currentSong);
    if (++it == allSongs.end())
        it = allSongs.begin();

    currentSong = *it;
    playCurrentSong();
}


void playlist::Playlist::playPrevious() {
    auto it = locateSong(currentSong);
    if (it == allSongs.begin())
        it = allSongs.end();

    --it;
    currentSong = *it;
    playCurrentSong();
}


void playlist::Playlist::displayList() const {
    for (auto song: allSongs) {
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