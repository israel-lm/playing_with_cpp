#include "Playlist.h"

std::list<Song>::iterator Playlist::locate_song(Song song){
    return std::find(all_songs.begin(), all_songs.end(), song);
}

void Playlist::play_current_song(){
    std::cout << "Playing: " << current_song.get_name() << ", by " << current_song.get_artist() << std::endl;
}


void Playlist::insert_song(Song song){
    auto it = locate_song(song);
    all_songs.insert(it, song);
    current_song = song;
}
void Playlist::play_next(){
    auto it = locate_song(current_song);
    it++;
    current_song = *it;
}
void Playlist::play_previous(){

}
void Playlist::resume(){

}
void pause(){

}