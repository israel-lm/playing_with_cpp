#include "Playlist.h"


std::list<Song>::iterator Playlist::locate_song(const Song &song) {
    return std::find(all_songs.begin(), all_songs.end(), song);
}


void Playlist::play_current_song(){
    std::cout << std::endl << "Playing: " << current_song.get_name() << ", by " << current_song.get_artist() << std::endl;
}


void Playlist::insert_song(const Song &song){
    auto it = locate_song(current_song);
    all_songs.insert(it, song);
    current_song = song;
    play_current_song();
}


void Playlist::play_next(){
    auto it = locate_song(current_song);
    if (++it == all_songs.end())
        it = all_songs.begin();

    current_song = *it;
    play_current_song();
}


void Playlist::play_previous(){
    auto it = locate_song(current_song);
    if (it == all_songs.begin())
        it = all_songs.end();

    --it;
    current_song = *it;
    play_current_song();
}


void Playlist::display_list() {
    for (auto song: all_songs) {
        std::cout << "Name: " << song.get_name() << ", Artist: " << song.get_artist() << ", Rating: " << song.get_rating() << std::endl;
    }
}


std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}