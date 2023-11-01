#include "playlist.h"


std::list<playing_with_cpp::song::Song>::iterator playing_with_cpp::playlist::Playlist::LocateSong(const playing_with_cpp::song::Song &song) {
    return std::find(all_songs.begin(), all_songs.end(), song);
}


void playing_with_cpp::playlist::Playlist::PlayCurrentSong() {
    std::cout << std::endl << "Playing: " << current_song.GetName() << ", by " << current_song.GetArtist() << std::endl;
}


void playing_with_cpp::playlist::Playlist::InsertSong(const playing_with_cpp::song::Song &song){
    auto it = LocateSong(current_song);
    all_songs.insert(it, song);
    current_song = song;
    PlayCurrentSong();
}


void playing_with_cpp::playlist::Playlist::PlayNext() {
    auto it = LocateSong(current_song);
    if (++it == all_songs.end())
        it = all_songs.begin();

    current_song = *it;
    PlayCurrentSong();
}


void playing_with_cpp::playlist::Playlist::PlayPrevious() {
    auto it = LocateSong(current_song);
    if (it == all_songs.begin())
        it = all_songs.end();

    --it;
    current_song = *it;
    PlayCurrentSong();
}


void playing_with_cpp::playlist::Playlist::DisplayList() const {
    for (auto song: all_songs) {
        std::cout << "Name: " << song.GetName() << ", Artist: " << song.GetArtist() << ", Rating: " << song.GetRating() << std::endl;
    }
}

namespace playing_with_cpp {
    namespace song {
        std::ostream &operator<<(std::ostream &os, const playing_with_cpp::song::Song &s) {
            os << std::setw(20) << std::left << s.name
            << std::setw(30) << std::left << s.artist
            << std::setw(2) << std::left << s.rating;
            return os;
        }
    }
}

