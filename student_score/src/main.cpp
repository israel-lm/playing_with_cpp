/*
Section 19
Challenge 2
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


std::list<char> GetListFromString(const std::string &s) {
    std::list<char> l;
    for (char c: s) {
        l.push_back(c);
    }

    return l;
}


int GetScore(const std::list<char> &answers, const std::list<char> &answer_sheet) {
    int score = 0;
    auto j = answer_sheet.begin();

    for(auto i = answers.begin(); i != answers.end(); i++, j++) {
        if (*i == *j)
            score++;
    }

    return score;
}

void DisplayScores(std::map<std::string, std::list<char>> &answers, const std::string &answer_sheet) {
    std::cout << std::setw(20) << std::left << "\nStudent"
                << std::setw(10) << std::right << "Score" << std::endl;
    std::cout << "================================" << std::endl;

    for (auto it = answers.begin(); it != answers.end(); it++) {
        int score = GetScore(it->second, GetListFromString(answer_sheet));
        std::cout << std::setw(20) << std::left << it->first
                << std::setw(10) << std::right << std::to_string(score) << std::endl;
    }
}

void DisplayMap(std::map<std::string, std::list<char>> &m) {
    for (auto i: m) {
        std::cout << "String: " << i.first << std::endl;
        std::cout << " List: ";
        for (auto j: i.second) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string answer_sheet = "ABCDE";
    std::ifstream in_file {"../student_score/resources/responses.txt"};
    std::map<std::string, std::list<char>> answers;

    std::string line;
    std::string answer {};

    int line_number = 0;

    if (in_file) {
        while(std::getline(in_file, line)) {
            if (line_number % 2 == 0) { //lines with answers
                answer = line;
            }
            else {
                answers[line] = GetListFromString(answer);
            }
            ++line_number;
        }
        in_file.close();
    }
    else {
        std::cerr << "Error opening input file" << std::endl;
    }

    DisplayScores(answers, answer_sheet);

}