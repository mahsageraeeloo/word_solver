#include <vector>
#include "WordPuzzleSolver.h"

std::vector<std::string> getInput();

int main() {
    std::cout << "Enter puzzle:" << std::endl;
    std::vector<std::string> input = getInput();

    char answer = 'Y';
    try {
        WordPuzzleSolver wordSolver(input);
        while (answer == 'Y' || answer == 'y') {
            string word;
            bool result;

            cout << "Enter word: " << endl;
            cin >> word;

            result = wordSolver.HasWord(word);
            if (result) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            cout << "Continue?(Y/N) ";
            cin >> answer;
            cout << endl;
        }
    } catch (std::invalid_argument e) {
        cout << e.what() << endl; //TODO continue or just print the message
    }
    return 0;
}

std::vector<string> getInput() {
    std::vector<string> inputVector;
    for (std::string line; std::getline(std::cin, line) && !line.empty();) {
        inputVector.push_back(line);
    }
    return inputVector;
}
