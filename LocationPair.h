#ifndef WORD_SOLVER_LOCATIONPAIR_H
#define WORD_SOLVER_LOCATIONPAIR_H

#include <iostream>
using namespace std;

struct LocationPair {
private:
    int row_indx;
    int col_indx;
public:
    LocationPair();
    LocationPair(int rowIndx, int colIndx);

    int getRowIndx() const;

    void setRowIndx(int rowIndx);

    int getColIndx() const;

    void setColIndx(int colIndx);

    friend std::ostream& operator<< (std::ostream &out, const LocationPair &locationPair);
};

#endif //WORD_SOLVER_LOCATIONPAIR_H
