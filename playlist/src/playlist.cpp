#include "playlist.h"


std::list<Song>::iterator Playlist::LocateSong(const Song &song) {
    return std::find(all_songs.begin(), all_songs.end(), song);
}


void Playlist::PlayCurrentSong(){
    std::cout << std::endl << "Playing: " << current_song.GetName() << ", by " << current_song.GetArtist() << std::endl;
}


void Playlist::InsertSong(const Song &song){
    auto it = LocateSong(current_song);
    all_songs.insert(it, song);
    current_song = song;
    PlayCurrentSong();
}


void Playlist::PlayNext(){
    auto it = LocateSong(current_song);
    if (++it == all_songs.end())
        it = all_songs.begin();

    current_song = *it;
    PlayCurrentSong();
}


void Playlist::PlayPrevious(){
    auto it = LocateSong(current_song);
    if (it == all_songs.begin())
        it = all_songs.end();

    --it;
    current_song = *it;
    PlayCurrentSong();
}


void Playlist::DisplayList() {
    for (auto song: all_songs) {
        std::cout << "Name: " << song.GetName() << ", Artist: " << song.GetArtist() << ", Rating: " << song.GetRating() << std::endl;
    }
}


std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}