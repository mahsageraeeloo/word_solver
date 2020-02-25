#ifndef WORD_SOLVER_WORDPUZZLESOLVER_H
#define WORD_SOLVER_WORDPUZZLESOLVER_H

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include "LocationPair.h"
#include "Direction.h"

class WordPuzzleSolver {
private:
    GridBoundary puzzleSize;
    std::vector<std::string> puzzle; // Grid (rows*cols) contains letters of the entered words (UPPERCASE)
    unordered_multimap<char, LocationPair> letter_locations; // A multimap, maps each letter to its occurrences in the puzzle
    bool IsSubstr(const std::string &word, const LocationPair &loc_pair, const Direction &direction); // from cur_loc toward direction, can string:'word' be found?
public:
    explicit WordPuzzleSolver(std::vector<std::string> inPuzzle);
    bool HasWord(std::string word); // Can string:word be found in the grid?
};

#endif //WORD_SOLVER_WORDPUZZLESOLVER_H
