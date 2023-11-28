cmake_minimum_required(VERSION 3.10)

project(playing_with_cpp VERSION 1.0)

find_package(gtest REQUIRED)

add_subdirectory(array_and_vector)
add_subdirectory(char_and_strings)
add_subdirectory(playlist)
add_subdirectory(count_words)
add_subdirectory(student_score)

target_link_libraries(${PROJECT_NAME} gtest::gtest)