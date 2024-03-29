
#ifndef __SONG_H__
#define __SONG_H_

#include <string>
#include <iostream>

namespace playing_with_cpp {
    namespace playlist {
        class Song {
            friend std::ostream& operator<<(std::ostream &os, const Song &s);
            std::string name;
            std::string artist;
            int rating;
        public:
            Song() = default;
            Song(std::string name, std::string artist, int rating)
                    : name{name}, artist{artist}, rating{rating} {}
            std::string getName() const {
                return name;
            }
            std::string getArtist() const {
                return artist;
            }
            int getRating() const {
                return rating;
            }

            bool operator<(const Song &rhs) const  {
                return this->name < rhs.name;
            }

            bool operator==(const Song &rhs) const  {
                return this->name == rhs.name;
            }
        };
    }
}

#endif