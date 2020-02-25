#include "GridBoundary.h"

GridBoundary::GridBoundary(int rowBoundary, int colBoundary) {
    try {
        setRowBoundary(rowBoundary);
        setColBoundary(colBoundary);
    } catch (std::invalid_argument e) {
        throw e;
    }
}

GridBoundary::GridBoundary() : row_boundary(0), col_boundary(0) {}  // Grid with size = 0

int GridBoundary::getRowBoundary() const {
    return row_boundary;
}

void GridBoundary::setRowBoundary(int rowBoundary) {
    if (rowBoundary < 0) {
        throw std::invalid_argument("Invalid boundary.");
    }
    row_boundary = rowBoundary;
}

int GridBoundary::getColBoundary() const {
    return col_boundary;
}

void GridBoundary::setColBoundary(int colBoundary) {
    if (colBoundary < 0) {
        throw std::invalid_argument("Invalid boundary.");
    }
    col_boundary = colBoundary;
}