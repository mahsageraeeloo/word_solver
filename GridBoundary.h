#ifndef WORD_SOLVER_GRIDBOUNDARY_H
#define WORD_SOLVER_GRIDBOUNDARY_H

#include <stdexcept>

struct GridBoundary {
private:
    int row_boundary; //row valid boundary : [0, row_boundary)
    int col_boundary; //col valid boundary : [0, col_boundary)
public:
    GridBoundary(int rowBoundary, int colBoundary);

    GridBoundary();

    int getRowBoundary() const;

    void setRowBoundary(int rowBoundary);

    int getColBoundary() const;

    void setColBoundary(int colBoundary);
};

#endif //WORD_SOLVER_GRIDBOUNDARY_H
