/*
Automated Grader

Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz
as well as student responses for the quiz.

The answer key is the first item in the file.
Student1 name
Student1 responses
Student2 name
Student2 responses
. . .

Here is a sample file.

ABCDE
Frank
ABCDE
Larry
ABCAC
Moe
BBCDE
Curly
BBAAE
Michael
BBCDE

You should read the file and display:
Each student's name and score (#correct out of 5)
At the end, the class average should be displayed
You may assume that the data in the file is properly formatted

Program should output to the console the following:
Student                     Score
----------------------------
Frank                             5
Larry                              3
Moe                              4
Curly                             2
Michael                         4
---------------------------
Average score            3.6
*/

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

/**
 * @brief Convert a string into a list of characters
 * 
 * @param s String to be converted
 * @return List of characters
 */
std::list<char> getListFromString(const std::string &s) {
    std::list<char> l;
    for (char c: s) {
        l.push_back(c);
    }

    return l;
}

/**
 * @brief Get the student's score given its answers and the answer sheet
 * 
 * @param answers Student's answers
 * @param answerSheet Correct answers
 * @return The sudent score
 */
int getScore(const std::list<char> &answers, const std::list<char> &answerSheet) {
    int score = 0;
    auto j = answerSheet.begin();

    for(auto i = answers.begin(); i != answers.end(); i++, j++) {
        if (*i == *j)
            score++;
    }

    return score;
}

/**
 * @brief Display the students score given the answer sheet
 * 
 * @param answers Map of student name and the answers
 * @param answerSheet The correct answers
 */
void displayScores(std::map<std::string, std::list<char>> &answers, const std::string &answerSheet) {
    std::cout << std::setw(20) << std::left << "\nStudent"
                << std::setw(10) << std::right << "Score" << std::endl;
    std::cout << "================================" << std::endl;

    for (auto it = answers.begin(); it != answers.end(); it++) {
        int score = getScore(it->second, getListFromString(answerSheet));
        std::cout << std::setw(20) << std::left << it->first
                << std::setw(10) << std::right << std::to_string(score) << std::endl;
    }
}


int main() {
    std::string answerSheet = "ABCDE";
    std::ifstream inFile {"../student_score/resources/responses.txt"};
    std::map<std::string, std::list<char>> answers;

    std::string line;
    std::string answer {};

    int lineNumber = 0;

    if (inFile) {
        while(std::getline(inFile, line)) {
            if (lineNumber % 2 == 0) { //lines with answers
                answer = line;
            }
            else {
                answers[line] = getListFromString(answer);
            }
            ++lineNumber;
        }
        inFile.close();
    }
    else {
        std::cerr << "Error opening input file" << std::endl;
    }

    displayScores(answers, answerSheet);

}