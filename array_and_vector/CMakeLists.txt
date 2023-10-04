add_executable(ArrayVector src/main.cpp)

add_library(Utils STATIC src/utils.cpp)

target_include_directories(Utils PUBLIC include)

target_link_libraries(ArrayVector PRIVATE Utils)

