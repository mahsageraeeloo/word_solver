#include "LocationPair.h"

LocationPair::LocationPair(int rowIndx, int colIndx) : row_indx(rowIndx), col_indx(colIndx) {}

LocationPair::LocationPair(): row_indx(-1), col_indx(-1){}

int LocationPair::getRowIndx() const {
    return row_indx;
}

void LocationPair::setRowIndx(int rowIndx) {
    row_indx = rowIndx;
}

int LocationPair::getColIndx() const {
    return col_indx;
}

void LocationPair::setColIndx(int colIndx) {
    col_indx = colIndx;
}

std::ostream& operator<< (std::ostream &out, const LocationPair &locationPair)
{
    out << "LocationPair(" << locationPair.row_indx << "," << locationPair.col_indx << ")" << endl;
    return out;
}
