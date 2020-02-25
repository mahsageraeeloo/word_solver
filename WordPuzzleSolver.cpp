#include "WordPuzzleSolver.h"

WordPuzzleSolver::WordPuzzleSolver(std::vector<std::string> inPuzzle) : puzzle(std::move(inPuzzle)) {
    if (puzzle.empty()) { // Check if the input puzzle is empty or not
        throw std::invalid_argument("Puzzle is empty.");
    }

    /*Strings in the input should have the same length*/
    int str_size = -1;
    for (auto &string : puzzle) {
        if (str_size == -1) {
            str_size = string.size();
        } else if (string.size() != str_size) {
            throw std::invalid_argument("Strings' lengths are different!");
        }
        std::transform(string.begin(), string.end(), string.begin(), ::toupper); // Converting letters to uppercase for case insensitive processing
    }
    try {
        this->puzzleSize.setColBoundary(str_size);
        this->puzzleSize.setRowBoundary(puzzle.size());
    } catch (std::invalid_argument e)
    {
        throw e;
    }
    /* filling location map*/
    /* One time iteration over the letters to avoid search for each input 'word' */
    for (int i = 0; i < this->puzzleSize.getRowBoundary(); ++i) {
        for (int j = 0; j < this->puzzleSize.getColBoundary(); ++j) {
            LocationPair locationPair(i, j);
            this->letter_locations.insert(make_pair(puzzle[i][j], locationPair));
        }
    }
    for(auto l: letter_locations)
    {
        cout << l.first << ":" << l.second << endl;
    }
}

// Check whether the puzzle has the word or not
bool WordPuzzleSolver::HasWord(std::string word) {
    /* This function:
     *      1. Converts the 'word' to uppercase for case insensitive comparison
     *      2. Finds occurrences of the first letter of the 'word' in the letter_locations(unordered_multimap) (instead of searching the whole puzzle)
     *      3. Moves toward 8 direction to find the 'word' using IsSubstr function.
     * */
    std::transform(word.begin(), word.end(), word.begin(), ::toupper); // Converting 'word' to uppercase for case insensitive comparison
    std::vector<Direction> directions = Direction::getAllDirections(); // Getting all directions

    auto range = letter_locations.equal_range(word.at(0)); // Finding occurrences of the first letter of the word using letter_locations
    for (auto pair_indx = range.first; pair_indx != range.second; ++pair_indx) {

        for (Direction const &direction:directions) {  // for each occurrence start searching in all possible directions
            if (IsSubstr(word, pair_indx->second, direction)) {
                return true;
            }
        }
    }
    return false;
}

/* Starting from loc_pair, each character of the 'word' compares with characters in the 'puzzle' but in a specific direction*/
bool WordPuzzleSolver::IsSubstr(const std::string &word, const LocationPair &loc_pair, const Direction &direction) {

    LocationPair cur_loc(loc_pair.getRowIndx(), loc_pair.getColIndx());
    // Checking whether with the 'word' size and current location we go out of puzzle boundaries or not
    // Current location contains first letter, so 'word.size()-1' moves are needed to compare all characters of 'word' with characters in the puzzle
    if (!direction.isValidMove(cur_loc, this->puzzleSize, word.size() - 1)) {
        return false;
    }
    // Comparing letters in the 'word' with letters in 'puzzle'
    for (auto letter = word.cbegin() + 1; letter != word.cend(); ++letter) { // First letter has been checked already
        if (!direction.moveToDirection(cur_loc, this->puzzleSize, 1)) { // Move 1 step toward the specified direction
            return false;
        }
        if (puzzle[cur_loc.getRowIndx()][cur_loc.getColIndx()] != *letter) {
            return false;
        }
    }
    return true;
}
