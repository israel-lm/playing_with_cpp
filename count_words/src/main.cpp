/*
We will be reading words from a text file provided to you.
The text file is named 'words.txt' and contains the fist few
paragraphs from the book, "The Wonderful Wizard of Oz", by
L. Frank Baum.

Part 1:

You are to display each unique word
in the file and immediately following each word display the number
of time it occurs in the text file.

The words should be displayed in ascending order.

Here is a sample listing of the first few words:

Word         Count
===================
Aunt                 5
Dorothy              8
Dorothy's            1
Em                   5
Even                 1
From                 1


============================================
Part 2:

You are to display each unique word
in the file and immediately following each word display the line numbers
in which that word appears.

The words should be displayed in ascending order and the line numbers for
each word should also be displayed in ascending order.
If a word appears more than once on a line then the line number should
only appear once.

Here is a sample listing of the first few words:

Word       Occurrences
============================
Aunt                  [ 2 7 25 29 48 ]
Dorothy      [ 1 7 15 29 39 43 47 51 ]
Dorothy's                       [ 31 ]
Em                    [ 2 7 25 30 48 ]
Even                            [ 19 ]
From                            [ 50 ]
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

/**
 * @brief Display the words and counts
 * 
 * @param words Map of a word and how many times it appears in the file
 */
void displayWords(const std::map<std::string, int> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
                << std::setw(7) << std::right << "Count"<< std::endl;
    std::cout << "===================" << std::endl;
    for (auto pair: words)
        std::cout << std::setw(12) << std::left << pair.first
                    << std::setw(7) << std::right << pair.second << std::endl;
}


/**
 * @brief Display the words and the lines where they appear
 * 
 * @param words A map of the words and a set containing the line numbers where they appear
 */
void displayWords(const std::map<std::string, std::set<int>> &words)
{
     std::cout << std::setw(12) << std::left << "\nWord"
                << "Occurrences"<< std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair: words) {
        std::cout << std::setw(12) << std::left << pair.first
                       << std::left << "[ ";
        for (auto i: pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}



/**
 * @brief Removes periods, commas, semicolons and colon in a string and returns the clean version
 * 
 * @param s String to be cleaned up
 * @return Clean string
 */
std::string cleanStrings(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}


/**
 * @brief Get the words of a file and the number of times they occur
 */
void countWords() {
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream inFile {"../count_words/resources/words.txt"};
    if (inFile) {
        while( std::getline(inFile, line)) {
            std::istringstream lineStream {line};
            while (lineStream >> word) {
                word = cleanStrings(word);
                if (words.find(word) != words.end()) {
                    words[word] += 1;
                }
                else {
                     words[word] = 1;
                }
            }
        }

        inFile.close();
        displayWords(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}


/**
 * @brief Get words from a file and the line numbers in which the word appears
 */
void getLineNumbers() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream inFile {"../count_words/resources/words.txt"};
    if (inFile) {
        int lineNumber = 0;
        // You implement this code
        while( std::getline(inFile, line)) {
            std::istringstream lineStream {line};
            while (lineStream >> word) {
                word = cleanStrings(word);
                if (words.find(word) != words.end()) {
                    words[word].insert(lineNumber);
                }
                else {
                    std::set<int> c {lineNumber};
                    words[word] = c;
                }
            }
            lineNumber++;
        }
        inFile.close();
        displayWords(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main() {
    countWords();
    getLineNumbers();
    return 0;
}