/*  Section 7
    Challenge

    Write a C++ program as follows:

    Declare 2 empty vectors of integers named
    vector1 and vector 2, respectively.

    Add 10 and 20 to vector1 dynamically using push_back
    Display the elements in vector1 using the at() method as well as its size using the size() method

    Add 100 and 200 to vector2 dynamically using push_back
    Display the elements in vector2 using the at() method as well as its size using the size() method

    Declare an empty 2D vector called vector_2d
    Remember, that a 2D vector is a vector of vector<int>

    Add vector1 to vector_2d dynamically using push_back
    Add vector2 to vector_2d dynamically using push_back

    Display the elements in vector_2d using the at() method

    Change vector1.at(0) to 1000

    Display the elements in vector_2d again using the at() method

    Display the elements in vector1

    What did you expect? Did you get what you expected? What do you think happended?
*/

#include "utils.h"

int main() {

    std::vector<int> vector1, vector2;
    std::vector<std::vector<int>> vector_2d;

    vector1.push_back(10);
    vector1.push_back(20);
    DisplayVector(vector1);

    vector2.push_back(100);
    vector2.push_back(200);
    DisplayVector(vector2);

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    DisplayMatrix(vector_2d);

    vector1.at(0) = 1000;
    DisplayVector(vector1);
    DisplayMatrix(vector_2d);

    return 0;
}

