#include <gtest/gtest.h>
#include <memory>

#include "playlist.h"

class PlaylistTest : public testing::Test 
{
protected:    
    std::unique_ptr<playing_with_cpp::playlist::Playlist> playlistPtr;

    void SetUp() override
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
        playlistPtr = std::make_unique<playing_with_cpp::playlist::Playlist>(songs);
    }

};

TEST_F(PlaylistTest, Creation)
{
    ASSERT_EQ(playlistPtr->GetCurrentSong().GetName(), "God's Plan");
}

TEST_F(PlaylistTest, NextSong)
{
    playlistPtr->PlayNext();
    ASSERT_EQ(playlistPtr->GetCurrentSong().GetName(), "Never Be The Same");
}

TEST_F(PlaylistTest, PreviousSong)
{
    playlistPtr->PlayPrevious();
    ASSERT_EQ(playlistPtr->GetCurrentSong().GetName(), "Whatever It Takes");
}

TEST_F(PlaylistTest, InsertSong)
{
    playing_with_cpp::song::Song song("Indestructible", "Welshly Arms", 5);
    playlistPtr->InsertSong(song);

    ASSERT_EQ(playlistPtr->GetCurrentSong().GetName(), "Indestructible");
}