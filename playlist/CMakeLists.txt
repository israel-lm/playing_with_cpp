
set(playlist_src 
    src/main.cpp
    src/playlist.cpp
)

set(test_src
    test/main.cpp
    src/playlist.cpp
)

add_executable(Playlist ${playlist_src})

find_package(GTest REQUIRED)

add_executable(playlist_test ${test_src})

target_link_libraries(playlist_test PRIVATE GTest::GTest)

target_include_directories(Playlist PRIVATE include)
target_include_directories(playlist_test PRIVATE test include)
