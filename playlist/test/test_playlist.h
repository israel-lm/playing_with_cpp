#include <gtest/gtest.h>
#include <memory>

#include "playlist.h"

using namespace playing_with_cpp;

class PlaylistTest : public testing::Test 
{
protected:    
    std::unique_ptr<playlist::Playlist> playlistPtr;

    void SetUp() override
    {
        std::list<playlist::Song> songs
        {
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}
        };
        playlistPtr = std::make_unique<playlist::Playlist>(songs);
    }

};

TEST_F(PlaylistTest, Creation)
{
    ASSERT_EQ(playlistPtr->getCurrentSong().GetName(), "God's Plan");
}

TEST_F(PlaylistTest, NextSong)
{
    playlistPtr->playNext();
    ASSERT_EQ(playlistPtr->getCurrentSong().GetName(), "Never Be The Same");
}

TEST_F(PlaylistTest, PreviousSong)
{
    playlistPtr->playPrevious();
    ASSERT_EQ(playlistPtr->getCurrentSong().GetName(), "Whatever It Takes");
}

TEST_F(PlaylistTest, insertSong)
{
    playlist::Song song("Indestructible", "Welshly Arms", 5);
    playlistPtr->insertSong(song);

    ASSERT_EQ(playlistPtr->getCurrentSong().GetName(), "Indestructible");
}