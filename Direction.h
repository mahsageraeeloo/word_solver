#ifndef WORD_SOLVER_DIRECTION_H
#define WORD_SOLVER_DIRECTION_H

#include <utility>
#include <vector>
#include <stdexcept>
#include "LocationPair.h"
#include "GridBoundary.h"

class Direction {
private:
    int row_change;
    int col_change;
public:
    enum DirectionEnum:int
    {
        NORTH,
        NORTH_EAST,
        EAST,
        SOUTH_EAST,
        SOUTH,
        SOUTH_WEST,
        WEST,
        NORTH_WEST
    };

    explicit Direction(DirectionEnum direction);
    bool moveToDirection(LocationPair &locationPair, const GridBoundary &gridBoundary, const int &steps) const ;
    bool isValidMove(const LocationPair &locationPair, const GridBoundary &gridBoundary, const int &steps) const;
    //TODO rename func
    int getRowChange() const;
    int getColChange() const;
    static std::vector<Direction> getAllDirections();
};

#endif //WORD_SOLVER_DIRECTION_H
