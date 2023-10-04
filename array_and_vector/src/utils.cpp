
#include "utils.h"

void display_vector(const std::vector<int> &vec) {
    int size = vec.size();

    std::cout << "Vector size: " << size << std::endl;
    std::cout << "Vector content:";
    for (int i = 0; i < size; i++)
        std::cout << " " << vec.at(i);
    std::cout << std::endl;
}

void display_matrix(std::vector<std::vector<int>> &matrix) {
    std::cout << "Displaying matrix content" << std::endl;
    for (int i = 0; i < matrix.size(); i++) {
        display_vector(matrix.at(i));
    }
}