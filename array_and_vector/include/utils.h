#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>
#include <vector>

/**
 * @brief Utility for displaying a vector of integers
 * 
 * @param vec Reference to the vector to be displayed
 */
void display_vector(const std::vector<int> &vec);

/**
 * @brief Utility for displaying a 2D vector a.k.a a matrix
 * 
 * @param matrix Reference to a vector of vectors of integers
 */
void display_matrix(std::vector<std::vector<int>> &matrix);

#endif //__UTILS_H__