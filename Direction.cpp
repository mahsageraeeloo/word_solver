#include "Direction.h"

Direction::Direction(Direction::DirectionEnum direction) {
    /* Only following 8 directions are supported by this class*/
    switch (direction) {
        case NORTH:
            this->row_change = -1;
            this->col_change = 0;
            break;
        case NORTH_EAST:
            this->row_change = -1;
            this->col_change = 1;
            break;
        case EAST:
            this->row_change = 0;
            this->col_change = 1;
            break;
        case SOUTH_EAST:
            this->row_change = 1;
            this->col_change = 1;
            break;
        case SOUTH:
            this->row_change = 1;
            this->col_change = 0;
            break;
        case SOUTH_WEST:
            this->row_change = 1;
            this->col_change = -1;
            break;
        case WEST:
            this->row_change = 0;
            this->col_change = -1;
            break;
        case NORTH_WEST:
            this->row_change = -1;
            this->col_change = -1;
            break;
        default:
            throw std::invalid_argument("Invalid direction."); //TODO revise
    }
}

int Direction::getRowChange() const {
    return row_change;
}

int Direction::getColChange() const {
    return col_change;
}

vector<Direction> Direction::getAllDirections() {
    /*TODO It needs improvement (avoid creating instant each time that this method is called)*/
    return {Direction(NORTH),
            Direction(NORTH_EAST),
            Direction(EAST),
            Direction(SOUTH_EAST),
            Direction(SOUTH),
            Direction(SOUTH_WEST),
            Direction(WEST),
            Direction(NORTH_WEST)};
}
/* Checks whether number of 'steps' moves in this direction can be taken by verifying:
 *      1. row_final_indx to be in [0,row_boundary)
 *      2. col_final_indx to be in [0,col_boundary)
 * */
bool Direction::isValidMove(const LocationPair &locationPair,
                            const GridBoundary &gridBoundary, const int &steps) const {
    int row_final_indx = locationPair.getRowIndx() + (steps * this->row_change);
    int col_final_indx = locationPair.getColIndx() + (steps * this->col_change);
    return !(row_final_indx < 0 || row_final_indx >= gridBoundary.getRowBoundary()
             || col_final_indx < 0 || col_final_indx >= gridBoundary.getColBoundary());
}
/* validates and will take number of 'steps' move(s) in this direction */
bool Direction::moveToDirection(LocationPair &locationPair, const GridBoundary &gridBoundary, const int &steps) const {
    if (!isValidMove(locationPair, gridBoundary, steps)) {
        return false;
    }
    int row_final_indx = locationPair.getRowIndx() + (steps * this->row_change);
    int col_final_indx = locationPair.getColIndx() + (steps * this->col_change);
    locationPair.setRowIndx(row_final_indx);
    locationPair.setColIndx(col_final_indx);
    return true;
}

