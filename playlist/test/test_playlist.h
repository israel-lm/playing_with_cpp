#include <gtest/gtest.h>

#include "playlist.h"

TEST(Playlist,  Creation)
{
     std::list<playing_with_cpp::song::Song> songs
     {
        {"God's Plan",        "Drake",                     5},
        {"Never Be The Same", "Camila Cabello",            5},
        {"Pray For Me",       "The Weekend and K. Lamar",  4},
        {"The Middle",        "Zedd, Maren Morris & Grey", 5},
        {"Wait",              "Maroone 5",                 4},
        {"Whatever It Takes", "Imagine Dragons",           3}
    };
    playing_with_cpp::playlist::Playlist playlist(songs);

    ASSERT_EQ(playlist.GetCurrentSong().GetName(), "God's Plan");
}