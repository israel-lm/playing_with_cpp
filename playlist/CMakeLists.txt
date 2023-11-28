add_executable(Playlist src/main.cpp src/playlist.cpp)
add_executable(playlist_test test/main.cpp)

target_include_directories(Playlist PRIVATE include)
target_include_directories(playlist_test PRIVATE test include)
